/*
 * CS101 Lab #5
 *
 * Guess the number generated by computer
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* define whether the user num is between 1 and 100 */
int domain (int d_num){
	if( 1 <= d_num && d_num <= 100) return 0;
	// when the number is out of permitted range
	else return 1;
}

void main (void){
	int n, u_num, cnt=1, def;

	/* variable declarations

	n : generated num,
	u_num : user num,
	cnt : counting trial numbers,
	def : define permitted range */

	srand(time(NULL));

	// making the number
	n = (rand()%100)+1;

	printf("I am thinking a number between 1 and 100.\n");

	for(;;cnt++) {

		printf("Guess a number : ");
		scanf("%d",&u_num);

		def = domain(u_num);	// defining whether the user num is in the permitted range

		if(def == 1){
			printf("You gave up in turn %d.\n",cnt);
			break;
		}

		if(u_num == n){
			printf("Right! You got right answer in turn %d.\n",cnt);
			break;
		}

		if(u_num > n){
			printf("%d is too big.\n",u_num);
			continue;
		}

		if(u_num < n){
			printf("%d is too small.\n",u_num);
			continue;
		}
	}
}