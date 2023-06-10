/*
 * CS101 Assignment #5 : Library Management
 *
 * This is a simple program for managing a library. 
 * The list of books is rearranged using a bubble sorting method.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct book{
	char id[20];
	char title[20];
	char author[20];
	int available;
	struct book *next;
}book;


void print_menu(void){
	printf(":::::: Library ::::::\n");
	printf("1) Input new book\n");
	printf("2) Remove old book\n");
	printf("3) Lend available book\n");
	printf("4) Return book\n");
	printf("5) Sort a list (ID)\n");
	printf("6) Print a list\n");
	printf("7) Main Menu\n");
	printf("8) Quit\n\n");
}


/* Command prompt for numbers between 1~8 */
int choice(void){
	int num;

	printf("Select>> ");
	scanf("%d",&num);

	return num;
}


/* If user's input id exists in the list, return 1 */
int exist_id(book *head,char id[]){
	book *h=head;

	while(h!=NULL) {
		if(strcmp(h->id,id)==0) return 1;
		h=h->next;
	}
	return 0;
}


/* Input a new book */
void input_list(book **head,book **tail){
	char item;
	book *temp;

	temp=(book *)malloc(sizeof(book));

	printf("<<Input New book>>\n");
	printf("ID : ");
	gets(temp->id);

	/* when the user inputs nothig */
	if(strlen(temp->id)==0) item='n';

	else if(exist_id(*head,temp->id)==1) {
		item='n';
		printf("The same ID already exists. ");
	}else{
		printf("Title : ");
		gets(temp->title);

		if(strlen(temp->title)!=0){
			printf("Author : ");
			gets(temp->author);

			if(strlen(temp->author)!=0) {
				printf("Is this correct? [Y/n] : ");
				scanf("%c",&item);
			}
			else item='n';
		}
		else item='n';
	}

	/* Input new node to linked list */
	if(item!='N' && item!='n'){  

		/* when the list is not empty */
		if(*tail!=NULL) (*tail)->next=temp;
		/* when the list is empty */
		if(*head==NULL) *head=temp;

		/* basic process for inserting new node */
		*tail=temp;
		(*tail)->next=NULL;

		(*tail)->available=1;

		printf("New book inserted sucessfully!!\n\n");
	}
	else {
		free(temp);
		printf("Input failed..\n\n");
	}
}


/* Counts the number of nodes of linked list */
int count(book *h){
	int num=0;
	book *temp=h;

	while(temp!=NULL){
		temp=temp->next;
		num++;
	}
	return num;
}


/* Deleting a book of given TITLE and ID by user */
void remove_list(book **head,book **tail){
	char key[20],item;

	/* 'prev' for searching locate of a node */
	book *temp=*head,*prev=NULL;

	if(count(*head)==0){
		printf("There are no book..\n\n");
		return;
	}

	printf("<<Remove old book>>\n");
	printf("ID: ");
	gets(key);

	/* when user inputs nothing */
	if(strlen(key)==0){
		printf("Remove failed..\n\n"); return; }

	if(exist_id(*head,key)==1){
		/* searching for a special locate of the node by ID */
		while(temp!=NULL){
			if(strcmp(temp->id,key)==0) break;
			prev=temp;
			temp=temp->next;
		}

		printf("[%s, %s, %s]\nAre you sure that you want to remove it?(Y/n) :"
					,temp->id,temp->title,temp->author);
		scanf("%c",&item);
		//fflush(stdin);

		if(item!='n' && item!='N'){
			if(temp!=*head) prev->next=temp->next;

			/* removing head */
			else if(temp->next!=NULL) *head=temp->next;    
			/* when head is the only one node */
			else *head=NULL;

			/* removing last node */
			if(temp==*tail) *tail=prev;

			printf("[%s, %s, %s] Removed successfully!!\n\n"
					,temp->id,temp->title,temp->author);
			free(temp);
		}else{
			printf("Remove failed..\n\n"); return;
		}
	}
	else printf("Sorry, There is no book for %s..\n\n",key);
}


/* Counting the number of the book that has the same title with user's TITLE */
int count_same_title(book *head,char title[]){
	book *h=head;
	int num=0;

	while(h!=NULL){
		if(strcmp(h->title,title)==0) num++;
		h=h->next;
	}
	return num;
}


