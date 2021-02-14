#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person{
  char name[20];
  char surname[20];
  char musical_Work[20];
   int age;
 
struct person *next;

} *top;
void addNode(char name[20], char surname [20], char creation [20], int age);
void deleteNode();
void Sort_Alphabetically(struct person* tmp2);
void Sort_Increasingly(struct person* tmp2);
void menu();
void print_stack();
int main(){
	menu();
	return 0;
}

void menu(){
	int choice=0;
	char name[20],surname [20],creation [20];
	int age;
		while(choice!=5){
			printf("****MENU****\n"
				"\t1- Add a Person to the Stack\n"
				"\t2- Pop a Person from the Stack\n"
				"\t3- Sort Alphabetical Order\n"
				"\t4- Sort Age in Increasing Order\n"
				"\t5- Exit menu\n"
				"*************\n");
			printf("\nSelect your Choise: ");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					printf("\nName: ");
					scanf(" %[^\n]s",name);
					printf("Surname: ");
					scanf(" %[^\n]s",surname);
					printf("Creation: ");
					scanf(" %[^\n]s",creation);
					printf("Age: ");
					scanf(" %d",&age);
					addNode(name,surname,creation,age);
					printf("\n\n\n");
					print_stack();
					break;
				case 2:
					deleteNode();
					print_stack();
					break;
				case 3:
					Sort_Alphabetically(top);
					print_stack();
					break;
				case 4:
					Sort_Increasingly(top);
					print_stack();
					break;
				case 5:
					printf("Exitting...\n");
					break;		
				default:
					printf("Choice a valid choice \n");
					break;	
			}
		}
}
/*push function*/
void addNode(char name[20], char surname [20], char creation [20], int age){
	int i=0;
	if(top==NULL){
		top=(struct person*)malloc(sizeof(struct person));
		for (i = 0; i < 20; ++i){/*I declared 20 for array size so the for loops copy the elemenths of arrays*/
			top->name[i]     =name[i];
			top->surname[i]  =surname[i];
			top->musical_Work[i] =creation[i];
		
		}
		top->age =age;
		
	}
	else{
		struct person* tmp=(struct person*)malloc(sizeof(struct person));
		for (i = 0; i < 20; ++i){
			tmp->name[i]     =name[i];
			tmp->surname[i]  =surname[i];
			tmp->musical_Work[i] =creation[i];
		
		}
		tmp->age      =age;
		tmp->next=(struct person*)malloc(sizeof(struct person));
		tmp->next=top;
		top=tmp;

	}
}
/*I used buble sort to sort increasingly*/
void Sort_Increasingly(struct person* tmp2){
	struct person* check=(struct person*)malloc(sizeof(struct person));
	struct person* count2=(struct person*)malloc(sizeof(struct person));
	struct person* head=(struct person*)malloc(sizeof(struct person));
	struct person temp_struct;
	int n=0,i=0,j=j;
	count2= tmp2;
	head= tmp2;
	check=tmp2;
	top=check;
	while(count2){
		count2=count2->next;
		n=n+1;

	}/*I need to know how many data are there in the linked list so the n keeps the count of datas*/
	for (j = 0; j < n; ++j)
	{ 
	check=head;/*for each loop the check goes to the end so we have to bring it back to head of linked list*/
		while(check!=NULL){
			if (check->next && check->age > check->next->age)
			{
				/*following four loops necessary to swap operation*/
				for (i = 0; i < 20; ++i)/*This for loop necessary to copy elemenths of darray */
				{
					temp_struct.name[i] =check->name[i];
					temp_struct.surname[i] =check->surname[i];
					temp_struct.musical_Work[i] =check->musical_Work[i];
						
				}
				temp_struct.age=check->age;
				for (i = 0; i < 20; ++i)
				{
					check->name[i]=check->next->name[i];
					check->surname[i]=check->next->surname[i];
					check->musical_Work[i]=check->next->musical_Work[i];			
				}
				check->age=check->next->age;
				for (i = 0; i < 20; ++i)
				{
					check->next->name[i]=temp_struct.name[i];
					check->next->surname[i]=temp_struct.surname[i];
					check->next->musical_Work[i]=temp_struct.musical_Work[i];			
				}
				check->next->age=temp_struct.age;

			}
			check=check->next;
		}
		
	}
}
void Sort_Alphabetically(struct person* tmp2){
	struct person* check=(struct person*)malloc(sizeof(struct person));
	struct person* count2=(struct person*)malloc(sizeof(struct person));
	struct person temp_struct;
	int n=0,i=0,j=0;
	count2= tmp2;
	check=tmp2;
	top=check;
	while(count2){
		count2=count2->next;
		n=n+1;

	}
	for (j = 0; j < n; ++j)
	{ 
	check=tmp2;
		while(check!=NULL){
			if (check->next && strcmp(check->name,check->next->name)>0)/*Its almost same with the sorting ages but we check the characters of the name*/
			{
				for (i = 0; i < 20; ++i)
				{
					temp_struct.name[i] =check->name[i];
					temp_struct.surname[i] =check->surname[i];
					temp_struct.musical_Work[i] =check->musical_Work[i];
						
				}
				temp_struct.age=check->age;
				for (i = 0; i < 20; ++i)
				{
					check->name[i]=check->next->name[i];
					check->surname[i]=check->next->surname[i];
					check->musical_Work[i]=check->next->musical_Work[i];			
				}
				check->age=check->next->age;
				for (i = 0; i < 20; ++i)
				{
					check->next->name[i]=temp_struct.name[i];
					check->next->surname[i]=temp_struct.surname[i];
					check->next->musical_Work[i]=temp_struct.musical_Work[i];			
				}
				check->next->age=temp_struct.age;

			}
			check=check->next;
			
		}
		
	}
}
/*pop function*/
void deleteNode(){
	if(top==NULL){/*if the stack is empty and you want to pop a node from stack*/
		printf("Stack is empty\n");
		return ;
	}
	else{
		struct person* will_delete=(struct person*)malloc(sizeof(struct person));
		will_delete=top;/*I have to keep it in another node to free it*/
		top=top->next;
		free(will_delete);

	}
}
/*to print my stack*/
void print_stack(){/*print function for each calling it is going to print the stack from head of stack*/
	struct person *head = top;
	int i=1;
	while(head!= NULL){
		printf("%d) %s\n",i,head->name );
		printf("%s\n",head->surname );
		printf("%s\n",head->musical_Work );
		printf("%d\n",head->age );
		head = head->next;
		i++;
	}

}
