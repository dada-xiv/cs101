/*
 * CS101 Lab #7 : double array
 *
 */

#include<stdio.h>

void read_data(int a[4][4]){
	int i,j;

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
}

void print_matrix(int a[4][4]){
	int i,j;

	for(i=0;i<4;i++){
		for(j=0;j<4;j++)
			printf("%d  ",a[i][j]);

		printf("\n");
	}
	printf("\n");

}


void matrix_add(int a[4][4], int b[4][4], int c[4][4]){
	int i,j;

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			c[i][j]=a[i][j]+b[i][j];
}

void  matrix_mult(int a[4][4], int b[4][4], int c[4][4]){
	int i,j;

	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j]+a[i][3]*b[3][j];
}


int main(void){
	int a[4][4], b[4][4], c[4][4];

	/* data input */
	read_data(a);
	print_matrix(a);
	read_data(b);
	print_matrix(b);

	/* calculate a + b */
	matrix_add(a, b, c);
	print_matrix(c);

	/* calculate a * b */
	matrix_mult(a, b, c);
	print_matrix(c);
	return 0;
}