/* 
 * Counting the number of books.
 * If the mode is '1', counts the available books for lending.
 * If the mode is '0', counts the books which is lent.
 */
int count_available(book *head,int mode){
	book *h=head;
	int num=0;

	while(h!=NULL){
		if(h->available==mode) num++;
		h=h->next;
	}
	return num;
}


/* Counting the number of books that has the same title and is available */
int count_title_available(book *head,char title[]){
	book *h=head;
	int num=0;

	while(h!=NULL){
		if(strcmp(h->title,title)==0 && h->available==1) num++;
		h=h->next;
	}
	return num;
}


/* Printing available books for lending that have same title */
void print_available(book *head,char title[]){
	book *temp=head;

	printf("-------------------- ------------------- -------------------\n");
	printf("        Available ID               Title              Author\n");
	printf("-------------------- ------------------- -------------------\n");
	while(temp!=NULL) {
		if(strcmp(temp->title,title)==0 && temp->available==1)
			printf("%20s%20s%20s\n",temp->id,title,temp->author);
		temp=temp->next;
	}
	printf("------------------------------------------------------------\n");
}


/*
 * If the mode is '0', change 'available' to '0'(book is lent)
 * If the mode is '1', change 'available' to '1'(book is returned)
 */
void change_available(book *head,char id[],int mode){
	book *temp=head;

	/* searching the special location in linked-list */
	while(temp!=NULL){
		if(strcmp(temp->id,id)==0) {
			temp->available=mode;
			break;
		}
		temp=temp->next;
	}

	if(mode==0)
		printf("[%s, %s, %s] lent successfully!!\n\n",
		temp->id,temp->title,temp->author);
	else if(mode==1)
		printf("[%s, %s, %s] returned successfully!!\n\n",
		temp->id,temp->title,temp->author);
}


/* To find the location of the book that has given title and change 'available' */
void find_location(book *head,char title[]){
	book *temp=head;

	while(temp!=NULL){
		if(strcmp(temp->title,title)==0) break;
		temp=temp->next;
	}
	
	if(temp->available==0){
		printf("%s is lent..\n\n",title);
		return;
	}
	else change_available(head,temp->id,0);
}


/* To get the book's ID when the other books have the same title are all lent */
char* get_id(book *head,char title[]){
	book *h=head;

	while(h!=NULL) {
		if(h->available==1 && strcmp(h->title,title)==0) return h->id;
		h=h->next;
	}
	
	printf("%s\n",h->title);
	return NULL;
}



/*
 * Lending a book that has the given title and if there exists many books have the
 * same title, gets a special ID by user.
 */
void lend_book(book **head){
	int num,a_num;
	char title[20],*id;
	book *temp=*head;

	a_num=count_available(*head,1);

	if(count(*head)==0 || a_num==0){
		printf("There is no available book to lend..\n\n"); return;
	}

	printf("<<Lend available book>>\n");
	printf("Title : ");
	gets(title);

	/* when user inputs nothing */
	if(strlen(title)==0){
		printf("Failed..\n\n"); return; }

	num=count_same_title(*head,title);

	if(num==0){
		printf("Sorry, There is no book of TITLE : %s..\n\n",title);
	}else if(num==1){
		find_location(temp,title);
		return;
	}else if(num!=1){
		a_num=count_title_available(*head,title);

		/* if there are many books of the same title and available for lending */
		if(a_num>1){
			print_available(*head,title);
			printf("Select ID : ");
			gets(id);

			change_available(*head,id,0);
			return;
		}
		else if(a_num==1){
			change_available(temp,get_id(temp,title),0);
		}

		/* ..many books of the same title but available for lending is just one */
	}
}



/* Finding the book of given ID, and if it is lent, returns '1' */
int is_lent(book *head,char id[]){
	book *temp=head;

	while(temp!=NULL){
		if(strcmp(temp->id,id)==0) break;
		temp=temp->next;
	}

	if(temp->available==0) return 1;
	else return 0;
}


/* Returning a book */
void return_book(book **head){
	char id[20];

	if(count(*head)==0 || count_available(*head,0)==0){
		printf("There are no book to return..\n\n");
		return;
	}

	printf("<<Return book>>\n");
	printf("ID: ");
	gets(id);

	/* when user inputs nothing */
	if(strlen(id)==0){      
		printf("Failed..\n\n"); return; }

	if(is_lent(*head,id)==0){
		printf("The book is not lent..\n\n");
		return;
	}

	if(exist_id(*head,id)==0)
		printf("Sorry, There is no book for ID : %s.\n",id);

	else change_available(*head,id,1);  /* retuning the book */
}


