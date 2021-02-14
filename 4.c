#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define BACK 5
#define QUIT 0
#define SIZE 4
typedef enum 
	{Charmander,Pikachu,Squirtle,Bulbasaur,Pidgeotto,Ratata,Mug,Caterpie,Zubat,Krabby,xx}
pokemon;
typedef enum 
	{quadratic,linear}
attack_type;
typedef enum
	{UP,DOWN,LEFT,RIGHT,UPT,DOWNT,LEFTT,RIGHTT}
movement;	/*ı also defined as enum the movements its more clear*/

void pokedex(char Pokemon_name[10][11], int range[], attack_type type[],int attack_power[], int stamina[]);

void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_Pokemons);
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[],int pokemon_count);
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket);
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket);
void menu(char Pokemon_name[10][11], int range[], attack_type type[],int attack_power[], int stamina[], pokemon Pokemons[],pokemon *my_Pokemons,int pokemon_count,pokemon *my_pocket);
int compare(char userinput[10],char Pokemon_name[10][11]);
void show_area (char Pokemon_name[10][11],int area[8][8],int pokemon_staminas_view[8][8]);
void battle(char Pokemon_name[10][11], int range[10], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]);
int randfo();

int main (){
	/*ı used parallel arraysthats mean if ı call charmander in pokemon name[0][11] array and the other arrays also show me the charmanders features; */
	char Pokemon_name[10][11] ={"Charmander","Pikachu","Squirtle","Bulbasaur","Pidgeotto","Ratata","Mug","Caterpie","Zubat","Krabby"};
 	int range[10]={1,3,4,3,2,2,1,2,3,2};
 	attack_type type[]={0,1,1,1,0,1,0,0,1,1};
 	int attack_power[]={500,350,300,400,250,250,350,200,350,300};
 	int stamina[]={2200,1500,1700,2500,1900,2500,3000,1200,1250,2600};
 	pokemon Pokemons[10]={0,1,2,3,4,5,6,7,8,9};
 	pokemon my_Pokemons[SIZE]={-1,-1,-1,-1};//ı defined sıze as 4 
 	pokemon my_pocket[SIZE]={-1,-1,-1,-1};
 	srand(time(NULL));
	/*pokemon my_pocket_array[4];*/
	int pokemon_count;
	menu(Pokemon_name,range,type,attack_power,stamina,Pokemons,my_Pokemons,pokemon_count,my_pocket);
	/*hocam bu arada belirteyim dedim benim ubuntu gcc de compile ettikten sonra programın çalışması için bir kaç kez ./exe yapmak gerekiyor muhtemelen benim bilgisayardan kaynaklı ama yinede belirtmek istedim*/
}
/*------------------------------------- PART - 5 ------------------------------------ */
void menu(char Pokemon_name[10][11], int range[], attack_type type[],int attack_power[], int stamina[], pokemon Pokemons[],pokemon *my_Pokemons,int pokemon_count,pokemon *my_pocket){
	int choice1;
		while(choice1 !=QUIT){
			printf("Please select an option to continue:\n\n1) Open Pokedex\n2) Go to Oak’s Laboratory\n3) Enter the tournament\n");
			scanf("%d",&choice1);
				switch(choice1){
					case 0:
						printf("See you again...");/*you did not say anyting about to terminate execution of program but ı defined 0 to quit program*/
						break;
					case 1:
						pokedex(Pokemon_name,range,type,attack_power,stamina);
						break;
					case 2:
		 				oaks_laboratory(Pokemon_name,Pokemons,my_Pokemons);
						break;
					case 3:
						printf("enter rows{first(7), second(6)} and columns{(0,7)}  that you want to place pokemons\n");
						battle(Pokemon_name,range,type,attack_power,stamina,my_Pokemons);
						break;
					default:
						printf("Invalid choice.\n");
						continue;
				}			
		}				

}
/*------------------------------------- PART - 1 ------------------------------------ */
void pokedex(char Pokemon_name[10][11], int range[], attack_type type[],int attack_power[], int stamina[]){
	
	char d;
	char userinput[10];
	pokemon current_pokemon;
		while(current_pokemon!=-1){
			printf("Please type name of the Pokémon (type exit to close Pokedex):\n");
			
					scanf("%s",userinput);
				
			current_pokemon=compare(userinput,Pokemon_name);/*ı explained the following rows in compare function*/
			if (current_pokemon==-2){
				printf("This is an invalid name\n");
			}
			else if(current_pokemon==-1){
				printf("exitting...\n");
				break;
			}
			else			
				for (int i = 0; i <1 ; ++i)/*pokemon name get the pokemon names strings and current pokemon is enum variable*/
				{
					printf("Name    : %s\n",Pokemon_name[current_pokemon]);
					if (type[current_pokemon]==0)
					{
						printf("A. Type : Quadratic\n");
					}
					else{
						printf("A. Type : Linear\n");
					}	
					/*printf("A. Type : "(type[current_pokemon] ==1) ?"Linear\n":"Quadratic\n");*/
					printf("Range   : %d block\n",range[current_pokemon] );
					printf("A. Power : %d\n",attack_power[current_pokemon] );
					printf("Stamina: %d\n\n\n",stamina[current_pokemon]);
				}
		}		

}
/*compare function it checks the pokemon names and input name */
int compare(char userinput[10],char Pokemon_name[10][11]){
	char exit[5]={"exit"};/*also I checked exit in another array */
	int result=-2,i,a;/*if user enter different name from userinput its going to return -2 which is mean its an invalid name  */
		for (a = -1; a <10 ; ++a)
		{
			for (i = 0; userinput[i]==Pokemon_name[a][i]; ++i){
				if (userinput[i]=='\0'){
					result= a;
					break;
					}
			}
			for (int l = 0; userinput[l]==exit[l] ; ++l){/*its going to increase for each element of character array*/
				if (userinput[l]=='\0'){
				result=-1;
				break;
				}
			}
			
		}
	return result;
}

