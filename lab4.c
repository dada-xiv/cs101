/*
 * CS101 Lab #4 : switch, case
 *
 */

#include <stdio.h>

/* print menu of this restaurant */
void printMenu(){
        printf("\n####### CS Restaurant ##########\n");
        printf (" %s\n %s\n %s\n %s\n %s\n %s\n %s\n",
                "0) Quit",
                "1) Pork cutlet",
                "2) Beef steak",
                "3) Curry rice",
                "4) coffee",
                "5) tea",
                "6) Print Menu");
        printf("################################\n");
}


void main(void){
	int n, price; /*n is the number of the each choice by user */

	printMenu();

	do {

		printf("\nSelect your favorit stuff : ");
		scanf("%d", &n);

		switch(n) {
			case 0 :
				printf("Good Bye..\n");
				break;

			case 1 :
				printf("Good choice. Price 4000won.\n");
				break;

			case 2 :
				printf("Good choice. Price 6000won.\n");
				break;

			case 3 :
				printf("Good choice. Price 3500won.\n");
				break;

			case 4 :
				printf("Good choice. Price 2500won.\n");
				break;

			case 5 :
				printf("Good choice. Price 2000won.\n");
				break;

			case 6 :
				printMenu();
				break;

		default :
			printf("Error : Invalid choice\n");
		}
	}while(n!=0); /* condition for ending */
}