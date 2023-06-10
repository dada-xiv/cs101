/*
 * CS101 Lab #3-2
 *
 * Take two numbers and performs addition, multiplication, subtraction, and division.
 *
 */
 
#include <stdio.h>

void main(void){
	float i,j,a,b,c,d;

	printf("Number_1 : ");
	scanf("%f",&i);
	printf("Number_2 : ");
	scanf("%f",&j);

	a=i+j;
	b=i-j;
	c=i*j;
	d=i/j;

	printf("summation is %.2f,\n",a);
	printf("subtraction is %.2f,\n", b);
	printf("multiplication is %.2f,\n", c);
	printf("division is %.2f.", d);
}
