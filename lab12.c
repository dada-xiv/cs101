/*
 * CS101 Lab #12 : Queue
 *
 * Rearrangement when 'tail' is located at the end of queue array
 *
 */

#include<stdio.h>

#define QUEUE_SIZE 6

/* To insert an element at the end of queue */
void insertq(int *head,int *tail,int queue[])
{
	int num,length,i;

	length=*tail-*head+1;

	if(length==QUEUE_SIZE){		
		printf("Queue is Overflow!! [Max:%d]\n", QUEUE_SIZE);
	}else {
		printf("Enter an integer : ");
		scanf("%d", &num);
		fflush(stdin);

		/* when tail is not the end of array */
		if(*tail!=QUEUE_SIZE-1){

			/* if head is larger than tail, queue is underflow */
			if(*head>*tail){

				queue[*head]=num;
				queue[++(*tail)]=num;
			}
			else queue[++(*tail)]=num;
		}else if(length<QUEUE_SIZE){
		/* pulling the queue in queue[QUEUE_SIZE] */
			for(i=0;i<=length;i++){
				queue[i]=queue[*head];
				(*head)++;
			}

			*head=0;
			*tail=*head+length;  /* for new elt, -1 is not added */
			queue[*tail]=num;    /* new element */
		}
	}

}


/* To delete the first element of queue */
void deleteq(int *head,int *tail,int queue[]){
	if(*head<=*tail){
		printf("The deleted value is %d\n",queue[*head]);
		(*head)++;
	}
	else printf("Queue is Underflow!!\n");
}


/* Printing queue array from head to tail */
void printq(int head,int tail,int queue[]){
	int i;

	for(i=head;i<=tail;i++)
		printf("%d ", queue[i]);
	printf("\n");
}



void main(void){
	int queue[QUEUE_SIZE];
	int head=0, tail=-1, item;

	printf("Enter choice :  1) Insert a value in the queue.\n");
	printf("                2) Delete a value from the queue.\n");
	printf("                else) exit.\n");

	do{
		printf("\n>>Choice : ");
		scanf("%d", &item);
		fflush(stdin);

		switch(item) {

			case 1 :
				insertq(&head, &tail, queue);
				printq(head, tail, queue);
				break;

			case 2 :
				deleteq(&head, &tail, queue);
				printq(head, tail, queue);
				break;

			default :
				printf("End of run!!\n");
				break;
			}

	}while(item==1 || item==2);

}
