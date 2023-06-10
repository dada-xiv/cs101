/*
 * CS101 Assignment #2
 *
 * This program calculates given wages to needed composition of units of bills.
 * The user wants to divide given numbers as giving prior to larger units first.
 */

#include<stdio.h>

/* Calculate given number to required composition of units */
int cal(long money){
	int bill=10000, i;  //bill : unit of money
	int b_num;          //b_num : dividend numer of each units

	printf("=====================\n");

	//when the given num is out of range
	if(money > 9999999 || money < 1){
		printf("Error.\nNot permitted range.\n");
		printf("=====================\n");
		return 0;
	}

	for(i=1;i<10;i++){
		b_num=money/bill;

		printf(" %5d : %d\n",bill,b_num);

		//calculate required bills for each units
		money=money%bill;

		if(i%2 != 0) bill=bill/2;
		else bill=bill/5;
	}

	printf("=====================\n");
	return 0;
}



/* Asking for retrying */
int quit(void){
	char cn;

	printf("Again? [Y]/n : ");
	scanf("%c",&cn);

	//condition for ending
	if(cn=='N' || cn=='n') return 0;
	else return 1;
}



void main(void){
	long money;	//given number
	
	//for calling a function that asks about ending
	int again = 1;

	while(again!=0){
		printf("Input : ");
		scanf("%ld",&money);

		printf("\nMoney = %ld\n",money);
	
		//calculates given numbers for each units
		cal(money);

		//asking for retrying
		again = quit();
	}

}