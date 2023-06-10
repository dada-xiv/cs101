/*
 * CS101 Assignment #4 : Matrix Calculator
 *
 * This program carries out basic matrix caculations.
 */

#include <stdio.h>
#include <stdlib.h>

/* Printing menu */
void print_menu(void){
	printf(":::::: M E N U ::::::\n");
	printf("1. Input\n");
	printf("2. Addition\n");
	printf("3. Substraction\n");
	printf("4. Multiplication\n");
	printf("5. Print Menu\n");
	printf("6. Quit\n");
	printf("---------------------\n");
}


/* Printing given 2dimentional pointer to matrix */
void print_matrix(int **matrix,int n){
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%5d ",*(*(matrix+i)+j));
		printf("\n");
	}
	printf("\n");
}


/* Getting two matrices */
void input(int **a,int **b,int n){
	int i,j;

	printf("Input Matrix A : ");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",*(a+i)+j);
	fflush(stdin);   //For excess input error
	print_matrix(a,n);

	printf("Input Matrix B : ");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",*(b+i)+j);
	fflush(stdin);
	print_matrix(b,n);
}


/* Adding two matrices */
void add(int **a,int **b,int **c,int n){
	int i,j;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			*(*(c+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
	printf("::: A + B :::\n");
	print_matrix(c,n);
}


/* Subtrating two matrices */
void subt(int **a,int **b,int **c,int n){
	int i,j;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			*(*(c+i)+j)=*(*(a+i)+j)-*(*(b+i)+j);
	printf("::: A - B :::\n");
	print_matrix(c,n);
}


/* Multiplying two matrices */
void multi(int **a,int **b,int **c,int n){
	int i,j,k;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			//Initializing for adding
			*(*(c+i)+j)=0;
			for(k=0;k<n;k++)
				*(*(c+i)+j)=
                        *(*(c+i)+j)+*(*(a+i)+k)**(*(b+k)+j);
		}
	printf("::: A * B :::\n");
	print_matrix(c,n);
}


/* Free memory */
void free_memory(int **a,int **b,int **c,int n){
	int i;

	//First, free memories of elts in one row
	for(i=0 ; i<n ; i++)
		free(*(a+i));
	//Second, free memories of each pointers of row
	free(a);

	for(i=0 ; i<n ; i++)
		free(*(b+i));
	free(b);

	for(i=0 ; i<n ; i++)
		free(*(c+i));
	free(c);
}


void main(void){
	int **a,**b,**c,item,size=0,i;
	/* To prevent errors such as calling other functions first than input(),
	the program initializes matrix size to 0.  */

	print_menu();

	do{
		printf("Select : ");
		scanf("%d",&item);

		switch(item) {
			case 1 :
				printf("Input size : ");
				scanf("%d",&size);
				fflush(stdin);
				if(size<=0) {
					size=0;
					printf("Error! Input a natual number.\n");
					break;
				}

				/* Below sentences for memory allocations */
				a=(int **)malloc(size*sizeof(int *));
				for(i=0 ; i<size ; i++)
					*(a+i)=(int *)malloc(size*sizeof(int));

				b=(int **)malloc(size*sizeof(int *));
				for(i=0 ; i<size ; i++)
					*(b+i)=(int *)malloc(size*sizeof(int));

				c=(int **)malloc(size*sizeof(int *));
				for(i=0 ; i<size ; i++)
					*(c+i)=(int *)malloc(size*sizeof(int));

				input(a,b,size);
				break;

			case 2 :
				if(size!=0) add(a,b,c,size);
				else printf("Error! Input first..\n");
				break;

			case 3 :
				if(size!=0) subt(a,b,c,size);
				else printf("Error! Input first..\n");
				break;

			case 4 :
				if(size!=0) multi(a,b,c,size);
				else printf("Error! Input first..\n");
				break;

			case 5 :
				print_menu();
				break;

			case 6 :
				//When the user choice 6 first
				if(size==0){
					break;
				}else{
					free_memory(a,b,c,size);
					break;
				}

			default : printf("Error!\n"); break;

		}
	}while(item!=6);

	//getchar();
	//getchar();
}
