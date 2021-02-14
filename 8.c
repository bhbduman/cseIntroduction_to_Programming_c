#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PROPERTY_COUNT 12
enum block_type{start, property, tax, punish,fortune};
enum player_type{noone, cap, car };
enum fortune_type{free_house=1, time_travel=2, garnishment=3, generosity=4, treasure_hunter=5};

struct player{
	enum player_type type; 
	int current_block_id; 
	int owned_block_ids[12]; 
	int account; 
	int turn_to_wait; 
	char * name; 
};

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
	enum block_type type;
	struct block* next;
	struct block* prev;
};

struct fortune_card{
	enum fortune_type type;
	char* name;
	int reward_punish;
	struct fortune_card* next;

};

void init_the_board(struct block **board);
void init_the_fcards(struct fortune_card **card);
void addNewC(struct fortune_card **card,enum fortune_type type,char* name,int reward_punish);
void show_board(struct block *board, struct player player_one,struct player player_two);
void addNew(struct block **board,int id,char* name,int price,int rent,int rent_1,int rent_2,int rent_3,int house_price,int house_count,enum block_type type);
void game_play(struct block *board, struct player player_one, struct player player_two);
void show_my_properties(struct block* board,struct player current_player);
void buy_house(struct block** current_block,struct player* current_player);

void sell_property(struct block *board, struct player* current_player);

int draw_fcard();

void buy_property(struct block** current_block, struct player* current_player);

int check_end(struct player current_player);
void show_property_deed(struct block* board);
int roll_dice();

void show_properties(struct block *board);
void AI(struct player* current_player,struct block *board,struct player* old_player);

