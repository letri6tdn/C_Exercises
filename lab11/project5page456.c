#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20    /*max length of a word*/
#define MAX_WORDS 50   /*max words input*/

char *word[MAX_WORDS];
int numWords = 0;

int read_line();

int main(void) {
	int smallest, i, j;
	char *temp;
	
	putchar('\n');
	for(i=0; ;i++) {
		printf("Enter a word: ");
		if(read_line() == 0)
			break;
		if(numWords == MAX_WORDS)
			break;
	}
	
	/*sort*/
	for(i=0; i<numWords; i++) {
		smallest = i;
		for(j=i+1; j<numWords; j++) 
			if(strcmp(word[j], word[smallest]) < 0)
				smallest = j;
		temp = word[i];
		word[i] = word[smallest];
		word[smallest] = temp;
	}
	
	printf("In sorted order: ");
	for(i=0; i < numWords; i++)
		printf("%s%s", word[i], i == numWords ? "": " ");
	printf("\n\n");
	
	return 0;
}

int read_line(char str[], int n) {
	word[numWords] = malloc(MAX_LEN+1);
	int ch, i=0;
	
	if(!word[numWords]){
		printf("Memory allocation error.\n\n");
		exit(EXIT_FAILURE);
	}
	while((ch=getchar()) != '\n')
		if(i<n)
			word[numWords][i++] = ch;
		else if(ch==' ')
			break;
	word[numWords][i] = '\0';
	numWords++;
	return i;
}

		
		
		
	
		