#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char*);

int main(int argc, char *argv[]) {

	for(int i = 0; i < argc; ++i) {
		if (*argv[i] == *"fuck") printf("%s\n", "FUCK YOU TOOOO");
		//printf("%s\n", argv[i]);
	}

	return 0;
}
