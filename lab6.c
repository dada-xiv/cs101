/*
 * CS101 Lab #6
 *
 * Finding perfect numbers
 *
 */

#include<stdio.h>

/* Defining each given numbers is perfect num or not */
int is_perfect(int num){
	int i, sum=0;

	for(i=1;i!=num;i++){
		//when the num is perfect, adding to sum of factors
		if(num%i==0) sum=sum+i; 
	}

	//the sum of factors equals to the given num, that is perfect
	if(sum==num) return 0;
	else return 1;
}


void main(void){
	int i, def;

	printf("Perfect numbers between 1 and 1000 :\n");

	for(i=2;i<=1000;i++){
		//finding perfect numbers
		def=is_perfect(i);
		
		//printing perfect numbers
		if(def==0) printf(" %4d\n",i);
	}
}
