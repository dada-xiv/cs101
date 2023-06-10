/*
 * CS101 Lab #9
 *
 * Implemens some special string functions
 *
 */

#include <stdio.h>
#include <string.h>

// Defining the maximum string length
#define MAX 100


/* Calculating the length of a given string */
int mystrlen(char *string){
	int i;
	//To stop adding at NULL character
	for(i=0;string[i]!='\0';i++){}
	return i;
}


/* Copying given string to a new string */
char* mystrcpy(char *dest,char *source){
	int i;

	for(i=0;source[i]!='\0';i++)
		dest[i] = source[i];

	// At the end of the string
	dest[i]='\0';

	return dest;
}


/* Adding an additional string to the original string */
char* mystrcat(char *add,char *source){
	int i,j,k,m=0;

	i=mystrlen(source);
	j=mystrlen(add);

	// Generating additional length
	for(k=i;add[m]!='\0';k++){
		source[k]=add[m];
		m++;
	}

	// At the end of the string
	source[i+j]='\0';

	return source;
}


/* To determe two given strings are same or not */
int mystrcmp(char *s1,char *s2){
	int i,j;

	i=mystrlen(s1);

	// When the lengths of two strings are different
	if(i!=mystrlen(s2)) return 1;

	for(j=0;j<i;j++)
		if(s1[j]!=s2[j]) return 1;

	// When the two strings are same
	return 0;
}


void main(void){
	int define,i,j;
	char input1[MAX], input2[MAX], copy[MAX];

	printf("Input A : ");
	gets(input1);
	printf("Input B : ");
	gets(input2);
	printf("\n");

	define=mystrcmp(input1,input2);
	i=mystrlen(input1);
	j=mystrlen(input2);

	printf("strcpy(A->new) : %s\n",mystrcpy(copy,input1));
	printf("strcat(A + B)  : %s\n",mystrcat(input2, input1));

	if(define!=0) printf("A and B are different each other.\n");
	else printf("A and B are same.\n");

	printf("Length of A : %d\n",i);
	printf("Length of B : %d\n",j);
}