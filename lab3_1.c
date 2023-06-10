/*
 * CS101 Lab #3-1
 *
 * Take minutes and seconds, and converts the summation into seconds.
 *
 */

#include <stdio.h>

void main(void){
	int min,sec,sum;

	printf("\n#input minute(s):");
	scanf("%d",&min);
	printf("#input second(s):");
	scanf("%d",&sec);

	sum = min * 60 + sec;
	printf("\n#Total %dsecond(s).",sum);
}
