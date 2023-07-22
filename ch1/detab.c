#include <stdio.h>
#define MAXLINE 1000
#define TABWIDTH 4

char line[MAXLINE];

int getLine(void);
void detab();

int main() {
	detab();
}

void detab() {
	int c;
	int charCount = 0;

	while((c = getchar()) != EOF) {
		if(c == '\t') {
			for(int i = 0; i < TABWIDTH; ++i) {
				putchar(' ');
				charCount++;
			}
		} else {
			putchar(c);
			charCount++;
		}
	}
}
