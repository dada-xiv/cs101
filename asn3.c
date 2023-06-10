/*
 * CS101 Assignment #3
 *
 * This program translates given string of characters to a code by some rules.
 * When the character is alphabet, the ascii value of the character increases
 * as much as the number of each alphabets of the string.
 * And when the character is other kind of character, the ascii value of the
 * character increases as much as the number of all words of the string.
 */

#include<stdio.h>

#define MAXSTRING 100
#define ALPHABET 26

/* String input & counting numbers of each alphabet characters */
void input(char string[],int alphabet[]){
	int i,j;

	printf("Input : ");

	// String Input
	for(i=0;;i++){
		scanf("%c",&string[i]);
		if(string[i]=='\n') break;
	}

	// Initializing alphabet[]
	for(i=0;i<ALPHABET;i++)
		alphabet[i]=0;

	for(j=0;;j++){
		for(i=0;i<ALPHABET;i++)
			//when character is alphabet
			if(string[j]==('a'+i)||string[j]==('A'+i))
				alphabet[i]++;

		if(string[j]=='\n') break;
	}
}


/* Counting the number of words */
int word_cnt(char array[]){
	int i,cnt=0;

	for(i=0;;i++){
		if(array[i]=='\n') break;

		else if((array[i]!=' '&&array[i]!='\t')&&
			(array[i+1]==' '||array[i+1]=='\t')) cnt++;

		else if((array[i]!=' '&&array[i]!='\t')&&
			(array[i+1]=='\n')) cnt++;
	}

	return cnt;
}


/* Finding alphabet to corresponds to each alphabet[] */
int is_alphabet(char letter){
	int i;
	for(i=0;i<ALPHABET;i++)
		if(letter==('a'+i)||letter==('A'+i)) return i;

	// when the given character is not alphabet
	return (-1);
}


/* Printing a string called by other function */
void print_string(char array[]){
	int i;

	for(i=0;;i++){
		printf("%c",array[i]);
		if(array[i]=='\n') break;
	}
}



/* Generating code and Printing */
void output(char string[],int alphabet[],char code[],int cnt){
	int i,j,d;

	for(i=0;;i++){
		// Initializing code[]
		code[i]=0;

		d=is_alphabet(string[i]);
		// when the letter is alphabet
		if(d != -1 ) code[i]=string[i]+alphabet[d];
		// when the letter is non-alphabet
		else code[i]=string[i]+cnt;

		// at the end of the string
		if(string[i]=='\n') {
			code[i]=string[i];
			break;
		}
	}

	printf("Result : ");
	print_string(code);

	printf("Word count : %d\n\n",cnt);
}

void main(void){
	char string[MAXSTRING], code[MAXSTRING], quit; //quit for ending
	int alphabet[ALPHABET], num, i;//num for word counting

	// gets strings 5times
	for(i=0;i<5;i++){
		input(string,alphabet);
		num=word_cnt(string);
		output(string,alphabet,code,num);
	}
}