/* Printing the one structure(node) of books that have the given ID */
void print_row(book *head,char id[]){
	book *temp=head;

	/* searching the location for the ID */
	while(temp!=NULL){
		if(strcmp(temp->id,id)==0) break;
		temp=temp->next;
	}

	printf("%20s",temp->id);
	printf("%20s",temp->title);
	printf("%20s",temp->author);
	if(temp->available==1) printf("%14s","true");
	else printf("%14s","false");
	printf("\n");
}



/* Sorting a linked-list by ascending order */
void sort_list(book *head){
	char **a,*tmp;
	int i,j,num;
	book *temp;

	num=count(head);
	temp=head;

	/* for temporary array */
	a=(char **)calloc(num,sizeof(char*));

	/* Making an array of ID from the list */
	for(i=0;temp!=NULL;i++){
		*(a+i)=temp->id;
		temp=temp->next;
	}

	/* Bubble Sorting */
	for(i=num;i>=0;i--)
		for(j=1;j<i;j++)
			if( strcmp(*(a+j-1),*(a+j)) > 0 ){
				/* Swapping */
				tmp=*(a+j-1);
				*(a+j-1)=*(a+j);
				*(a+j)=tmp;
			}
	
	printf("-------------------- ------------------- ------------------- -------------\n");
	printf("(Sorted)          ID               Title              Author     Available\n");
	printf("-------------------- ------------------- ------------------- -------------\n");

	for(i=0;i<num;i++)
		print_row(head,*(a+i));

	printf("\n");

	free(a);
}


/* Printing the given list */
void print_list(book *head){
	book *h=head;

	printf("-------------------- ------------------- ------------------- -------------\n");
	printf("                  ID               Title              Author     Available\n");
	printf("-------------------- ------------------- ------------------- -------------\n");

	while(h!=NULL){
		printf("%20s",h->id);
		printf("%20s",h->title);
		printf("%20s",h->author);
		if(h->available==1)
			printf("%14s","true");
		else printf("%14s","false");
		printf("\n");

		h=h->next;
	}
	printf("\n");
}


/* Free memory of the given list */
void free_list(book *head){
	book *current=head, *next_node;

	while(current!=NULL){
		next_node=current->next;
		free(current);
		current=next_node;
	}
}


/* Reding a node from a data file of linked-list */
void read_node(book **head,book **tail,book *temp){
	//basic type
	if(*tail!=NULL) (*tail)->next=temp; 

	//when the first node is liked
	if(*head==NULL) *head=temp;

	*tail=temp;
	(*tail)->next=NULL;
}


/* Reding a linked-list from a data file */
void read_file(book **head,book **tail){
	book *temp;
	FILE *fp;

	fp = fopen("asn5.dat","rb");

	if(fp==NULL){
		fclose(fp);
		return;
	}

	do{
		temp=(book *)malloc(sizeof(book));
		if(fread(temp,sizeof(book),1,fp)!=1) break;
		read_node(head,tail,temp);
	}while(1);

	fclose(fp);
}


/* Writing the liked-list to a file */
void write_file(book *head){
	FILE *fp;
	book *temp=head;
	fp=fopen("asn5.dat","wb");

	while(temp!=NULL) {
		fwrite(temp,sizeof(book),1,fp);
		temp=temp->next;
	}
	fclose(fp);
}



void main(void){
	int num;
	book *head=NULL,*tail;

	print_menu();

	read_file(&head,&tail);
	do{
		num=choice();
		switch(num) {
			case 1 :
				input_list(&head,&tail);
				break;
			case 2 :
				remove_list(&head,&tail);
				break;
			case 3 :
				lend_book(&head);
				break;
			case 4 :
				return_book(&head);
				break;
			case 5 :
				sort_list(head);
				break;
			case 6 :
				print_list(head);
				break;
			case 7 :
				print_menu();
				break;
			case 8 :
				write_file(head);
				free_list(head);
				break;
			default :
				printf("Error : Input num between 1 and 8.\n");
				break;
		}
	}while(num!=8);

	printf("[End of Program, 'getchar()' included]\n");
	getchar();
}