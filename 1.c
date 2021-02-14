#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3
#define SQUARE 1
#define	RECTANGULAR 2
#define CIRCULAR 3

#define RED 0
#define YELLOW 1
#define BLUE 2
#define BLACK 3
#define WHITE 4

double CreateBody (int shape);
int SetColor (int color);
double LoadMoves(int shape, double body_size);
int SetAttackPower(int lower_bound, int upper_bound);
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power);

int main ()
{
	int shape, color, attack_power;
	double size_of_body, move_length;
		shape = CIRCULAR;
		size_of_body = CreateBody (shape);
		color = 798;
		color = SetColor(color);
		move_length = LoadMoves(shape, size_of_body);
		attack_power = SetAttackPower (0,150);
		ShowPokemon(shape, size_of_body, color, move_length, attack_power);
}

//////////////////////////////////Part_1	
double CreateBody (int shape){	
	double size_of_body;
    double length1,length2;
		if (shape==1){
			printf("Enter one side of Square\n");
			scanf("%lf",&length1);
			size_of_body= length1*length1;
		}
			else if (shape == 2){
				printf("\n Enter the edges of Rectangular\n");
				scanf("%lf",&length1);
				scanf("%lf",&length2);
				size_of_body= length1*length2;
			}
				else if (shape == 3){
					printf("Enter the radius of Circle\n");
					scanf("%lf",&length1);
					size_of_body= PI*length1*length1;
				}
	return size_of_body;
}
/////////////////////////Part_2
int SetColor (int color) 
{
	if(color>=0 && color<=1000){
		color= color%5;
	}
		else
			color = WHITE;

	return color;
}
/////////////////////////////////////////Part_3
double LoadMoves(int shape, double body_size)
{
	double move_length;
	if (shape==1){
			move_length = sqrt(body_size)*4;	//ı used sqrt function to calculate
		}
			else if (shape == 2){
				move_length= ((body_size/5)+5)*2;  /* That's to calculate rectangular and ı used 5 for a side otherwise 
				             ı should break the function or ı had to declare them with different data types such as extern etc.*/		
			}
				else if (shape == 3){ 
					move_length= (sqrt(body_size)*sqrt(PI))*2 ;
				}
	return move_length;

}
//////////////////////Part_4
int SetAttackPower(int lower_bound, int upper_bound) {
	int power,range;
	range =upper_bound- lower_bound+1;
		srand(time(NULL));   //thats to declare seed value so ı have to declare it null and with time function which is in time header
		power=(rand() % range)+lower_bound; /*rand function gives randomly numbers but it can be bigger than the range of numbers
		so we have to get mod of it according to range nummber and then we should add the low number cause of the it can be smaller than the 
		lower number*/
	return power;	
}

////////////////////////////////////Part_5
void ShowPokemon(int shape, double body_size, int color, double move_length, int attack_power){	
	int i,j,radius,length;
	char clr[10];
/*ı pre defined the colors as you say and ı used them in colour function to print colors*/
	void colour(int color){
		if (color == RED){
			printf("Red");
		}
				
			else if (color==YELLOW){
				printf("Yellow");
			}
			
				else if (color ==BLUE){
					printf("Blue");
				}
			
					else if(color==BLACK){
						printf("Black");
					}
			
						else
							printf("White");
}
			if (shape==1){
				length= sqrt(body_size);
				for(i=0; i<length; i++){	
					for (j=0; j<length; j++){
						printf("X");
					}
					printf("\n");
				}	
				printf("Name : Square Pokémon\n");
				printf("Size : %.0lf\n",body_size);
				printf("Color : ");
				colour(color);
				printf("\nMove : %.2lf\n",move_length);
				printf("Attack Power %d: \n",attack_power);
			}
			if (shape==2){
				length= body_size/5;
				for(i=0; i<length; i++){	///ı get one of rectangular side as 5 
					for (j=0; j<5; j++){
						printf("X");
					}
					printf("\n");
				}	
				printf("Name : Rectangular Pokémon\n");
				printf("Size : %.0f\n",body_size);
				printf("Color : ");
				colour(color);
				printf("\nMove : %.2lf\n",move_length);
				printf("Attack Power %d: \n",attack_power);

			}
			if (shape==3){
				radius= sqrt((body_size)/PI) ;
				int inciterim =(radius+1)/2;//it finds number of terms which is same with line of (up side+middle one) and (down side-middle one) 
				int a=inciterim,b=inciterim,c=1;
				int i,j,k;
				if (radius%2==1){ //this block to print odd numbers
					if(radius==1){//to print if user enter 1 as radius
						printf("x\n");
					}
						else{
							
							for (i = 0; i < radius-1; ++i){ //this line to print first x and ı found its readius-1 multiplying by 4 white space
									printf("    ");
							}
							printf("x\n");
								
								for (i=1; i!=inciterim; ++i){ //term of number is to print how many line for upside 
										int j;
										for (j=0; j!=a-2; j++){ //its for outside of circle before the first x for each line  
											printf("\t");
										}
										printf("x");
										a=a-1;
											int k;
											for ( k = 0; k<c ; k++){ //these tabs for inside of circle(between two x)
												printf("\t");
											}
										c=c+2;
										printf("\t");
										printf("x\n");
									}
							
							for (i = 1; i!= inciterim-1; ++i){// this block to print downside of circle 
									
									for (j=0; j!=a-2; j--){
										printf("\t");
									}
									printf("x");
									a=a-1;
									
									for (k = 2; k<c ; k++){
										printf("\t");
									}
									c=c-2;
									printf("\b\b\b\b\b\b\b\b");//it pirinted one more tabs each time so ı used  8 backspace to a tab effect
									printf("x\n");
								}
							
							for (i = 0; i < radius-1; ++i){//it prints last x
									printf("    ");
							}
							printf("x\n");	
						}
					}
						else{//this block to print even numbers
						  if(radius==2){
						  	printf("    x\nx\tx\n    x\n");//ı could not print for 2 radius so ı printed it own my own
						  }
								  else{
						
									for (i = 0; i < radius-1; ++i){//first line
											printf("    ");
										}
										printf("x\n");				
									for (i=1; i!=inciterim; ++i){
											for (j=0; j!=a-2; j++){
												printf("\t");
											}
											printf("\t");
											printf("x");
											a=a-1;
											for (k = 0; k<c ; k++){
												printf("\t");
											}
											c=c+2;
											printf("x\n");
										}
									printf("x");//////this line to print middle line and the number of tab carachter is radius-1
									
									for(i=0;i<radius-1; i++){
										printf("\t");
									}	
										printf("x\n");
									for ( i = 1; i!= inciterim-1; ++i){
										printf("\t");
											for (j=0; j!=a-2; j--){
												printf("\t");
											}
											printf("\b\b\b\b\b\b\b\b");
											printf("x");
											a=a-1;
											for (k = 2; k<c ; k++){
												printf("\t");
											}
											c=c-2;
											printf("x\n");
										}
										for(i=0;i!=(radius-2)/2;i++){
											printf("\t");
										}
										printf("x\tx\n");
									for (i = 0; i < radius-1; ++i){
											printf("    ");
										}
										printf("x\n");	
								}				
						}
										printf("Name : Circular Pokémon\n");
										printf("Size : %.2f\n",body_size);
										printf("Color : ");
										colour(color);
										printf("\nMove : %.2lf\n",move_length);
										printf("Attack Power : %d \n",attack_power);

						}
}
