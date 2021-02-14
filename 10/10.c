#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20

typedef struct stack{
	int data;
	struct stack* next; }stack;

typedef struct queue{
	int data;
	struct queue* next; }queue;

typedef struct bst{
	int data;
	struct bst* left, *right; }bst;
	 
void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[SIZE]);
void ordered_print(stack * stack_, queue * queue_, bst * bst_);
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search);
void special_traverse(stack * stack_, queue * queue_, bst * bst_);
void push(stack ** stack_,int data);
void enqueue(queue ** queue_,int data,int i,queue** head);
void create_bst(bst ** bst_,int data);
void sort_stack(stack** stack_);
void sort_queue(queue** q);
void sort_bst(bst * bst);
void put(queue** q, int value);
int pop(stack** stck);
void place(stack** stck, int frame);
int dequeue(queue ** queue);
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search);
int main()
{
	int data[20]={5, 2, 7, 8, 11, 3, 21, 7, 6, 15, 19, 35, 24, 1, 8, 12, 17, 8, 23, 4};
	bst * bst_;
	queue * queue_;
	stack * stack_;
		fill_structures(&stack_, &queue_, &bst_, data);
		ordered_print(stack_, queue_, bst_);
		search(stack_, queue_, bst_, 5);
		special_traverse(stack_, queue_, bst_);
	return 0;
}
void special_traverse(stack * stack_, queue * queue_, bst * bst_){
	sort_queue(&queue_);
	clock_t s,q,b;
	int ar[SIZE];
	int counter=0,i=0;
	q=clock();
	queue *head_q=NULL;
	queue *head_spec_q=NULL;
	head_q=queue_;
	queue *special_q=malloc(sizeof(queue));
	for ( i = 0; i < SIZE; ++i)
	{
		ar[i]=queue_->data;
		queue_=queue_->next;
	}
	head_spec_q=special_q;
	for (i = 0; i < SIZE/2; ++i)
	{
		
		special_q->data=ar[i];
		special_q->next=malloc(sizeof(queue));
		special_q=special_q->next;
		special_q->data=ar[SIZE-i-1];
		special_q->next=malloc(sizeof(queue));
		special_q=special_q->next;



	}
	special_q=head_spec_q;
	printf("\n\n\n");
	while(special_q!=NULL){
		printf("%d->",special_q->data );
		special_q=special_q->next;
	}
	q=clock()-q;
	s=clock();
	stack *head_s=NULL;
	stack *head_spec_s=NULL;
	head_s=stack_;
	stack *special_s=malloc(sizeof(stack));
	head_spec_s=special_s;
	for (i = 0; i < SIZE/2; ++i)
	{
		
		special_s->data=ar[i];
		special_s->next=malloc(sizeof(stack));
		special_s=special_s->next;
		special_s->data=ar[SIZE-i-1];
		special_s->next=malloc(sizeof(stack));
		special_s=special_s->next;



	}
	special_s=head_spec_s;
	printf("\n\n\n");
	while(special_s!=NULL){
		printf("%d->",special_s->data );
		special_s=special_s->next;
	}
	s=clock()-s;
	printf("\nSpecial traverse \n");
	printf("Structures    Stack\t\t\b\b\b\tQueue\t\t\bBST\n");
	printf("Exec. Time    %lf       %lf       %lf(wrong)\n",((double)s)/CLOCKS_PER_SEC,((double)q)/CLOCKS_PER_SEC,((double)b)/CLOCKS_PER_SEC);



	/*int max=-9999999,min=9999999,current;
	stack* helper_stack=NULL;
	stack* head=NULL;
	stack* head_helper_stack=NULL;
	queue* mylist=NULL;
	queue* head_mylist=NULL;
	head_mylist=mylist;
	head=stack_;
	head_helper_stack=helper_stack;
	while(stack_!=NULL){
		while(stack_!=NULL){
			current=pop(&stack_);
			if(current>=max){
					max=current;
			}
			if(current!=max)
				push(&helper_stack,current);
		}
		enqueue(&mylist,max,5,&head_mylist);

		stack_=head;
		while(stack_!=NULL){
			if(current<min){
					min=current;
			}
			push(&helper_stack,current);
			current=pop(&stack_);
		}
		enqueue(&mylist,min,5,&head_mylist);
		helper_stack=head_helper_stack;
		stack_=helper_stack;
	}
	mylist=head_mylist;
	while(mylist!=NULL){
		printf("%d->",mylist->data );
		mylist=mylist->next;
	}*/	
}
void search(stack * stack_, queue * queue_, bst * bst_, int val_to_search){
	int counter=0,list_length=0;
	clock_t s,q,b;
	/////////////////////////////////////////////////////////////////
	s=clock();
	queue* counter_list_q=malloc(sizeof(queue));
	queue* head_q=malloc(sizeof(queue));
	queue* new_q=NULL;
	queue* new_head_q=NULL;
	
	head_q=counter_list_q;
	while(queue_!=NULL){
		if(queue_->data==val_to_search){
			counter_list_q->data=(counter+1);
			counter_list_q->next=malloc(sizeof(queue));
			counter_list_q=counter_list_q->next;
			list_length++;
		}
		enqueue(&new_q,dequeue(&queue_),counter,&new_head_q);
		counter++;
	}
	counter_list_q=head_q;
	printf("\n\n%d result founded on ",list_length );
	while(counter_list_q->next!=NULL){
		printf("%d. step ",counter_list_q->data );
		counter_list_q=counter_list_q->next;
			if (counter_list_q->next!=NULL)
				printf("and ");
	}
	printf("\n");
	s=clock()-s;
	queue_=new_q;
	//////////////////////////////////////////////////////////////////
	q=clock();
	counter=0,list_length=0;
	int ar[SIZE];
	stack* counter_list_s=malloc(sizeof(stack));
	stack* head_s=malloc(sizeof(stack));
	stack* new_s=NULL;
	
	head_s=counter_list_s;
	while(stack_!=NULL){
		if(stack_->data==val_to_search){
			counter_list_s->data=(counter+1);
			counter_list_s->next=malloc(sizeof(stack));
			counter_list_s=counter_list_s->next;
			list_length++;
		}
		
			counter++;
			ar[counter]=pop(&stack_);
	}
	counter_list_s=head_s;
	printf("%d result founded on ",list_length );
	while(counter_list_s->next!=NULL){
		printf("%d. step ",counter_list_s->data );
		counter_list_s=counter_list_s->next;
			if (counter_list_s->next!=NULL)
				printf("and ");
	}
	q=clock()-q;
	for (int l = SIZE; l > 0; --l)
	{
		push(&new_s,ar[l]);
	}
	stack_=new_s;
	//////////////////////////////////////////////////////////////////
	b=clock();
	counter=0,list_length=0;
	queue* counter_list_b=malloc(sizeof(queue));
	queue *head_b=malloc(sizeof(queue));
	head_b=counter_list_b;
	while(bst_!=NULL){
		if(bst_->data==val_to_search){
			counter_list_b->data=(counter+1);
			counter_list_b->next=malloc(sizeof(bst));
			counter_list_b=counter_list_b->next;
			list_length++;
			bst_=bst_->right;
		}
		else if(bst_->data > val_to_search){

			bst_=bst_->left;
		}
		else{
			bst_=bst_->right;
		}
		counter++;
	}
	counter_list_b=head_b;
	printf("\n%d result founded on ",list_length );
	while(counter_list_b->next!=NULL){
		printf("%d. step ",counter_list_b->data );
		counter_list_b=counter_list_b->next;
			if (counter_list_b->next!=NULL)
				printf("and ");
	}
	b=clock()-b;
	//////////////////////////////////////////////////////////////////
	printf("\nSearching \n");
	printf("Structures    Stack\t\t\b\b\bQueue\t\t\b\b\b\bBST\n");
	printf("Exec. Time    %lf       %lf       %lf\n",((double)s)/CLOCKS_PER_SEC,((double)q)/CLOCKS_PER_SEC,((double)b)/CLOCKS_PER_SEC);

}
void fill_structures(stack ** stack_, queue ** queue_, bst ** bst_, int data[20]){	
	(*stack_)=NULL;
	(*queue_)=NULL;
	(*bst_)=NULL;
	queue* head=NULL;
	int counter=0;
	clock_t s,q,b;
	s=clock();
	for (int i = 0; i < SIZE; ++i)
	{
		push(stack_,data[i]);
	}
	s=clock()-s;
	q=clock();
	for (int i = 0; i < SIZE; ++i)
	{
		enqueue(queue_,data[i],i,&head);
	}
	q=clock()-q;
	b=clock();
	for (int i = 0; i < SIZE; ++i)
	{
		create_bst(bst_,data[i]);
	}
	b=clock()-b;
	printf("Filling the lists\n");
	printf("Structures    Stack\t\t\b\b\bQueue\t\t\b\b\b\bBST\n");
	printf("Exec. Time    %lf       %lf       %lf",((double)s)/CLOCKS_PER_SEC,((double)q)/CLOCKS_PER_SEC,((double)b)/CLOCKS_PER_SEC);
}	

