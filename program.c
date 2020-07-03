#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void permutation(char *word, int n)
{
	char *wordcpy=strdup(word); // creating a duplicate string and storing in wordcpy
	/*
	fgets() associate a next line character followed by a null character at last word
	still there is a small bug which resulting of extra newline during printing
	of permutation of the last word
	*/
	if(wordcpy[n-1]=='\n') // handling the of last word bug (not completely)
	{
		n--;
	}
	char temp;
	int i;
	printf("Permutations are as follows:\n");
	while(1) // infinite loop
	{
		for(i=0;i<n-1;i++) // swapping of string
		{
			temp=wordcpy[i];
			wordcpy[i]=wordcpy[i+1];
			wordcpy[i+1]=temp;
			printf("%s\n",wordcpy);
		}
		if(!strcmp(word,wordcpy)) // breaking condition of loop
		{
			break;
		}
	}
	printf("\n"); // nextline character
}
int main(int argc, char *argv[]) // command line argument 
{	/* initialising the file pointer pointing to the file which is passing through command line */
	FILE *fp =fopen(argv[1],"r");
	if(fp==NULL)
	{
		printf("File is empty!\n"); // if the file is empty
		printf("Program Terminated!\n");
		exit(1); // exit the program execution with return code 1
	}
	/* handling the file */
	char str[1024]; //initialising a character array for taking input from file
	/* 
	The C library function char *strtok(char *str, const char *delim)
	breaks string str into a series of tokens using the delimiter delim (string)
	Reference: tutorialspoint.com/c_standard_library/c_function_strtok
	*/
	const char delim[2] =",";
	/*
	Since in Comma-Separated Values(CSV) file, values are separeted using commas
	here delimiter is ','
	*/
	char *word;
	while(fgets(str,1023,fp)!=NULL)
	{
		char *temp=strdup(str); // creating a duplicate string from buffer
		word=strtok(temp,delim);// returning first token from the string
		while(word!=NULL)
		{
			printf("Word is %s\n",word);// tokenised string (word before ',')
			/* Calling the permutation program passing the base address and size of the word*/
			permutation(word,strlen(word));
			
			word=strtok(NULL,delim);
		}
	}
	fclose(fp); // Closing of file pointer, buffer associated with the file is removed from memory
	return 0;
}
