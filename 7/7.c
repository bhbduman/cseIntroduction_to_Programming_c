#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef enum block_type{
	start, property, tax, punish
}block_type;
typedef enum player_type{
	 noone, cap, car
}player_type;
struct player{
	player_type type; 
	int current_block_id; 
	int owned_block_ids[11]; 
	int account; 
	int turn_to_wait; 
	char * name; 
}player;
struct block{
	int block_id;
	char * name ;
	int price;
	int rent;
	int rent_1; 
	int rent_2;
	int rent_3; 
	int house_price; 
	int house_count;
	struct player owner;
	block_type type;
}block;
void init_the_board(struct block board[20]);
void show_board(struct block board[20], struct player player_one,struct player player_two);
void show_properties(struct block board[20]);
void buy_property(struct block* current_block, struct player* current_player);
void sell_property(struct block board[20], struct player* current_player);
void game_play(struct block board[20], struct player player_one, struct player player_two);
void show_my_properties(struct block board[20],struct player current_player);
int roll_dice();
void buy_house(struct block* current_block, struct player* current_player);
int main()
{	
	struct block board[20];
	struct player player_one;
	struct player player_two;
	player_one.type=cap;
	player_one.current_block_id=0;
	player_one.owned_block_ids[11];
	player_one.account=100000;
	player_one.turn_to_wait=0;	
	player_one.name="Cap";
	player_two.type=car;
	player_two.current_block_id=0;
	player_two.owned_block_ids[11];
	player_two.account=100000;
	player_two.turn_to_wait=0;
	player_two.name="Car";
	
	srand(time(NULL));
	init_the_board(board);
	show_board(board,player_one,player_two);	
	game_play(board,player_one,player_two);
	return 0;
}
/**********************************************PART-1******************************************************/
void init_the_board(struct block board[20]){
	struct player player_one;
	board[0].block_id=0;
	board[0].name="Start";
	board[0].price=0;
	board[0].rent=0;
	board[0].rent_1=0;
	board[0].rent_2=0;
	board[0].rent_3=0;
	board[0].house_price=0;
	board[0].house_count=0;
	board[0].owner.type=noone;
	board[0].type=start;
		board[1].block_id=1;
	board[1].name="Esenyurt";
	board[1].price=16000;
	board[1].rent=800;
	board[1].rent_1=4000;
	board[1].rent_2=9000;
	board[1].rent_3=25000;
	board[1].house_price=10000;
	board[1].house_count=0;
	board[1].owner.type=noone;
	board[1].type=property;
		board[2].block_id=2;
	board[2].name="Car Park";
	board[2].price=0;
	board[2].rent=1500;
	board[2].rent_1=0;
	board[2].rent_2=0;
	board[2].rent_3=0;
	board[2].house_price=0;
	board[2].house_count=0;
	board[2].owner.type=noone;
	board[2].type=tax;
		board[3].block_id=3;
	board[3].name="Tuzla";
	board[3].price=16500;
	board[3].rent=850;
	board[3].rent_1=4250;
	board[3].rent_2=9500;
	board[3].rent_3=26000;
	board[3].house_price=12000;
	board[3].house_count=0;
	board[3].owner.type=noone;
	board[3].type=property;
		board[4].block_id=4;
	board[4].name="Arnavutkoy";
	board[4].price=17000;
	board[4].rent=875;
	board[4].rent_1=4500;
	board[4].rent_2=10000;
	board[4].rent_3=28000;
	board[4].house_price=12000;
	board[4].house_count=0;
	board[4].owner.type=noone;
	board[4].type=property;
		board[5].block_id=5;
	board[5].name="Wait 2 Turn";
	board[5].price=0;
	board[5].rent=2;
	board[5].rent_1=0;
	board[5].rent_2=0;
	board[5].rent_3=0;
	board[5].house_price=0;
	board[5].house_count=0;
	board[5].owner.type=noone;
	board[5].type=punish;
		board[6].block_id=6;
	board[6].name="Catalca";
	board[6].price=20000;
	board[6].rent=1000;
	board[6].rent_1=5000;
	board[6].rent_2=12000;
	board[6].rent_3=30000;
	board[6].house_price=13000;
	board[6].house_count=0;
	board[6].owner.type=noone;
	board[6].type=property;
		board[7].block_id=7;
	board[7].name="Beykoz";
	board[7].price=23000;
	board[7].rent=1100;
	board[7].rent_1=5500;
	board[7].rent_2=12500;
	board[7].rent_3=33000;
	board[7].house_price=13000;
	board[7].house_count=0;
	board[7].owner.type=noone;
	board[7].type=property;
		board[8].block_id=8;
	board[8].name="Car Fix";
	board[8].price=0;
	board[8].rent=1750;
	board[8].rent_1=0;
	board[8].rent_2=0;
	board[8].rent_3=0;
	board[8].house_price=0;
	board[8].house_count=0;
	board[8].owner.type=noone;
	board[8].type=tax;
		board[9].block_id=9;
	board[9].name="Maltepe";
	board[9].price=30000;
	board[9].rent=1350;
	board[9].rent_1=7000;
	board[9].rent_2=15000;
	board[9].rent_3=40000;
	board[9].house_price=15000;
	board[9].house_count=0;
	board[9].owner.type=noone;
	board[9].type=property;
		board[10].block_id=10;
	board[10].name="Bills";
	board[10].price=0;
	board[10].rent=2000;
	board[10].rent_1=0;
	board[10].rent_2=0;
	board[10].rent_3=0;
	board[10].house_price=0;
	board[10].house_count=0;
	board[10].owner.type=noone;
	board[10].type=tax;
		board[11].block_id=11;
	board[11].name="Sisli";
	board[11].price=33000;
	board[11].rent=1500;
	board[11].rent_1=8000;
	board[11].rent_2=16000;
	board[11].rent_3=42000;
	board[11].house_price=16000;
	board[11].house_count=0;
	board[11].owner.type=noone;
	board[11].type=property;
		board[12].block_id=12;
	board[12].name="Oil";
	board[12].price=0;
	board[12].rent=2250;
	board[12].rent_1=0;
	board[12].rent_2=0;
	board[12].rent_3=0;
	board[12].house_price=0;
	board[12].house_count=0;
	board[12].owner.type=noone;
	board[12].type=tax;
		board[13].block_id=13;
	board[13].name="Atasehir";
	board[13].price=35000;
	board[13].rent=1600;
	board[13].rent_1=8500;
	board[13].rent_2=17000;
	board[13].rent_3=45000;
	board[13].house_price=17000;
	board[13].house_count=0;
	board[13].owner.type=noone;
	board[13].type=property;
		board[14].block_id=14;
	board[14].name="Sariyer";
	board[14].price=40000;
	board[14].rent=1750;
	board[14].rent_1=9500;
	board[14].rent_2=19000;
	board[14].rent_3=48000;
	board[14].house_price=19000;
	board[14].house_count=0;
	board[14].owner.type=noone;
	board[14].type=property;
		board[15].block_id=15;
	board[15].name="Wait 1 Turn";
	board[15].price=0;
	board[15].rent=1;
	board[15].rent_1=0;
	board[15].rent_2=0;
	board[15].rent_3=0;
	board[15].house_price=0;
	board[15].house_count=0;
	board[15].owner.type=noone;
	board[15].type=punish;
		board[16].block_id=16;
	board[16].name="Kadikoy";
	board[16].price=43000;
	board[16].rent=1900;
	board[16].rent_1=11000;
	board[16].rent_2=21500;
	board[16].rent_3=55000;
	board[16].house_price=23000;
	board[16].house_count=0;
	board[16].owner.type=noone;
	board[16].type=property;
		board[17].block_id=17;
	board[17].name="Besiktas";
	board[17].price=60000;
	board[17].rent=2500;
	board[17].rent_1=15000;
	board[17].rent_2=28000;
	board[17].rent_3=60000;
	board[17].house_price=30000;
	board[17].house_count=0;
	board[17].owner.type=noone;
	board[17].type=property;
		board[18].block_id=18;
	board[18].name="Vacation";
	board[18].price=0;
	board[18].rent=5000;
	board[18].rent_1=0;
	board[18].rent_2=0;
	board[18].rent_3=0; 
	board[18].house_price=0;
	board[18].house_count=0;
	board[18].owner.type=noone;
	board[18].type=tax;
		board[19].block_id=19;
	board[19].name="Bebek";
	board[19].price=70000;
	board[19].rent=3500;
	board[19].rent_1=20000;
	board[19].rent_2=35500;
	board[19].rent_3=65000;
	board[19].house_price=35000;
	board[19].house_count=0;
	board[19].owner.type=noone;
	board[19].type=property;
}
/**********************************************PART-2******************************************************/
void show_board(struct block board[20], struct player player_one,struct player player_two){
	/*THE first part for upper blocks*/
	int i=0,j=0;
	printf("--------------------------------------------------------------------");
	printf("-----------------------------------------------------------------------------------\n");
		printf("|");
	for (i = 0; i < 6; ++i)
	{
		printf("%12s            |",board[i].name);
		
	}
	printf("\n");
		printf("|");
	for (i = 0; i < 6; ++i)
	{
		if (board[i].price!=0 && (board[i].type!=punish ))
			printf("%12d$           |",board[i].price);
		else if(board[i].rent!=0 && (board[i].type!=punish) )
			printf("%12d$           |",board[i].rent);
		else	
			printf("%12c            |",' ');
		
	}
	printf("\n");
	printf("|");
	for (i = 0; i < 6; ++i)
	{	
		if(player_two.current_block_id==board[i].block_id && player_one.current_block_id==board[i].block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
		else if(player_one.current_block_id==board[i].block_id)
			printf("%12s            |",player_one.name);
		else if(player_two.current_block_id==board[i].block_id)
			printf("%12s            |",player_two.name);
		else
			printf("%12c            |",' ');

		
	}
	printf("\n");
/*for the middle blocks ı increases right blocks when decreases left blocks */
	printf("--------------------------------------------------------------------");
	printf("-----------------------------------------------------------------------------------\n");
	int l=6;
	for (j = 19; j > 15; --j)
	{	
		printf("|");
		printf("%12s            |",board[j].name);
		for (i = 0; i < 4; ++i)
		{
			printf("%12c             ",' ' );
		}
		printf("\b");
		printf("|");
		printf("%12s            |\n",board[l].name);
		printf("|");
			if (board[j].price!=0 && (board[j].type!=punish ))
				printf("%12d$           |",board[j].price);
			else if(board[j].rent!=0 && (board[j].type!=punish) )
				printf("%12d$           |",board[j].rent);
			else	
				printf("%12c            |",' ');
		for (i = 0; i < 4; ++i)
		{
			printf("%12c             ",' ' );
		}
		printf("\b");
		printf("|");
			if (board[l].price!=0 && (board[l].type!=punish ))
				printf("%12d$           |",board[l].price);
			else if(board[l].rent!=0 && (board[l].type!=punish) )
				printf("%12d$           |",board[l].rent);
			else	
				printf("%12c            |",' ');	
		printf("\n");

		printf("|");
			if(player_two.current_block_id==board[j].block_id && player_one.current_block_id==board[j].block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
			else if(player_one.current_block_id==board[j].block_id)
				printf("%12s            |",player_one.name);
			else if(player_two.current_block_id==board[j].block_id)
				printf("%12s            |",player_two.name);
			else
				printf("%12c            |",' ');
		for (i = 0; i < 4; ++i)
		{
			printf("%12c             ",' ' );
		}
		printf("\b");
		
		printf("|");
		if(player_two.current_block_id==board[l].block_id && player_one.current_block_id==board[l].block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
		else  if(player_one.current_block_id==board[l].block_id)
			printf("%12s            |",player_one.name);
		else if(player_two.current_block_id==board[l].block_id)
			printf("%12s            |",player_two.name);
		else
			printf("%12c            |",' ');
		for (i = 0; i < 5; ++i)
		{
			printf("%12c             ",' ' );
		}
		/*printf("\x1b[1A");*//*bu satır board ı çizdirirken fazladan bir satır aşağı kaydırıyor onu düzeltmek için internetten bulduğum bir statement ancak her compilerde doğru çalışmadığı için yorum satırına aldım*/
		if(j!=16){
			printf("\n--------------------------");
			for (i = 0; i < 4; ++i)
			{
				printf("%12c             ",' ' );
			}
		printf("\b");
			printf("--------------------------\n");
		}
		l++;

	}
	/*downward blocks its like upper blocks*/
	printf("\n--------------------------------------------------------------------");
		printf("-----------------------------------------------------------------------------------\n");
		printf("|");
	for (i = 15; i > 9; --i)
	{
		printf("%12s            |",board[i].name);
		
	}
	printf("\n");
		printf("|");
	for (i = 15; i > 9; --i)
	{
		if (board[i].price!=0 && (board[i].type!=punish ))
			printf("%12d$           |",board[i].price);
		else if(board[i].rent!=0 && (board[i].type!=punish) )
			printf("%12d$           |",board[i].rent);
		else	
			printf("%12c            |",' ');
		
	}
	printf("\n");
	printf("|");
	for (i = 15; i > 9; --i)
	{	
		if(player_two.current_block_id==board[i].block_id && player_one.current_block_id==board[i].block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
		else  if(player_one.current_block_id==board[i].block_id)
			printf("%12s            |",player_one.name);
		else if(player_two.current_block_id==board[i].block_id)
			printf("%12s            |",player_two.name);
		else
			printf("%12c            |",' ');

		
	}
	printf("\n--------------------------------------------------------------------");
		printf("-----------------------------------------------------------------------------------\n");
	printf("\n");

}
/**********************************************PART-3******************************************************/
void show_properties(struct block board[20]){
	int i,choice=23;
	for (i = 0; i < 20; ++i)
		{
			if(board[i].type==property)
			printf("%d- %s\n",i,board[i].name);
		}
		printf("0- Exit\n");
		scanf("%d",&choice);
	while(choice!=0){
		for (i = 0; i < 20; ++i)
		{
			if(board[i].type==property)/*if the type is property it would shown in terminal*/
			printf("%d- %s\n",i,board[i].name);
		}
		printf("0- Exit\n");

		printf("----------------------------\n");
		printf("|    %12s          |\n",board[choice].name );
		printf("---------------------------\n");
		printf("|      Rent         %-6d$|\n",board[choice].rent );
		printf("|      Rent 1 H     %-6d$|\n",board[choice].rent_1 );
		printf("|      Rent 2 H     %-6d$|\n",board[choice].rent_2 );
		printf("|      Rent 3 H     %-6d$|\n",board[choice].rent_3 );
		printf("----------------------------\n");
		printf("|      House Price  %-6d$|\n",board[choice].house_price );
		printf("----------------------------\n");
		scanf("%d",&choice);
			if(choice==0)
				printf("Exitting...\n");/*to exit back to menu*/
	}	
}
/**********************************************PART-4******************************************************/
void buy_property(struct block* current_block, struct player* current_player){
	int flag=0;
	int choc=0,empty=0;
	int i;
	printf("current player account: %d\n",current_player->account );
	if(current_block->type==property){
			if(current_block->owner.type==current_player->type)
				flag=1;
		
		printf("%d\n",flag );
		if(flag==0 && current_player->account>=current_block->price){
			printf("do you want to buy block? (1/0)\n");/*I should check the user again cause of he/She can come again the same block and this time the block could be sold*/
			
			scanf("%d",&choc);
			
			switch(choc){
				case 1:
					current_player->account = current_player->account - current_block->price;
					//printf("current player account: %d\n",current_player->account );
					for (i = 0; i < 11 && empty==0; ++i)
					{
						if(current_player->owned_block_ids[i] ==0)
							empty=1;
					}
					current_player->owned_block_ids[i-1] = current_block->block_id;/*it assignes the first empty index in array*/
					current_block->owner.type=current_player->type;					
					break;
				case 0:
					current_player->account = current_player->account - current_block->rent;
					break;
				default:
					printf("'%d' is an invalid choice\n",choc);
					break;
			}	
		}	
		if(current_player->account>=current_block->house_price){	
				printf("do you wanna buy an house 1/0\n");/*as you told program asks for house if the user bought the property*/
			
			scanf("%d",&choc);
			
			if (choc==1 && current_block->house_count<4){
				current_player->account = current_player->account - current_block->house_price;
				current_block->house_count=current_block->house_count +1;				
				printf("%d\n",current_block->house_count );
			}
			
			else if (current_block->house_count>3)/*the statement to check user dont buy more than three house*/
				
				printf("You bought all houses in this block\n");
			
			else
				printf("'%c' is an invalid choice\n",choc);

		}
	}  
}
/**********************************************PART-5******************************************************/
void sell_property(struct block board[20], struct player* current_player){
	int choice=0;
	int flag=0;
	int i,j;
	for (i = 0; i < 11; ++i)
	{
		if (board[i].owner.type==current_player->type)
		{
			printf("\nThe Property:------------------------>%12s\n"
				   "Block id:---------------------------->%12d\n",board[i].name,i);
			printf("The property rent fee:--------------->%12d$\n",board[i].rent );
			printf("The houses you have:----------------->%12d\n",board[i].house_count );
			printf("The income from this property-------->%12d$\n",((board[i].price)/2)+((board[i].house_count*board[i].house_price)/2) );
		}
	}
	printf("What property that you want to sell Enter the block id, If you dont want to sel just enter '0'): ");
	scanf("%d",&choice);
	if (choice!=0)
	{
		current_player->account = current_player->account + ((board[choice].price)/2)+(board[choice].house_count*board[choice].house_price);
		for (j = 0; j < 11 && flag==0; ++j)
		{
			if(board[choice].block_id == current_player->owned_block_ids[j])
				flag=1;
		}
			current_player->owned_block_ids[j]=0;/*it make empty the user owned blocks arrays*/
			board[choice].house_count=0;/*also houses sell so it has tto be 0*/
			board[choice].owner.type=noone;/*and the owner type has to be again noone*/
		for ( j; j < 11 && j+1!=11 ; ++j)
		{
			current_player->owned_block_ids[j]=current_player->owned_block_ids[j+1];
		}
		/*Im not sure the shifting is necessary but I put that*/


	}
}
/**********************************************PART-6******************************************************/
void game_play(struct block board[20], struct player player_one, struct player player_two){
	struct player current_player=player_one;
	struct player old_player=player_two;
	int choice=0,dice=0,wannabuy;
	int i,over=0;
	int avaiable=0;
	while(current_player.account>=0 || over==0){
		if (current_player.type==player_one.type){
			current_player=player_two;
			old_player=player_one;
		}	
		else{/*Its to change each time after user roll the dice*/
			current_player=player_one;
			old_player=player_two;
		}


				avaiable=0;/*if avaiable =0 the block belong noone if 1 its belong opponent if it s 2 it belong current player */

				if (choice==1)
				{
					if (current_player.turn_to_wait!=0)
					{/*to arrange wait turn but there is a problem in my program even you are in wait to turn block then you have to roll the dice just he wont make an operationuntil pass the punish*/
						current_player.turn_to_wait = current_player.turn_to_wait-1;
						printf("%s have to wait %d more turn \n",current_player.name,current_player.turn_to_wait );
						
					}
					else{
			printf("current_player::::::::::%s\n",current_player.name );
						dice=roll_dice();
						printf("Dice is %d\n",dice );
							if (current_player.current_block_id+dice>19){/*Its going to add 10000 for eaach completing tour*/
								current_player.current_block_id = (current_player.current_block_id+dice)%19-1;
								current_player.account = current_player.account + 10000;
							}
							else
								current_player.current_block_id = current_player.current_block_id+dice;
						
						if (current_player.type==player_one.type)
							player_one=current_player;
						else
							player_two=current_player;
						
						show_board(board,player_one,player_two);
						for (i = 0; i < 11; ++i){
							if(old_player.owned_block_ids[i]==current_player.current_block_id)
								avaiable=1;
						}
						for (i = 0; i < 11; ++i){
							if(current_player.owned_block_ids[i]==current_player.current_block_id)
								avaiable=2;
						}
							
						if(board[current_player.current_block_id].type==property && avaiable==1){
							if (board[current_player.current_block_id].house_count==3){
								current_player.account = current_player.account - board[current_player.current_block_id].rent_3;
								old_player.account = old_player.account + board[current_player.current_block_id].rent_3;
							}
								/*to arrange how much the opponent going to pay according to number of houses*/
							else if(board[current_player.current_block_id].house_count==2){
								current_player.account = current_player.account - board[current_player.current_block_id].rent_2;
								old_player.account = old_player.account + board[current_player.current_block_id].rent_2;
							}

							else if(board[current_player.current_block_id].house_count==1){
								current_player.account = current_player.account - board[current_player.current_block_id].rent_1;
								old_player.account = old_player.account + board[current_player.current_block_id].rent_1;
							}

							else{	
								current_player.account = current_player.account - board[current_player.current_block_id].rent;
								old_player.account = old_player.account + board[current_player.current_block_id].rent;
							}				
						}
						else if(board[current_player.current_block_id].type==property && avaiable==2){
							current_player.account = current_player.account;
							buy_house(&board[current_player.current_block_id],&current_player);

						}

						else if(board[current_player.current_block_id].type==property && avaiable==0){/*first time if its empty program offer do you want to buy it*/
							printf("Do you Want to  buy %s or rent 1/0\n",board[current_player.current_block_id].name);
							scanf("%d",&wannabuy);
							if (wannabuy==1){
								buy_property(&board[current_player.current_block_id],&current_player);
							}
							else if (wannabuy==0){							
							current_player.account = current_player.account - board[current_player.current_block_id].rent;
							}
							else
								printf("invalid choice\n");

						}

						else if(board[current_player.current_block_id].type==tax)
							current_player.account = current_player.account - board[current_player.current_block_id].rent;
						
						else if(board[current_player.current_block_id].type==punish){
							current_player.turn_to_wait= board[current_player.current_block_id].rent;
							printf("You have to wait %d more hand\n",current_player.turn_to_wait);
						}
					}	
					if (current_player.type==player_one.type)
						player_one=current_player;
					else
						player_two=current_player;

					
				printf("current_player--------------------->%s\n",current_player.name );
				}
			printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
			printf("Please select an option to continue:\n");
				printf("Enter an option(Roll the dice to give your turn)\n");
					scanf("%d",&choice);

				while(choice!=1){
					/*following statements to make functions except roolling the dice cause of if it rolls the dice the turn is pass the your opponent*/
					printf("current_player--------------------->%s\n",current_player.name );
					if (choice==2 && dice!=0)
					{
						printf("/----------------------------/\nMoney in your account:%d\n/-----------------------------/\n",current_player.account);
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
						printf("Please select an option to continue:\n");

					}
					else if (choice==3 && dice!=0)
					{
						show_my_properties(board,current_player);
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
						printf("Please select an option to continue:\n");

					}
					else if (choice==4 && dice!=0)
					{
						show_properties(board);
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
						printf("Please select an option to continue:\n");

					}
					else if (choice==5 && dice!=0)
					{
						buy_property(&board[current_player.current_block_id],&current_player);
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
						printf("Please select an option to continue:\n");
			
					}
					else if (choice==6 && dice!=0)
					{
						buy_house(&board[current_player.current_block_id],&current_player);
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
						printf("Please select an option to continue:\n");

					}
					else if (choice==7 && dice!=0)
					{
						sell_property(board,&current_player);
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
						printf("Please select an option to continue:\n");
					}

					else{
						printf("This is an invalid choice\n");	
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
					printf("Please select an option to continue:\n");
					}
						scanf("%d",&choice);/*its necessary to if user make another operations*/
				}
				over=1;
							for (i = 0; i < 11; ++i)
							{
								if (current_player.owned_block_ids[i]!=0)
								{
									over=0;/*its to check user has a property or not otherwise if user has no money the game is over*/
								}
							}
						if (over==0 && current_player.account<=0)
						{
							printf("you have to sell something otherwise you are going to lose\n");
							sell_property(board,&current_player);
						}					

	}
	printf("winner is %s\n",old_player.name );

}
int roll_dice(){/*a random function for dice*/
	int result;
	result=rand()%6+1;
	return result;

}
void show_my_properties(struct block board[20],struct player current_player){
	int i;
	for (i = 0; i < 11; ++i)
	{
		if (board[i].owner.type==current_player.type)
		{
			printf("\n-------------------------------------------------\n");
			printf("\nThe Property:------------------------>%12s\n"
				   "Block id:---------------------------->%12d\n",board[i].name,i);
			printf("The property rent fee:--------------->%12d$\n",board[i].rent );
			printf("The houses you have:----------------->%12d\n",board[i].house_count );
			printf("The income from this property-------->%12d$\n",((board[i].price)/2)+(board[i].house_count*board[i].house_price)/2 );
		}
	}
			printf("\n-------------------------------------------------\n");
}
void buy_house(struct block* current_block, struct player* current_player){
	int flag=0,i=0;
	int avaiable=0;
	int choc=110;

		for (i = 0; i < 11; ++i)
		{
			if(current_player->owned_block_ids[i]==current_block->block_id)
				avaiable=1;/*to check is it belong to user*/
		}
		
		if(avaiable==1 ){
				if(current_block->owner.type==current_player->type)
					flag=1;/*tedbir amaclı tekrardan tipini kontrol ediyorum*/
		}
	
		if(flag==1 &&current_player->account>=current_block->house_price){	
				printf("do you wanna buy an house 1/0\n");
				scanf("%d",&choc);
				
				if (current_block->house_count!=3 && choc==1){
					current_player->account = current_player->account - current_block->house_price;
					current_block->house_count = current_block->house_count +1;				
					printf("%d\n",current_block->house_count );
				}
				else
					printf("You bought all houses in this block\n");

			}
		
		else
			printf("'%c' is an invalid choice\n",choc);
}
