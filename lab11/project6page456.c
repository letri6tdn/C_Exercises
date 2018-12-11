#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 20    /*max length of a word*/
#define MAX_WORDS 50   /*max words input*/

char *word[MAX_WORDS];
int numWords = 0;

int read_line();
int compare(const void *a, const void *b);

int main(void) {
	int smallest, i, j;
	char *temp;
	
	putchar('\n');
	for(i=0; ; i++) {
		printf("Enter a word: ");
		if(read_line() == 0)
			break;
		if(numWords == MAX_WORDS)
			break;
	}
	
	qsort(words, numWords, sizeof(char *), compare);
	
	printf("In sorted order: ");
	for(i=0; i<numWords; i++){
		printf("%s%s", words[i], i == numWords ? "": " ");
	}
	printf("\n\n");
	
	return 0;
}

int read_line(char str[], int n)
{
    words[numWords] = malloc(MAX_LEN + 1);
    int ch, i = 0;
     if (!words[numWords])
    {
        printf("Memory allocation error.\n\n");
        exit(EXIT_FAILURE);
    }
    while ((ch = getchar()) != '\n')
        if (i < n)
            words[numWords][i++] = ch;
        else if (ch == ' ')
            break;
    words[numWords][i] = '\0';
    numWords++;
    return i;
}
 
 int compare(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
		