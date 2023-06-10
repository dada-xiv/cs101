/*
 * CS101 Lab #11 : pointer and file I/O
 *
 */
 
#include<stdio.h>

int main(int argc,char *argv[]){
	FILE *in;

	char ch;
	int a=0,b=0,c=0;

	if(argc<2){
		fprintf(stderr,"Usage : %s filename\n",argv[0]);
		exit(1);
	}

	//when the file doesn't exist
	if((in=fopen(argv[1],"r"))==NULL){
		fprintf(stderr,"I couldn't open the file \"%s\"\n",argv[1]);
		exit(2);
	}

	while((ch=getc(in))!=EOF){
		if(ch=='a') a++;
		else if(ch=='b') b++;
		else if(ch=='c') c++;
	}

	printf("A : %d\n",a);
	printf("B : %d\n",b);
	printf("C : %d\n",c);

	fclose(in);  //close file

	return 0;
}