/*------------------------------------- PART - 2 ------------------------------------ */

void oaks_laboratory(char Pokemon_name[10][11], pokemon Pokemons[], pokemon *my_Pokemons){
	int pokemon_count;
	int choice=0;

		/*printf("\e[2J");//clears the terminal screen*/
		printf("\v\v\v\vWelcome to Laboratory of Professor Oak. How can I help you?\n1) Show Pokémons\n2) Catch a Pokémon\n3) Release a Pokémon\n4) Show my pocket\n5) Back\n");
					
		while(choice != BACK){
		
			scanf("%d",&choice);
			switch(choice){
				case 1:
				 pokemon_count=10;
					show_Pokemons(Pokemon_name,Pokemons,pokemon_count);
					/*printf("\e[2J");*/
					printf("\v\v\v\vWelcome to Laboratory of Professor Oak. How can I help you?\n1) Show Pokémons\n2) Catch a Pokémon\n3) Release a Pokémon\n4) Show my pocket\n5) Back\n");
					break;
				case 2:
					catch_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);

					for (int i = 0; i < 4; ++i)
					{
						
						Pokemons[i]=my_Pokemons[i];
					}/* after user caught the pokemons it has to be assign the pokemons to send pokemons other functions as parameter*/
					printf("\v\v\v\vWelcome to Laboratory of Professor Oak. How can I help you?\n1) Show Pokémons\n2) Catch a Pokémon\n3) Release a Pokémon\n4) Show my pocket\n5) Back\n");
					break;
				case 3:	
					release_a_pokemon(Pokemon_name,Pokemons,my_Pokemons);
				
					printf("\v\v\v\vWelcome to Laboratory of Professor Oak. How can I help you?\n1) Show Pokémons\n2) Catch a Pokémon\n3) Release a Pokémon\n4) Show my pocket\n5) Back\n");
					break;
				case 4:
				 pokemon_count=4;
					show_Pokemons(Pokemon_name,my_Pokemons, pokemon_count);
					printf("\v\v\v\vWelcome to Laboratory of Professor Oak. How can I help you?\n1) Show Pokémons\n2) Catch a Pokémon\n3) Release a Pokémon\n4) Show my pocket\n5) Back\n");
					break;
				case 5:
					choice = BACK;/* ı defined BACK as five to quit to go main manu*/
					printf("You are forwarding the menu...\n");		
					break;
				default:
				printf("This is an invalid choice. Try again!”\n");
					continue;

			}
		}	
					
}
void catch_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket){
	pokemon caught;
	int flag =0,warn=0;
	int i,num;
	int pokemon_count=10;
	show_Pokemons(Pokemon_name,Pokemons,pokemon_count);
	printf("Enter the pokemon number that you want to catch:\n");
	scanf("%d",&num);
	caught=num;
	i=0;
	int found=0;
	if(caught>=0 && caught<=9){
		for (i = 0; i < 4; ++i){


			if (my_pocket[i]==caught)
			{

				found = 1;/* secilen pokemonun arrayde olup olmadığını check eder */
				warn =1;/* to print warming message to user it has already cohoosen*/
			}

		}
		i=0;
		while(flag==0 && found==0 && i<5)
		{
				if ((my_pocket[i]==-1))
				{
					flag=1;
				}
			
			++i;		
		}
		i=i-1;
		my_pocket[i]=caught;
			if(i>3)
			printf("Your pocket is full!!!\n");
		else if(warn==1){
			for (int i = 0; i < 1; ++i)
				{
					printf("%s has already caught.\n",Pokemon_name[caught] );
				}

		}
		else{
			for (int i = 0; i < 1; ++i)
			{
				printf("%s was caught.\n",Pokemon_name[caught] );
			}
		}
	}
	else
		printf("Enter a valid pokemon number!\n");	

}
void release_a_pokemon(char Pokemon_name[10][11], pokemon Pokemons[],pokemon *my_pocket){
	int release_number,i;/*array indis number*/
	pokemon released;/*a variable whic is declared pokemon type*/
	int pokemon_count=4;
		show_Pokemons(Pokemon_name,Pokemons,pokemon_count);
		scanf("%d",&release_number);
		released=release_number;/*released which is decleared pokemon type*/
		pokemon_count=4;
		if(released<=3 && released>=0){
			for (i = 0; i < 1; ++i)
			{
				printf("%s was released.\n",Pokemon_name[Pokemons[released]] );
			}
			for (released; released < 3; ++released)
			{
				my_pocket[released]= my_pocket[released+1];
			
			}	
		
				my_pocket[3]=-1;
	
			for ( i = 0; i < 4; ++i)
			{
			
				Pokemons[i]=my_pocket[i];
			}
			printf("Pokémons in your pocket:\n");
			show_Pokemons(Pokemon_name,Pokemons,pokemon_count);
		}
		else
			printf("Please enter a valid choice\n");
}
/*ı couldnt use the pokemon_count actively if 4 print the pocket else if 4 or smmaller than 4 print the my pocket */
void show_Pokemons(char Pokemon_name[10][11], pokemon Pokemons[],int pokemon_count){
	int i;
	
	if(pokemon_count==10)
		for ( i = 0; i <10 ; ++i)
		{
			printf( "%d -%s\n",i,Pokemon_name[i]);
	 
		}
	else if(pokemon_count<=4)
		for ( i = 0; i <4 ; ++i)
		{	if(Pokemons[i]== -1)
				continue;
			else
			printf( "%d - %s\n",i,Pokemon_name[Pokemons[i]]);
	 
		}
	
}
/*------------------------------------- PART - 3 ------------------------------------ */
/*rand function*/
int randfo(int max,int min){
	int randnum=(rand()%(max-min+1))+min;
		return randnum;
}
void battle(char Pokemon_name[10][11], int range[], attack_type type[], int attack_power[], int stamina[], pokemon user_Pokemons[]){
	/*firstly before the battle starts the area have to be different numbers following arrays (sorry for the hard coddded)*/
	int pokemon_staminas_view[8][8]={{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10}};
	pokemon computer_pokemons[4]={-3,-3,-3,-3};	
	int area[8][8]={{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10},{10,10,10,10,10,10,10,10}};
	int x,y,k,l,m,i,check=0, move;
	for ( i = 0; i <4 ; ++i)
	{	/*following rows four get different random numbers it works random numbers but ı can not put them in the computer arrays */
		check=0;
		m=randfo(9,0);
		
		for (int j = 0; j < 4; ++j)
		{
			if(computer_pokemons[j]==m)
				check=1;
			
		}
		/*if (check==1)
			continue;*/
		
			computer_pokemons[i]=m;
	}
	for (int i = 0; i < 4; ++i)
	{	scanf("%d",&k);
		scanf("%d",&l);
		pokemon_staminas_view[k][l]=stamina[user_Pokemons[i]];
		area[k][l]=user_Pokemons[i];
		for (int i = 0; i <1 ; ++i)
		{		
					y=randfo(1,0);
					x=randfo(7,0);
				for (int j = 0; j < 4; ++j)
				{
					if(area[y][x]==y,x)
						continue;
				
				}
		
				area[y][x]=computer_pokemons[i];
				pokemon_staminas_view[y][x]=stamina[computer_pokemons[i]];
		}	
			
	}	
	
	show_area (Pokemon_name,area,pokemon_staminas_view);

	printf("enter rows{first(7), second(6)} columns{(0,7)}  that you want to make pokemon movement\n");
	scanf("%d",&k);
	scanf("%d",&l);
	printf("choose the direction and number of movement \n(0)UP(one block)\n(1)DOWN(one block)\n(2)LEFT(one block)\n(3)RIGHT(one block)\n");
	printf("for TWO block movement\n(4)UP(two block)\n(5)DOWN(two block)\n(6)LEFT(two block)\n(7)RIGHT(two block)\n");
	scanf("%d",&move);
  	/*movements but according my algorithm the two rows on the bottom are for the user*/
	if(move==DOWN){
		area[k+1][l]=area[k][l];
		area[k][l]=10;
	}	
	else if(move==UP){
		area[k-1][l]=area[k][l];
		area[k][l]=10;
	}
	else if(move==LEFT){
		area[k][l-1]=area[k][l];
		area[k][l]=10;
	}
	else if(move==RIGHT){
		area[k][l+1]=area[k][l];
		area[k][l]=10;
	}
	else if(move==UPT){
		area[k-2][l]=area[k][l];
		area[k][l]=10;
	}
	else if(move==DOWNT){
		area[k+2][l]=area[k][l];
		area[k][l]=10;
	}
	else if(move==LEFTT){
		area[k][l-2]=area[k][l];
		area[k][l]=10;
	}
	else if(move==RIGHTT){
		area[k][l+2]=area[k][l];
		area[k][l]=10;
	}		
	show_area (Pokemon_name,area,pokemon_staminas_view);	





}
/*------------------------------------- PART - 4 ------------------------------------ */
void show_area (char Pokemon_name[10][11],int area[8][8],int pokemon_staminas_view[8][8]){
	char c;
	
	
	for (int a = 0; a < 8; ++a)
	{
		printf("\n");
		
		for (int i = 0; i < 8; ++i)
		{
			
			printf("|   %c%c    ",Pokemon_name[area[a][i]][0],Pokemon_name[area[a][i]][1]);////we can print character by character  for the pokemons first two letter

		}
		printf("|\n");
	
		for (int i = 0; i < 8; ++i)
		{
			printf("|        ");
		}
		printf("|\n");
		if(a==7)/*this line to block  print last ----------- row*/
			continue;
		else
		printf("\n-------------------------------------------------------------------------\n");
	}

	
}
