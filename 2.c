#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define QUIT 4

// prototypes
void menu();
void draw_hourglass (int height);
void draw_mountain_road (int length, int max_radius);
int make_a_guess (int trial, int min, int max);
//void show_scores(int *score_human, int *score_program);
int sub (int subs);//
//

int main()
{
	srand(time(NULL));
	menu();	
	return 0;
}

// implements
void menu(){
	printf("\e[2J");//it clears the terminal
	printf("***** MENU *****\n1. Play Lucky Number\n2. Draw Hourglass\n3. Draw Mountain Road\n4. Exit\nChoice: ");
	int choice,height,length,max_radius;
	//int *scH,*scP;
	
//	scanf("%d",&choice);
	while(choice != QUIT){//ı defined quit 4 and I put it an infinite while loop so its gonna repeat until the user enter 4 which is defined QUıT 
	
		scanf("%d",&choice);
		switch(choice){
			case 1:
				make_a_guess (8, 1, 1024);//(trial number,minvalue,maxvalue)
				//show_scores(&scH,&scP);	 //
				printf("\v\v\v\v***** MENU *****\n1. Play Lucky Number\n2. Draw Hourglass\n3. Draw Mountain Road\n4. Exit\nChoice: "); 
				
				break;
			case 2:
				printf("Enter the height of glasshour\n");
				int height=3;//My algorithim is going to check whether is odd number so ı have to assign a trash value at this line 
				draw_hourglass (height);
				printf("\v\v\v\v***** MENU *****\n1. Play Lucky Number\n2. Draw Hourglass\n3. Draw Mountain Road\n4. Exit\nChoice: ");
				
				break;
			case 3:
				printf("Enter the length and max radius of mountain road\n");
				scanf("%d%d",&length,&max_radius);
				draw_mountain_road (length,max_radius);
				printf("\v\v\v\v***** MENU *****\n1. Play Lucky Number\n2. Draw Hourglass\n3. Draw Mountain Road\n4. Exit\nChoice: ");				
				break;
			case 4:
				choice = QUIT;
				printf("exiting...\n");
				break;
			default://this line if user enter an unvalid value the loop repeat menu again so ı used continue
				printf("This is an invalid choice. Try again!”\n");
				continue;

		}
	}
}
      
void draw_hourglass (int height){
	while(1){//this line necessary to check it is even or odd number
	scanf("%d",&height);
	int height1=height;//ı use height value so ı dont want to change it it can be a problem
	int k=1;//k value to determine number of spaces 
	int check= height%2;//two modulus
				int row=(height-1)/2;
		switch(check){
			case 0:
				printf("This is an invalid height. Please enter an odd number!”\n");
				continue;
			case 1:
				for (int i = 0; i < row; ++i)
				{
					
					for (int i=0; i!=height1; i++)
					{
						printf("*");
					}
					printf("\n");
						for(int j=0; j!=k;j++)
						{
							printf(" ");
						}
					k=k+1;
					height1=height1-2;
				}
				printf("*\n");
				for (int i = 0; i < row; ++i)
				{
					height1=height1+2;
					
						for(int j=k; j!=2;j--)
						{
							printf(" ");
						}
					k=k-1;
					for (int i=height1; i!=0; i--)
					{
						printf("*");
					}
					printf("\n");
				}
			}
			break;
	}
}

