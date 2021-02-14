#include <stdio.h>
#include <string.h>
#define QUIT 4

void first_menu();
///////////////////////////////part 1
void calc_men();
void usage();
int doit (int function(), int first_number, int second_number);
int add(int number1, int number2);
int sub(int number1, int number2);
int mul(int number1, int number2);
int div(int number1, int number2);
int powi(int number1, int number2);
int mod(int number1, int number2);

//////////////////////////////part 2
int take_grades(int grades[]);
int take_exam_grades(int exam[]);
double calculate_homework(int homework_grades[]);
double calculate_lab(int lab_grades[]);
double calculate_all(int homework_average,int exam[],int lab_average);
/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////part 3
void print_shape(int input);
/////////////////////////////////////////////////////////////////////////////////////

int main(){
	first_menu();
	return 0;
}
/////////////////////////////////////////////////////////part 1 implements

void first_menu(){
	int choice=0;
	printf("\e[2J");//clears the terminal screen
	printf("\v\v\v\v***** MENU *****\n1. Calculator\n2. Calculate The Weighted Average \n3. Print The Shape\n4. Exit\nChoice: ");

	while(choice != QUIT){
	
		scanf("%d",&choice);
		switch(choice){
			case 1:
				calc_men();
				printf("\v\v\v\v***** MENU *****\n1. Calculator\n2. Calculate The Weighted Average \n3. Print The Shape\n4. Exit\nChoice: ");
				
				break;
			case 2:
				printf("Enter Homework grades:\n");
				int homework_grades[10];
				int lab_grades[10];
				int exam[2];
				take_grades(homework_grades);
				printf("Enter Lab grades:\n");					
				take_grades(lab_grades);
				take_exam_grades(exam);
				int homework_average= (int)calculate_homework(homework_grades);
				int lab_average=(int)calculate_lab(lab_grades);
				double result=calculate_all(homework_average,exam,lab_average);
				printf("\n\nThe Weighted Average is %.3lf\n",result);
			 	printf("\v\v\v\v***** MENU *****\n1. Calculator\n2. Calculate The Weighted Average \n3. Print The Shape\n4. Exit\nChoice: ");
				
				break;
			case 3:

				printf("\nInput: \n");
				int input;
				scanf("%d",&input);
				print_shape(input);
				printf("\v\v\v\v***** MENU *****\n1. Calculator\n2. Calculate The Weighted Average \n3. Print The Shape\n4. Exit\nChoice: ");				


				break;
			case 4:
				choice = QUIT;// ı defined QUIT as four to quit from main manu
				printf("exiting...\n");
				
				break;
			default:
			printf("This is an invalid choice. Try again!”\n");
				continue;

		}
	}
}
void calc_men(){
	usage();
	char string[100];//to get input for calculator
	char exit=1;
	int a;
	/*a is the return value of sscanf sscanf returns how many string that it gets and it returns the number of strings
	so we can fix the Is user going to use result value or its going to enter a new operations */
	char operator[2];
	int firstnum,secondnum;
	int result=0;// if user starts like + 1 it accepts as zero the first value

	while(exit){
	scanf(" %[^\n]s",string);//thats mean commputer going to take untill the user press enter key which is new line character
			sscanf( string, "%s  %d  %d", operator, &firstnum, &secondnum );
			a=sscanf( string, "%s  %d  %d", operator, &firstnum, &secondnum );
			if(a==2)
			{			/*simply swapping if user wants  to use previous value*/
					secondnum=firstnum;
					firstnum=result;
				
				if (operator[0]=='+' )
						result=doit (add,firstnum,secondnum);
				else if (operator[0]=='-')
						result=doit (sub,firstnum,secondnum);
				else if (operator[0]=='*'){
					if (operator[1]=='*')
						result=doit (powi,firstnum,secondnum);
					else		
						result=doit (mul,firstnum,secondnum);
				}
				else if (operator[0]=='/')
					if (secondnum==0){
						printf("Please enter a valid value\n");//if user wants to divide a number by zero
						continue;
					}
					else{
						result=doit (div,firstnum,secondnum);
					}
							
				else if (operator[0]=='%')
					if (secondnum==0){
						printf("Please enter a valid value\n");
						continue;
					}
					else
						result=doit (mod,firstnum,secondnum);					

			}
				else if(a==3)
				{
					if (operator[0]=='+' )
						result=doit (add,firstnum,secondnum);
				else if (operator[0]=='-')
						result=doit (sub,firstnum,secondnum);
				else if (operator[0]=='*'){
					if (operator[1]=='*')
						result=doit (powi,firstnum,secondnum);
					else		
						result=doit (mul,firstnum,secondnum);
				}
				else if (operator[0]=='/')
					if (secondnum==0){
						printf("Please enter a valid value\n");
						continue;
					}
					else{
						result=doit (div,firstnum,secondnum);
					}
							
				else if (operator[0]=='%')
						if (secondnum==0){
						printf("Please enter a valid value\n");
						continue;
					}
					else
						result=doit (mod,firstnum,secondnum);	

				}
				if(operator[0]=='q')
					exit=0;
				else
					printf("%d\n",result);			
	}
}
void usage(){// ı dont wantto make confuse my code wit printf so ı arranged the usage hear
	printf("\e[2J");
	printf("******INSTRUCTIONS of CALCULATOR*******\nyou are going to use operator signs to use calculator\n");
	printf("+ Addition\n- Substruction\n/ Division\n* Multiplication\n** Power \n%% Modulus\n");
	printf("Please leave space character for every character\n(Exp.:** 12 2 =144)\nPress q key to go MENU\n");
	printf("*********************************************\n\n\n");
}
int doit (int function(), int first_number, int second_number){
	int result;
		result= function (first_number,second_number);
		return result;
}



