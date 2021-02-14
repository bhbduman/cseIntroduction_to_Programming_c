#include <stdio.h>

#define QUIT 0
#define ARRAYSIZE 100
#define STRING 100

void menu();/*	Menu function*/
int gcd_finder(int firstnum,int secondnum);/*1-part*/
void mergeANDsort(int unsort_ar[],int f_elem, int l_elem);/*2-part*/
void merge(int *unsort_ar,int f_elem,int m_elem,int l_elem);
void di_foo(int input);/*3-part*/
int equal_or_not(int input,int count_digit);/*4-part*/
int digit_count(int input,int count_digit);
int recursive_pow(int base, int exponent);
char find_capital(char *inputchar);/*5-part*/

int main(){	
	
	menu();/*I just call the menu with this function and ı made all calculations int he menu*/
	
	return 0;
}
void menu(){
	int choice1=1;/*Its necessary to quit while loop*/
	int firstnum,secondnum,result;
	int input;
	int count_digit=0;
	int length_of_list;
	int unsort_ar[ARRAYSIZE]={0};	
	char inputchar[STRING]={'\0'};
	char resultchar;
	int i;
	printf("********************HomeWork-6-********************");
	while(choice1!=QUIT){/*I defined quit as 0 */
		printf("\n\n\nPlease select a part to continue(Enter 0 to QUIT):\n1) Part-1-(GCD)\n2) Part-2-(Sort)\n3) Part-3-(Formula F(n))\n4) Part-4-(Equal or not)\n5) Part-5-(Find capital)\n\n");
		
		scanf("%d",&choice1);
			switch(choice1){
				case 0:
					choice1=QUIT;
					printf("See you again...");
					break;
				case 1:
					printf("Enter the numbers:\n");
					scanf("%d%d",&firstnum,&secondnum);
					result=gcd_finder(firstnum,secondnum);
					printf("%d\n",result );
					break;
				case 2:
					printf("Enter the length of the list: ");
					scanf("%d",&length_of_list);
					printf("Enter the numbers that you want sorted\n");
					for (i = 0; i < length_of_list; ++i){
						scanf("%d",&unsort_ar[i]);
					}
					mergeANDsort(unsort_ar,0,length_of_list-1);
					for (i = 0; i<length_of_list; ++i){
						printf("%d ",unsort_ar[i]);
					}
	 				
					break;
				case 3:
					printf("Enter number that you want to find F() serial\n");
					scanf("%d",&input);
					di_foo(input);
					break;
				case 4:
					printf("Enter the number that you want to find equal or not\n");
					scanf("%d",&input);	
					count_digit=digit_count(input,count_digit);
					result=equal_or_not(input,count_digit);
					if(result==input)
						printf("Equal\n");
					else
						printf("Not Equal\n");
					break;
				case 5:
					printf("Enter the string to find first CAPITAL letter\n(Please do not leave space between characters)\n");
					scanf("%s",inputchar);
					resultchar=find_capital(inputchar);
					printf("%c\n",resultchar );	 
					break;		
				default:
					printf("Invalid choice.\n");
					break;
			}			
	}				

}
/*--------------------------PART-1-------------------------------*/
int gcd_finder(int firstnum,int secondnum){
	int temp;
/*I used the eucladian algorithm to calculate gcd*/
    if (secondnum != 0){/*It's control condition*/
    	temp=firstnum%secondnum;/*It gets the first num mod according to second num */
    	firstnum=secondnum;/*so basically gcd(A,B)=gcd(B,A-B)*/
    	secondnum=temp ;
       return gcd_finder(firstnum,secondnum);
    }	   	
    else 
       return firstnum;

}
/*--------------------------PART-2--------------------------------*/
/*hocam bu kod icin internetten yararlandim*/
void mergeANDsort(int unsort_ar[],int f_elem, int l_elem){
	if (f_elem < l_elem){ 
		int m_elem = f_elem+(l_elem-f_elem)/2; 
		/*function goingto divede 2 part the array after that its going to sort itand its going to repeat itself */
		mergeANDsort(unsort_ar, f_elem, m_elem); 
		mergeANDsort(unsort_ar, m_elem+1, l_elem); 
		merge(unsort_ar, f_elem, m_elem, l_elem); 
		/*until all array is associated and sorted the fuction calls itself*/
	}
}
void merge(int *unsort_ar,int f_elem,int m_elem,int l_elem){
	int i, j, l; 
	int head_s = m_elem - f_elem + 1; /*first array size*/
	int tail_s =  l_elem - m_elem; /*last array size */
	int FRST[head_s], SCND[tail_s];
	l = f_elem; 
	/*following lines to divide them two parts */
	for (i = 0; i< head_s; i++){ 
		FRST[i] = unsort_ar[f_elem + i];
	}
	for (j = 0; j< tail_s; j++){ 
		SCND[j] = unsort_ar[m_elem + 1+ j];
	}
	i = 0;/*we have to make them zero cause of we used them */
	j = 0; 
	while (i<head_s && j <tail_s){ /*this loop is goingto iterate until the one of them its going to run out of*/
		if (FRST[i] < SCND[j]){ 
			unsort_ar[l] = FRST[i]; 
			i++;
			l++;
			}
			else if (FRST[i]== SCND[j]){
				 unsort_ar[l] =SCND[j];
			i++;
			l++;
			}
			else{
			unsort_ar[l] = SCND[j];
			j++;
			l++;
			}
	}/*ONE OF following loops is going to work cause still one part of array didint copy exactly*/
	while (i< head_s){
		unsort_ar[l] = FRST[i];
		i++;
		l++;
	}
	while (j<tail_s){
		unsort_ar[l] = SCND[j];
		j++; 
		l++;
	}
}

/*--------------------------PART-3--------------------------------*/
void di_foo(int input){
	if(input==1){
		printf("\n");
	}/*this is goingto continue following calculations recursively until the number is equal to 1*/	
	else if(input%2 ==0){//
		printf("%d ",(input/2));
		di_foo(input/2);
	}
	else if(input%2==1){
		printf("%d ",(3*input+1));
		di_foo(3*input+1);
	}
}
/*--------------------------PART-4--------------------------------*/
int digit_count(int input,int count_digit){
	if (input==0){
		return 0;
	}
	else/*It's going to divide ten and assign it to itself until It' going to be zeros*/
		input=input/10;
		count_digit=1+digit_count(input,count_digit);
		return count_digit;
		
}
int equal_or_not(int input,int count_digit){
	int result,base,a;
	if (input==0){
		
		return 0;
	}
	else 
		base=input%10;/*to find pow of each digit we have to get modulus 10 for each digit*/
		input=input/10;
		a=recursive_pow(base,count_digit);
		result=a+equal_or_not(input,count_digit);
		return result;
}/*power function with recursive*/
int recursive_pow(int base, int exponent){
 	if(exponent==0){
		return base=1;
		} 
	else
		base=base*recursive_pow(base,exponent-1);
	return base;
}
/*--------------------------PART-5--------------------------------*/
char find_capital(char *inputchar){
	if((int)*inputchar>=65 && (int)*inputchar<=90)
		return *inputchar;/*int 65 90 express the ppercase letter and if it finds a capital letter it returns it*/
	else if((int)*inputchar>=97 && (int)*inputchar<=122)
		return *inputchar=find_capital((inputchar+1));
	else/*for each time the function called the function determines the next character*/
		printf("CAPITAL letter could not find!!!\n");
	return 0;
}
