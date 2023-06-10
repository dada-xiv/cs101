/*
 * CS101 Lab #10 : pointer and array
 *
 */
 
#include<stdio.h>

void swap(int *x,int *y){
	int temp;

	temp=*x;
	*x=*y;
	*y=temp;
}

void main(void){
	int a[10]={3,12,9,7,6,14,1,11,5,10};
	int i, j, temp;

	printf("STEP 0 : ");
	for(i=0;i<10;i++)
		printf("%2d  ",a[i]);
	printf("\n");

	for(i=1;i<10;i++)
	{
		for(j=i;a[j]<a[j-1];j--)
			if (j!=0) swap(&a[j],&a[j-1]);
			//when j=0, j-1=-1 so we must not swap

		printf("STEP %d : ",i);
		for(j=0;j<i+1;j++)
			printf("%2d  ",a[j]);
		printf("\n");
	}
}