#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];
char longest[MAXLINE];

int getLine();
void printline(char line[], int len);
void copy(char to[], char from[]);
void reverse(char s[], int size);

int main()
{
	char arr[7] = {'0', '1', '6', '3', '4', 'A', 'Z'};

	printline(arr, 7);
	reverse(arr, 7);
	printline(arr, 7);

	int len = getLine();
	printf("Len: %d\n", len);
	printf("Line: %s\n", line);
}

void reverse(char s[], int size) {
	char newarr[size]; 
	for(int i = size-1; i >= 0; i--)
		newarr[size - i - 1] = s[i];

	for(int i = 0; i < size; ++i) 
		s[i] = newarr[i];
}

int getLine(void) {
	char c;
	int i; // we need it for the length
	for(i = 0; i < MAXLINE && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	line[i] = '\0';
	return i; /* length of the line  */
}

void printline(char line[], int len) {
	printf("Your line is: ");

	for(int i = 0; i < len; ++i)
		printf("%c", line[i]);
	printf("\n");
}