int main(){
	struct block* board;
	struct block* boardTemp;
	
	struct player player_one = {cap,0,{-1},100000,0,"Cap"};
	struct player player_two = {car,0,{-1},100000,0,"Car"};

	srand(time(NULL));

	board =(struct block *)malloc(sizeof(struct block));

	init_the_board(&board);
	board=board->next;
	
	show_board(board,player_one,player_two);
	game_play(board,player_one,player_two);
}
void init_the_board(struct block **board){

	struct block *head=(struct block*)malloc(sizeof(struct block));
	head=*board;
	addNew(board,0,"Start",				0,0,0,0,0,0,0,start);
	addNew(board,1,"Esenyurt",			16000,800,4000,9000,25000,10000,0,property);
	addNew(board,2,"Car Park",			0,1500,0,0,0,0,0,tax);
	addNew(board,3,"Fortune Card",		0,0,0,0,0,0,0,fortune);
	addNew(board,4,"Tuzla",				16500,850,4250,9500,26000,12000,0,property);
	addNew(board,5,"Arnavutkoy",		17000,875,4500,10000,28000,12000,0,property);
	addNew(board,6,"Wait 2 Turn",		0,2,0,0,0,0,0,punish);
	addNew(board,7,"Catalca",			20000,1000,5000,12000,30000,13000,0,property);
	addNew(board,8,"Beykoz",			23000,1100,5500,12500,33000,13000,0,property);
	addNew(board,9,"Fortune Card",		0,0,0,0,0,0,0,fortune);
	addNew(board,10,"Car Fix",			0,1750,0,0,0,0,0,tax);
	addNew(board,11,"Maltepe",			30000,1350,7000,15000,40000,15000,0,property);
	addNew(board,12,"Bills",			0,2000,0,0,0,0,0,tax);
	addNew(board,13,"Sisli",			33000,1500,8000,16000,42000,16000,0,property);
	addNew(board,14,"Oil",				0,2250,0,0,0,0,0,tax);
	addNew(board,15,"Fortune Card",		0,0,0,0,0,0,0,fortune);
	addNew(board,16,"Atasehir",			35000,1600,8500,17000,45000,17000,0,property);
	addNew(board,17,"Sariyer",			40000,1750,9500,19000,48000,19000,0,property);
	addNew(board,18,"Wait 1 Turn",		0,1,0,0,0,0,0,punish);
	addNew(board,19,"Kadikoy",			43000,1900,11000,21500,55000,23000,0,property);
	addNew(board,20,"Besiktas",			60000,2500,15000,28000,60000,30000,0,property);
	addNew(board,21,"Fortune Card",		0,0,0,0,0,0,0,fortune);
	addNew(board,22,"Vocation",			0,5000,0,0,0,0,0,tax);
	addNew(board,23,"Bebek",			70000,3500,20000,35500,65000,35000,0,property);
	(*board)->next=head;
	head->prev=(*board);
}
void addNew(struct block **iter,int id,char* name,int price,int rent,int rent_1,int rent_2,int rent_3,int house_price,int house_count,enum block_type type)
{
		

		(*iter)->block_id = id; 
		(*iter)->name = name; 
		(*iter)->price =price; 
		(*iter)->rent =rent; 
		(*iter)->rent_1 =rent_1; 
		(*iter)->rent_2 =rent_2; 
		(*iter)->rent_3 =rent_3; 
		(*iter)->house_price =house_price; 
		(*iter)->house_count =house_count; 
		(*iter)->owner.type=noone; 
		(*iter)->type=type;
			if(id!=23)
			{
				(*iter)->next=(struct block*)malloc(sizeof(struct block));
				(*iter)->next->prev=(*iter);
				(*iter) =(*iter)->next;
			}

}
void init_the_fcards(struct fortune_card **card){
	struct block *headC;
	headC=(struct fortune_card *)malloc(sizeof(struct fortune_card));
	headC=(*card);
	addNewC(card,free_house,"Free House",				1);
	addNewC(card,time_travel,"Time Travel",			2);
	addNewC(card,garnishment,"Garnishment",			5000);
	addNewC(card,generosity,"Generosity",				10000);
	addNewC(card,treasure_hunter,"Treasure Hunter",	20000);
	((*card)->next)=headC;
	printf("here: %s",(*card)->name);
}
void addNewC(struct fortune_card **card,enum fortune_type type,char* name,int reward_punish){
	(*card)->type=type;
	(*card)->name=name;
	(*card)->reward_punish=reward_punish;
	
	if(type!=treasure_hunter){
		(*card)->next=(struct fortune_card*)malloc(sizeof(struct fortune_card));
		(*card)=(*card)->next;
	}


}
void show_board(struct block *board, struct player player_one,struct player player_two){
		
		
	
	int i=0,j=0,space_flag=0;
	
	struct block* boardTemp1=(struct block*)malloc(sizeof(struct block));
	struct block* boardTemp2=(struct block*)malloc(sizeof(struct block));
	struct block* boardTemp6=(struct block*)malloc(sizeof(struct block));
	boardTemp1=board;
	boardTemp2=board;
	boardTemp6=board;

 	boardTemp2=boardTemp2;  
 	boardTemp6=boardTemp6->prev; 
 
	
	/*THE first part for upper blocks*/
	
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|");
	for (i = 0; i < 7; ++i)
	{
		printf("%12s            |",boardTemp1->name);
	
		boardTemp1=boardTemp1->next;	
	}
	boardTemp1=board;
	printf("\n");
		printf("|");
	for (i = 0; i < 7; ++i)
	{
		if (boardTemp1->price!=0 && (boardTemp1->type!=punish ))
			printf("%12d$           |",boardTemp1->price);
		else if(boardTemp1->rent!=0 && (boardTemp1->type!=punish) )
			printf("%12d$           |",boardTemp1->rent);
		else	
			printf("%12c            |",' ');
		boardTemp1=boardTemp1->next;
	}
	boardTemp1=board;
	printf("\n");
	printf("|");
	for (i = 0; i < 7; ++i)
	{	
		if(player_two.current_block_id== boardTemp1->block_id && player_one.current_block_id==boardTemp1->block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
		else if(player_one.current_block_id== boardTemp1->block_id)
			printf("%12s            |",player_one.name);
		else if(player_two.current_block_id==boardTemp1->block_id)
			printf("%12s            |",player_two.name);
		else
			printf("%12c            |",' ');	
		
		boardTemp1=boardTemp1->next;
	}
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	int l=7;
	for (j = 23; j > 18; --j)
	{	
		printf("|");
		printf("%12s            |",boardTemp6->name);
		for (i = 0; i < 5; ++i)
		{
			printf("%12c             ",' ' );
		}
		printf("\b");
		printf("|");
		printf("%12s            |\n",boardTemp1->name);
		printf("|");
			if (boardTemp6->price!=0 && (boardTemp6->type!=punish ))
				printf("%12d$           |",boardTemp6->price);
			else if(boardTemp6->rent!=0 && (boardTemp6->type!=punish) )
				printf("%12d$           |",boardTemp6->rent);
			else	
				printf("%12c            |",' ');
		for (i = 0; i < 5; ++i)
		{
			printf("%12c             ",' ' );
		}
		printf("\b");
		printf("|");
			if (boardTemp1->price!=0 && (boardTemp1->type!=punish ))
				printf("%12d$           |",boardTemp1->price);
			else if(boardTemp1->rent!=0 && (boardTemp1->type!=punish) )
				printf("%12d$           |",boardTemp1->rent);
			else	
				printf("%12c            |",' ');	
		printf("\n");

		printf("|");
			if(player_two.current_block_id==boardTemp6->block_id && player_one.current_block_id==boardTemp6->block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
			else if(player_one.current_block_id==boardTemp6->block_id)
				printf("%12s            |",player_one.name);
			else if(player_two.current_block_id==boardTemp6->block_id)
				printf("%12s            |",player_two.name);
			else
				printf("%12c            |",' ');
		for (i = 0; i < 5; ++i)
		{
			printf("%12c             ",' ' );
		}
		printf("\b");
		
		printf("|");
		if(player_two.current_block_id==boardTemp1->block_id && player_one.current_block_id==boardTemp1->block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
		else  if(player_one.current_block_id==boardTemp1->block_id)
			printf("%12s            |",player_one.name);
		else if(player_two.current_block_id==boardTemp1->block_id)
			printf("%12s            |",player_two.name);
		else
			printf("%12c            |",' ');
		for (i = 0; i < 6; ++i)
		{
			printf("%12c             ",' ' );
		}
		//printf("\x1b[1A");/*bu satır board ı çizdirirken fazladan bir satır aşağı kaydırıyor onu düzeltmek için internetten bulduğum bir statement ancak her compilerde doğru çalışmadığı için yorum satırına aldım*/
		if(j!=19){
			printf("\n--------------------------");
			for (i = 0; i < 5; ++i)
			{
				printf("%12c             ",' ' );
			}
		printf("\b");
			printf("--------------------------\n");
		}
		l++;
		boardTemp6=boardTemp6->prev;
		boardTemp1=boardTemp1->next;
	}
	boardTemp2=boardTemp6;
		printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		
		printf("|");
	for (i = 16; i > 9; --i)
	{
		printf("%12s            |",boardTemp6->name);
		
		boardTemp6=boardTemp6->prev;
	}
	boardTemp6=boardTemp2;
	printf("\n");
		printf("|");
	for (i = 16; i > 9; --i)
	{
		if (boardTemp6->price!=0 && (boardTemp6->type!=punish ))
			printf("%12d$           |",boardTemp6->price);
		else if(boardTemp6->rent!=0 && (boardTemp6->type!=punish) )
			printf("%12d$           |",boardTemp6->rent);
		else	
			printf("%12c            |",' ');
		
		boardTemp6=boardTemp6->prev;
	}
	boardTemp6=boardTemp2;
	printf("\n");
	printf("|");
	for (i = 16; i > 9; --i)
	{	
		if(player_two.current_block_id==boardTemp6->block_id && player_one.current_block_id==boardTemp6->block_id)
			printf("%10s-%s          |",player_one.name,player_two.name);
		else  if(player_one.current_block_id==boardTemp6->block_id)
			printf("%12s            |",player_one.name);
		else if(player_two.current_block_id==boardTemp6->block_id)
			printf("%12s            |",player_two.name);
		else
			printf("%12c            |",' ');

		boardTemp6=boardTemp6->prev;
		
	}

	printf("\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	printf("\n");
	
}
void game_play(struct block* board, struct player player_one, struct player player_two){
	struct player current_player=player_one;
	struct player old_player=player_two;
	int choice=0,dice=0,wannabuy,block_id=0;
	int i,over=0,dice_for_card=0;
	int avaiable=0;
	int fcard=0;
	int check=0;
	struct fortune_card * card =(struct fortune_card *)malloc(sizeof(struct fortune_card));
	struct fortune_card * cardTemp =(struct fortune_card *)malloc(sizeof(struct fortune_card));
	struct block * board_one =(struct block *)malloc(sizeof(struct block));
	struct block * board_two =(struct block *)malloc(sizeof(struct block));
	struct block * boardTemp =(struct block *)malloc(sizeof(struct block));
	struct block * boardTemp1 =(struct block *)malloc(sizeof(struct block));
	cardTemp=card;
	board_one=board;
	board_two=board;
	boardTemp=board;
	boardTemp1=board;
	
	init_the_fcards(&card);

	while(1){
						boardTemp=board;
			printf("current_player block id %d\n",current_player.current_block_id );
				
			printf(	"1 - Roll the dice"
					"\n2 - Show my account"
					"\n3 - Show my properties"
					"\n4 - Show property deeds"
					"\n5 - Buy property"
					"\n6 - Buy house"
					"\n7 - Sell property");
			printf("\nPlease select an option to continue:\n");
			printf("Enter an option(Roll the dice to give your turn)\n");
					scanf("%d",&choice);
		if (current_player.type==player_one.type){
			current_player=player_two;
			old_player=player_one;
		}	
		else{/*Its to change each time after user roll the dice*/
			current_player=player_one;
			old_player=player_two;
		}

		if (current_player.type==cap){
			AI(&current_player,boardTemp,&old_player);
		}
		else{
			printf("current_player--------------------->%s\n",current_player.name );
				avaiable=0;/*if avaiable =0 the block belong noone if 1 its belong opponent if it s 2 it belong current player */
				for (i = 0; i < 11; ++i){
					if(old_player.owned_block_ids[i]==current_player.current_block_id)
						avaiable=1;
				}
				for (i = 0; i < 11; ++i){
					if(current_player.owned_block_ids[i]==current_player.current_block_id)
						avaiable=2;
				}
				if (choice==1)
				{
					dice=roll_dice();
					for (int i = 0; i < dice; ++i)
					{
						boardTemp=boardTemp->next;
					}
					check=(current_player.current_block_id + boardTemp->block_id);
					if (check>23){
						current_player.current_block_id =(current_player.current_block_id + dice)%24;
						check=check%24;
						current_player.account=current_player.account+10000;

					}
					else
						current_player.current_block_id =(current_player.current_block_id + dice);
				
				}
				
				boardTemp=boardTemp;


				if(boardTemp->type==property && avaiable==1){
							if (boardTemp->house_count==3){
								current_player.account = current_player.account - boardTemp->rent_3;
								old_player.account = old_player.account + boardTemp->rent_3;
							}
								/*to arrange how much the opponent going to pay according to number of houses*/
							else if(boardTemp->house_count==2){
								current_player.account = current_player.account - boardTemp->rent_2;
								old_player.account = old_player.account + boardTemp->rent_2;
							}

							else if(boardTemp->house_count==1){
								current_player.account = current_player.account - boardTemp->rent_1;
								old_player.account = old_player.account + boardTemp->rent_1;
							}

							else{	
								current_player.account = current_player.account - boardTemp->rent;
								old_player.account = old_player.account + boardTemp->rent;
							}				
						}
						else if(boardTemp->type==property && avaiable==2){
							current_player.account = current_player.account;
							buy_house(&boardTemp,&current_player);

						}

						else if(boardTemp->type==property && avaiable==0){/*first time if its empty program offer do you want to buy it*/
							printf("Do you Want to  buy %s or rent 1/0\n",boardTemp->name);
							scanf("%d",&wannabuy);
							if (wannabuy==1){
							buy_property(&boardTemp,&current_player);
							}
							else if (wannabuy==0){							
							current_player.account = current_player.account - boardTemp->rent;
							}
							else
								printf("invalid choice\n");

						}

						else if(boardTemp->type==tax)
							current_player.account = current_player.account - boardTemp->rent;
						
						else if(boardTemp->type==punish){
							current_player.turn_to_wait= boardTemp->rent;
							printf("You have to wait %d more hand\n",current_player.turn_to_wait);
						}
						else if(boardTemp->type==fortune){
							fcard = draw_fcard();
							for (int i = 0; i < 5; ++i)
							{
								printf("%s\n",cardTemp->name );
								cardTemp=cardTemp->next;
							}
							
							for (int i = 0; i < fcard; ++i)
							{
								cardTemp=cardTemp->next;
							}
								printf("You drew %s Card\n",cardTemp->name );
							if (fcard==free_house)
							{
								printf("WHere do you want to build a house?Enter the block id:\n--------------------------------------------------");
								for (i = 0; i < 24; ++i)
								{
									if (boardTemp1->owner.type==current_player.type)
									{
										printf("\nThe Property:------------------------>%12s\n"
											   "Block id:---------------------------->%12d\n",boardTemp1->name,boardTemp1->block_id);
										printf("The property rent fee:--------------->%12d$\n",boardTemp1->rent );
										printf("The houses you have:----------------->%12d\n",boardTemp1->house_count );
										printf("The income from this property-------->%12d$\n",((boardTemp1->price)/2)+((boardTemp1->house_count * boardTemp1->house_price)/2) );
									}
									boardTemp1=boardTemp1->next;
								}
								printf("--------------------------------------------------\n");
								scanf("%d",&block_id);
								for (int i = 0; i < block_id; ++i)
								{
									board_two=board_two->next;
								}
								board_two->house_count =board_two->house_count+1;



							}
							else if(fcard==time_travel)
							{
								dice_for_card=roll_dice();
								if (dice_for_card>=1 && dice_for_card<=3)
								{
									for (int i = 0; i < 2; ++i)
									{
										boardTemp=boardTemp->next;
									}
									current_player.current_block_id =(current_player.current_block_id + boardTemp->block_id);
								}
								else{
									for (int i = 0; i < 2; ++i)
									{
										boardTemp=boardTemp->prev;
									}
									current_player.current_block_id =(current_player.current_block_id + boardTemp->block_id);

								}

							}
							else if (fcard==garnishment)
							{
								current_player.account = current_player.account - 5000;
							}
							else if (fcard==generosity)
							{
								current_player.account = current_player.account - 10000;
								old_player.account = old_player.account + 10000;

							}
							else if (fcard==treasure_hunter)
							{
								current_player.account = current_player.account + 20000;
							}
							else
								printf("The card didn't draw\n");

							cardTemp=card;
						}
						else
							printf("Its not valid\n");


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
						buy_property(&boardTemp,&current_player);
						printf("1 - Roll the dice\n2 - Show my account\n3 - Show my properties\n4 - Show property deeds\n5 - Buy property\n6 - Buy house\n7 - Sell property\n");
						printf("Please select an option to continue:\n");
			
					}
					else if (choice==6 && dice!=0)
					{
						buy_house(&boardTemp,&current_player);
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
						
					if (current_player.type==player_one.type){
						player_one=current_player;
						player_two=old_player;
					}

					else{
						player_two=current_player;
						player_one=old_player;			
					}

				}
					show_board(board,player_one,player_two);
									
	}

}					

	
int draw_fcard(){
	int i=0;
	i=(rand()%5)+1;
	return i;
}		
int roll_dice(){/*a random function for dice*/
	int result;
	result=rand()%6+1;
	return result;

}

void show_my_properties(struct block* board,struct player current_player){
	int i;
	for (i = 0; i < 24; ++i)
	{
		if (board->owner.type==current_player.type)
		{
			printf("\n-------------------------------------------------\n");
			printf("\nThe Property:------------------------>%12s\n"
				   "Block id:---------------------------->%12d\n",board->name,board->block_id);
			printf("The property rent fee:--------------->%12d$\n",board->rent );
			printf("The houses you have:----------------->%12d\n",board->house_count );
			printf("The income from this property-------->%12d$\n",((board->price)/2)+(board->house_count*board->house_price)/2 );
		}
		board=board->next;
	}
			printf("\n-------------------------------------------------\n");
}
void buy_house(struct block** current_block, struct player* current_player){
	int flag=0,i=0;
	int avaiable=0;
	int choc=110;

		for (i = 0; i < 11; ++i)
		{
			if(current_player->owned_block_ids[i]==(*current_block)->block_id)
				avaiable=1;/*to check is it belong to user*/
		}
		
		if(avaiable==1 ){
				if((*current_block)->owner.type==current_player->type)
					flag=1;/*tedbir amaclı tekrardan tipini kontrol ediyorum*/
		}
	
		if(flag==1 &&current_player->account>=(*current_block)->house_price){	
				printf("do you wanna buy an house 1/0\n");
				scanf("%d",&choc);
				
				if ((*current_block)->house_count!=3 && choc==1){
					current_player->account = current_player->account - (*current_block)->house_price;
					(*current_block)->house_count = (*current_block)->house_count +1;				
					printf("%d\n",(*current_block)->house_count );
				}
				else
					printf("You bought all houses in this block\n");

			}
		
		else
			printf("'%c' is an invalid choice\n",choc);
}
void show_properties(struct block *board){
	int i,choice=23;
	struct block *boardTemp=(struct block *)malloc(sizeof(struct block));
	boardTemp=board;
	for (i = 0; i < 20; ++i)
		{
			if(boardTemp->type==property)
			printf("%d- %s\n",boardTemp->block_id,boardTemp->name);
			boardTemp =boardTemp->next;
		}
		printf("0- Exit\n");
		scanf("%d",&choice);
	while(choice!=0){
		for (i = 0; i < 24; ++i)
		{
			if(boardTemp->type==property){/*if the type is property it would shown in terminal*/
			printf("%d- %s\n",boardTemp->block_id,boardTemp->name);
			boardTemp=boardTemp->next;
		}
		}
		printf("0- Exit\n");
		for (int i = 0; i < choice; ++i)
		{
			boardTemp=boardTemp->next;
		}
		printf("----------------------------\n");
		printf("|    %12s          |\n",boardTemp->name );
		printf("---------------------------\n");
		printf("|      Rent         %-6d$|\n",boardTemp->rent );
		printf("|      Rent 1 H     %-6d$|\n",boardTemp->rent_1 );
		printf("|      Rent 2 H     %-6d$|\n",boardTemp->rent_2 );
		printf("|      Rent 3 H     %-6d$|\n",boardTemp->rent_3 );
		printf("----------------------------\n");
		printf("|      House Price  %-6d$|\n",boardTemp->house_price );
		printf("----------------------------\n");
		scanf("%d",&choice);
			if(choice==0)
				printf("Exitting...\n");/*to exit back to menu*/
				boardTemp=board;
	}	
}

void buy_property(struct block** current_block, struct player* current_player){
	int flag=0;
	int choc=0,empty=0;
	int i;
	printf("current player account: %d\n",(*current_player).account );
	if((*current_block)->type==property){
			if((*current_block)->owner.type==(*current_player).type)
				flag=1;
		
		printf("%d\n",flag );
		if(flag==0 && (*current_player).account>=(*current_block)->price){
			printf("do you want to buy block? (1/0)\n");/*I should check the user again cause of he/She can come again the same block and this time the block could be sold*/
			
			scanf("%d",&choc);
			
			switch(choc){
				case 1:
					(*current_player).account = (*current_player).account - (*current_block)->price;
					//printf("current player account: %d\n",current_player->account );
					for (i = 0; i < 11 && empty==0; ++i)
					{
						if((*current_player).owned_block_ids[i] ==0)
							empty=1;
					}
					(*current_player).owned_block_ids[i-1] = (*current_block)->block_id;/*it assignes the first empty index in array*/
					(*current_block)->owner.type=(*current_player).type;					
					break;
				case 0:
					(*current_player).account = (*current_player).account - (*current_block)->rent;
					break;
				default:
					printf("'%d' is an invalid choice\n",choc);
					break;
			}	
		}	
		if((*current_player).account>=(*current_block)->house_price){	
				printf("do you wanna buy an house 1/0\n");/*as you told program asks for house if the user bought the property*/
			
			scanf("%d",&choc);
			
			if (choc==1 && (*current_block)->house_count<4){
				(*current_player).account = (*current_player).account - (*current_block)->house_price;
				(*current_block)->house_count=(*current_block)->house_count +1;				
				printf("%d\n",(*current_block)->house_count );
			}
			
			else if ((*current_block)->house_count>3)/*the statement to check user dont buy more than three house*/
				
				printf("You bought all houses in this block\n");
			
			else
				printf("'%c' is an invalid choice\n",choc);

		}
	}  
}

void sell_property(struct block* board, struct player* current_player){
	int choice=0;
	int flag=0;
	int i,j;
	struct block* boardTemp=(struct block*)malloc(sizeof(struct block));
	boardTemp=board;
	for (i = 0; i < 24; ++i)
	{
		if (board->owner.type==current_player->type)
		{
			printf("\nThe Property:------------------------>%12s\n"
				   "Block id:---------------------------->%12d\n",board->name,board->block_id);
			printf("The property rent fee:--------------->%12d$\n",board->rent );
			printf("The houses you have:----------------->%12d\n",board->house_count );
			printf("The income from this property-------->%12d$\n",((board->price)/2)+((board->house_count * board->house_price)/2) );
		}
		board=board->next;
	}
	printf("What property that you want to sell Enter the block id, If you dont want to sel just enter '0'): ");
	scanf("%d",&choice);
	for (int i = 0; i < choice; ++i)
	{
		boardTemp=boardTemp->next;
	}
	if (choice!=0)
	{
		current_player->account = current_player->account + ((boardTemp->price)/2)+(boardTemp->house_count*boardTemp->house_price)/2;
		for (j = 0; j < 11 && flag==0; ++j)
		{
			if(boardTemp->block_id == current_player->owned_block_ids[j])
				flag=1;
		}
			current_player->owned_block_ids[j]=0;/*it make empty the user owned blocks arrays*/
			boardTemp->house_count=0;/*also houses sell so it has tto be 0*/
			boardTemp->owner.type=noone;/*and the owner type has to be again noone*/
		for ( j; j < 11 && j+1!=11 ; ++j)
		{
			current_player->owned_block_ids[j]=current_player->owned_block_ids[j+1];
		}
		/*Im not sure the shifting is necessary but I put that*/


	}
}
void AI(struct player* current_player,struct block* board,struct player* old_player){
	int computer_dice,avaiable,empty,i;
	computer_dice=roll_dice();
		printf("Computer rolled the dice: %d\n",computer_dice );
		(*current_player).current_block_id=(*current_player).current_block_id+computer_dice;
		for (int i = 0; i < computer_dice; ++i)
		{
			board=board->next;
		}
		avaiable=0;/*if avaiable =0 the block belong noone if 1 its belong opponent if it s 2 it belong current player */
		for (i = 0; i < 11; ++i){
			if(old_player->owned_block_ids[i]==(*current_player).current_block_id)
				avaiable=1;
		}
		for (i = 0; i < 11; ++i){
			if((*current_player).owned_block_ids[i]==(*current_player).current_block_id)
				avaiable=2;
		}
		if(avaiable=0 && board->type==property){
			if(board->price<33625){
				(*current_player).account = (*current_player).account - board->price;
					//printf("current player account: %d\n",current_player->account );
					for (i = 0; i < 11 && empty==0; ++i)
					{
						if((*current_player).owned_block_ids[i] ==0)
							empty=1;
					}
					(*current_player).owned_block_ids[i-1] = board->block_id;/*it assignes the first empty index in array*/
					board->owner.type=(*current_player).type;					

			}
			else{
				computer_dice=roll_dice();
				if (computer_dice>=1 &&computer_dice<=3)
				{	
					(*current_player).account = (*current_player).account - board->price;
					//printf("current player account: %d\n",current_player->account );
					for (i = 0; i < 11 && empty==0; ++i)
					{
						if((*current_player).owned_block_ids[i] ==0)
							empty=1;
					}
					(*current_player).owned_block_ids[i-1] = board->block_id;/*it assignes the first empty index in array*/
					board->owner.type=(*current_player).type;
										
				}
			}

		}
		if(avaiable=2 && board->type==property){
			for (i = 0; i < 11 && empty==0; ++i)
			{
				if((*current_player).owned_block_ids[i] ==0)
					empty=1;
			}
			if(i>=4){
				computer_dice=roll_dice();
					if (computer_dice>=1 &&computer_dice<=3)
					{
						if (board->house_count!=3 && (*current_player).account>=board->house_price){
						(*current_player).account = (*current_player).account - board->house_price;
						board->house_count = board->house_count +1;
					}
					}
			}		
		}


}	