void draw_mountain_road (int length, int max_radius){
	int randnum;	
	int i,space=max_radius;
	if(max_radius==0){
		for (int i = 0; i < length; ++i)//this line necessary to if the user enter max radius zero
		{
			printf("|			------------>%d\n",randnum);
		}
	}
	else
	
	for(int i=0; i<length; i++){
		randnum =rand()%(max_radius+1);//its to include zero(radius)otherwise always it starts 1   
		
		for (int j = 0; j < randnum ; ++j){
			for (int i = 0; i <space+1 ; ++i){//this line and 138. and 146.line to leave enough space the (biggest radius) between mountain and edge of terminal
				printf(" ");
			}						
				space=space-1;	//its to decrease numbers of space 
		
		printf("/\n");
		
		}
			for (int i = 0; i < space+1; ++i){
					printf(" ");
					}
		
		printf("|			------------>%d\n",randnum);								
		
		for (int j = 0; j < randnum ; ++j){
			for (int i = 0; i <space+2 ; ++i){
				printf(" ");
			}						
				space=space+1;	
									
		printf("\\\n");
		
		}
		randnum =rand()%(max_radius+1);
		for (int j = 0; j < randnum ; ++j){
			for (int i = 0; i <space+2 ; ++i){
				printf(" ");
			}						
				space=space+1;	
									
		printf("\\\n");
		
		}
		for (int i = 0; i < space+2; ++i){
					printf(" ");
					}
		printf("|			------------>%d\n",randnum);
		for (int j = 0; j < randnum ; ++j){
			for (int i = 0; i <space+1 ; ++i){//this line (space =max_radius) to leave enough space the (biggest radius) between mountain and edge of terminal
				printf(" ");
			}						
				space=space-1;	//its to decrease numbers of space 
		
		printf("/\n");
		
		}//////////////////////////174-210 lines are necessary to if user enter odd length ı couldnt write a mathemtical algorithm so 
		//ı add one more line to write it as you want 
		if(length%2==1){
			if(length==1){
				length=length/2;//According to my algorithm the length print 2 mountain for each time so ı have to divide it by two
			}
			else
			length =(length-1)/2;
				randnum =rand()%(max_radius+1);//its to include zero(radius)otherwise always it starts 1   
			//printf("");
			for (int j = 0; j < randnum ; ++j){
				for (int i = 0; i <space+1 ; ++i){//this line (space =max_radius) to leave enough space the (biggest radius) between mountain and edge of terminal
					printf(" ");
				}						
					space=space-1;	//its to decrease numbers of space 
			
			printf("/\n");
			
			}
				for (int i = 0; i < space+1; ++i){
						printf(" ");
				}
			printf("|			------------>%d\n",randnum);								
			
			for (int j = 0; j < randnum ; ++j){
				for (int i = 0; i <space+2 ; ++i){
					printf(" ");
				}						
					space=space+1;				
			printf("\\\n");		
			}
		}	

	else{
		length=length/2;
	
	}

	}	


}
int make_a_guess (int trial, int min, int max){
	int randnum=(rand()%(max-min+1))+min;
	//int score_human=0,score_program=0;
	//int *scH;
	//int *scP;
	//scH=&score_human;
	//scP=&score_program;
	int subs,guess,guessNew=1024,guessOld,guessTemp,i;
	printf("With having Trial=8 & LN = %d\n",randnum );
	printf("(Trial: 1) Make guess between %d and %d: ",min,max);
			for (i=2; i<trial+2; i++){//i starts from 2 cause of the I print trial 1 befor the loop starts;
				scanf("%d",&guess);

				if (guess>max || guess<min)//tis line checks guess if user enter different interval from min max values
				{
					printf("Invalid trial. Try again...\n");
					continue;
				}
				else
				subs= guess-randnum;
				if (guess >randnum)
				guessTemp=guess;
				else
				if (subs<0)
					subs=-subs;
				else
					subs=subs;
				
				printf("Distance: %d\n",sub(subs) );//ı leave a commet in function

			if(guess==randnum)//to check did user enter true value or not 
				break;


			else if(randnum>guess){//ıif rand number bigger than guess it assign guess to guessold variable otherwise when user enter a bigger value than randnum
			                      // its going to say exp: Make guess betweeen A and A; so ı fixed that problem the following 8 lines 
						printf("(Trial: %d) Make guess between %d and %d: ",i,guess,guessNew);
						guessOld =guess;
					}
					
					else {

						printf("(Trial: %d) Make guess between %d and% d: ",i,guessOld,guess) ;
						guessNew=guess;
					}

		}
		if(i==trial+2){
	//		*scP++;
			printf("Game Over...\n");
		}
		else{
			printf("You WIN the game\n");
	//		*scH++;
		}
		
	//	void show_scores(scH,scP);
		return guess;
	
}
void show_scores(int *score_human, int *score_program){

	printf("Your Score: %d Program Score: %d\n",*score_human,*score_program );
}
//////////////////DISTANCE
int sub(int subs){
	int i;
		for(i=0; subs!=0; i++){
			subs=subs/2;//actually i is the two's powers so for xexample if the distanceof numbers is 140 its 2^7(128) until the 2^8(256)
		}
	return i;
}