void ordered_print(stack * stack_, queue * queue_, bst * bst_){
	stack* top=malloc(sizeof(stack));
	queue* head=malloc(sizeof(queue));
	stack* temp_stop=malloc(sizeof(stack));
	queue* temp_qhead=malloc(sizeof(queue));
	queue* temp_q=malloc(sizeof(queue));
	stack* temp_s=malloc(sizeof(stack));
	temp_qhead=temp_q;
	head=queue_;
	temp_stop=temp_s;
	top=stack_;
	int deneme;	
	clock_t s,q,b;

		while(stack_!=NULL){
			temp_s->data=pop(&stack_);
			if (stack_!=NULL)
			{
				temp_s->next=malloc(sizeof(stack));
			}			
				temp_s=temp_s->next;


		}
	stack_=top;
	temp_s=temp_stop;
		while(queue_!=NULL){
			temp_q->data=dequeue(&queue_);
			if (queue_!=NULL)
			{
				temp_q->next=malloc(sizeof(queue));
			}			
				temp_q=temp_q->next;


		}
	queue_=head;
	temp_q=temp_qhead;
	
	s=clock();
	sort_stack(&temp_s);
	s=clock()-s;
	deneme=dequeue(&queue_);
	printf("\n");
	q=clock();
	sort_queue(&temp_q);
	q=clock()-q;
	printf("\n");
	while(temp_qhead!=NULL){
		printf("%d-",temp_qhead->data );
		temp_qhead=temp_qhead->next;
	}
	printf("\n");
	b=clock();
	sort_bst(bst_);
	b=clock()-b;
	printf("\n");
	printf("Sorting the lists\n");
	printf("Structures    Stack\t\t\b\b\bQueue\t\t\b\b\b\bBST\n");
	printf("Exec. Time    %lf       %lf       %lf",((double)s)/CLOCKS_PER_SEC,((double)q)/CLOCKS_PER_SEC,((double)b)/CLOCKS_PER_SEC);

}
void sort_bst(bst * bst){
	if (bst==  NULL)
		return;
	sort_bst(bst->right);
	printf("%d-",bst->data );
	sort_bst(bst->left);
}
void sort_queue(queue** q){
	int max,second,swap,small_one,big_one;
	int counter=0,j;
	queue* q1=malloc(sizeof(queue));
	queue* head_t_q=malloc(sizeof(queue));
	queue* t_q=malloc(sizeof(queue));
	q1=(*q);
	t_q=q1;
	head_t_q=t_q;
	queue temp;
	printf("\n");
	for (j = 0; j < SIZE; ++j)
	{ 
	t_q=head_t_q;
		while(t_q!=NULL){
			if (t_q->next && t_q->data <= t_q->next->data)
			{
				temp.data=t_q->data;
				
				t_q->data=t_q->next->data;
					
				t_q->next->data=temp.data;

			}
			t_q=t_q->next;
		}
		
	}
	t_q=head_t_q;
	while(t_q!=NULL){
		printf("%d-",t_q->data );
		t_q=t_q->next;
		
	}




/*
	if(*q!=NULL){
		int val=dequeue(q);
		sort_queue(q);
		put(q,val);

	}


		while((*q)!=NULL){
			if (counter==0)
			{
				small_one=dequeue(q);
				big_one=dequeue(q);
			}

			if (small_one<=big_one)
			{
				t_q->data=big_one;
				printf("data %d____smallone%d_________bigone%d_________counter:%d\n",t_q->data,small_one,big_one,counter );
				t_q->next=malloc(sizeof(queue));
				t_q=t_q->next;
				big_one=dequeue(q);
			}
			else if (big_one<small_one)
			{
				swap=big_one;
				big_one=small_one;
				small_one=swap;
				
				t_q->data=big_one;
				printf("data %d____smallone%d_________bigone%d_________counter:%d\n",t_q->data,small_one,big_one,counter );
				
				t_q->next=malloc(sizeof(queue));
				t_q=t_q->next;
				big_one=dequeue(q);
				
			}
			counter++;
		(*q)=(*q)->next;
		//t_q->data=small_one;
				printf("data %d____smallone%d_________bigone%d_________counter:%d\n",t_q->data,small_one,big_one,counter );
				
		//t_q->next=malloc(sizeof(queue));
		//t_q=t_q->next;		
		small_one=dequeue(q);
				printf("sssdata %d_______counter:%d\n",small_one,counter );
				printf("bbbdata %d_______counter:%d\n",big_one,counter );
	while(head_t_q!=NULL){
		printf("%d\n",head_t_q->data );
		head_t_q=head_t_q->next;
	}
		if ((*q)!=NULL)
			(*q)=(*q)->next;		
		}	
		*/
	
	


}
void put(queue** q, int value){
	if((*q)!=NULL){
		int front_of_queue=(*q)->data;
		if(value<front_of_queue){
			dequeue(q);
			put(q,value);
			(*q)->data=front_of_queue;
			(*q)->next=malloc(sizeof(queue));
			(*q)=(*q)->next;
		}
		else{
			(*q)->data=value;
			if ((*q)!=NULL)
			{
				(*q)->next=malloc(sizeof(queue));
				(*q)=(*q)->next;
			}
		}	
	}
	else{
		if ((*q)!=NULL)
		{
			(*q)->data=value;
			(*q)->next=malloc(sizeof(queue));
			(*q)=(*q)->next;
		}
	}	
}
int dequeue(queue ** queue){
	int x;
	if ((*queue)!=NULL)
	{	
		x=(*queue)->data;
		(*queue)=(*queue)->next;
	}


	return x;
}
void sort_stack(stack** stck){
	if(*stck!=NULL){
		int frame=pop(stck);
		sort_stack(stck);
		place(stck,frame);

	}

}
void place(stack** stck, int frame){
	if ((*stck)!=NULL)
	{
		int top_of_stack=(*stck)->data;
		if(frame < top_of_stack){
			pop(stck);
			place(stck,frame);
			push(stck,top_of_stack);
		}
		else
			push(stck,frame);

	}
	else
		push(stck,frame);
}
int pop(stack** stck){
	int willdelete;
	if ((*stck)==NULL){
		printf("Stack is empty!!\n");
		return -1;
	}
	else
		willdelete=(*stck)->data;
		(*stck)=(*stck)->next;
		return willdelete;

}
void push(stack ** stack1,int data){
	stack * temp;
	if((*stack1)==NULL)
	{
		(*stack1)=malloc(sizeof(stack));
		(*stack1)->data=data;
	}
	else{
		stack* temp=malloc(sizeof(stack));
		temp->data=data;
		temp->next=malloc(sizeof(stack));
		temp->next= (*stack1);
		(*stack1)=temp;

	}

}
void enqueue(queue ** queue1,int data,int i,queue** head){
	if ((*queue1)==NULL)
	{
		(*queue1)=malloc(sizeof(queue));
		(*queue1)->data=data;
		(*head)=malloc(sizeof(queue));
		(*head)=(*queue1);
	}
	else if(i==SIZE-1){
		(*queue1)->next=malloc(sizeof(queue));
		(*queue1)=(*queue1)->next;
		(*queue1)->data=data;
		(*queue1)=(*head);
	}
	else{
		(*queue1)->next=malloc(sizeof(queue));
		(*queue1)=(*queue1)->next;
		(*queue1)->data=data;
	}

	

}
void create_bst(bst ** bst1,int data){	
	if ((*bst1)==NULL)	{
		(*bst1)=(bst *)malloc(sizeof(bst));
		(*bst1)->data=data;
		(*bst1)->right=(*bst1)->left=NULL;
		return ;
	}
	else if (data>=(*bst1)->data)
	{
		create_bst(&((*bst1)->right),data);
	}
	else
	{
		create_bst(&((*bst1)->left),data);
	}

}

