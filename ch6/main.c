#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 1000
#define BUFSIZE 100

struct key {
	char *word;
	int count;

} keytab[] =  {
	"auto", 0, // same as { "auto", 0 }
 	"break", 0,
 	"case", 0,
 	"char", 0,
 	"const", 0,
 	"continue", 0,
 	"default", 0,
 	/* ... */
 	"unsigned", 0,
 	"void", 0,
 	"volatile", 0,
 	"while", 0
};

#define NKEYS (sizeof keytab / sizeof(struct key))

int binsearch (char *, struct key *, int);
int getword(char*, int);


char buf[BUFSIZE];  // Buffer for "ungetting" characters
int buf_index = 0;  // Current index in the buffer

// Function to push a character back into the buffer
void ungetch(int c) {
    if (buf_index < BUFSIZE) {
        buf[buf_index++] = c;
    } else {
        printf("Error: Buffer is full, cannot ungetch.\n");
    }
}

int main(int argc, char *argv[]) {
	int n;
	char word[MAXWORD];

	while(getword(word,MAXWORD) != EOF)
		if(isalpha(word[0]))
			if((n = binsearch(word, keytab, NKEYS)) >= 0)
				keytab[n].count++;

	printf("-------------------\n");
	
	for(int i = 0; i < NKEYS; ++i) {
		if (keytab[i].word == NULL) break;
		printf("%s -- ", keytab[i].word);
		printf("%d\n", keytab[i].count);
	}
}

int binsearch (char *word, struct key *tab, int n) {
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if((cond = strcmp(word, tab[mid].word)) < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int getword(char *word, int lim) {
	int c;
	char *w = word;

	while (isspace(c = getchar()))
	;
	
	if (c != EOF || c != '\n') {
		*w++ = c;
	}
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; ++w)
		if (!isalnum(*w = getchar())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