int add(int number1, int number2){
	return number1 + number2;
}
int sub(int number1, int number2){
	return number1 - number2;
}
int mul(int number1, int number2){
	return number1 * number2;
}
int div(int number1, int number2){
	return number1/number2;
}
int powi(int number1, int number2){
	int pow_result=1;
	for (int i = 0; i < number2 ; ++i)
	{
		pow_result = pow_result*number1;
	}
	return pow_result;
}
int mod(int number1, int number2){
	return number1 % number2;
}
/////////////////////////////////////////////part 2 implements
int take_grades(int grades[]){
	

		for(int i=0; i<10; i++){
			printf("\n%d) ",i+1 );
			scanf("%d",&grades[i]);
		}	

	return 0;
}
int take_exam_grades(int exam[]){
	printf("Enter the Midterm exam: ");
	scanf("%d",&exam[0]);
	printf("\nEnter the Final exam: ");
	scanf("%d",&exam[1]);
	return 0;
}
double calculate_homework(int homework_grades[]){
	int total_hwgrade=0;
	double average_hw;
		for (int i = 0; i < 10; ++i)
		{
			total_hwgrade = total_hwgrade+homework_grades[i];
		}
		average_hw= (double)total_hwgrade/10;
	return average_hw;
}
double calculate_lab(int lab_grades[]){
	int total_labgrade=0;
	double average_lab;
		for (int i = 0; i < 10; ++i)
		{
			total_labgrade = total_labgrade+lab_grades[i];
		}
		average_lab= (double)total_labgrade/10;
	return average_lab;
}
double calculate_all(int homework_average,int exam[],int lab_average){
	double homework_atotal=(double)(homework_average)*10/100;
	double lab_atotal=(double)(lab_average)*20/100;
	double midterm= (double)(exam[0])*30/100;
	double final = (double)(exam[1])*40/100;
	double weighted_average= midterm+final+lab_atotal+homework_atotal;
	
	return weighted_average;

}
////////////////////////////////////////////////////////// part 3 implements
void print_shape(int input){
	int outspace=input;
	int star=0;
		for(int i=0; i<input; i++){
			for (int j = 0; j < outspace; ++j)
			{
				printf(" ");
			}
			outspace=outspace-1;
			printf("/");
			for(int k=0; k<star; k++){
				printf("*");
			}
			star=star+2;//it increaases two for each line
			printf("\\\n");
		}
		/*its going to print /\ and \/ each time for first line and after that it starts to print stars*/
		for(int i=0; i<input; i++){
			for (int j =0; j < outspace+1; j++)
			{
				printf(" ");
			}
			outspace=outspace+1;
			printf("\\");
			for(int k=0; k<star-2; k++){
				printf("*");
			}
			star=star-2;
			printf("/\n");
		}	
}	