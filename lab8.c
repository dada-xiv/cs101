/*
 * CS101 Lab #8 : luckey number
 *
 */

#include<stdio.h>

#define LUCKY_NUMBER 777

void main(void){
	int i=LUCKY_NUMBER;
	int *p=&i;

/* '*p' means pointer and 777 is not an address value, so we must
   change this pointer to direct a kind of address value. And now,
   an integer variable 'i' was used for giving adress value to *p
   and the value of address 'i' is 777. So *p has the value 777.  */

	printf("Is this my lucky number? %d\n",*p);
}

