#include <stdio.h>
#include <limits.h>

int strLen(char s[]);
void lower(char s[]);

int main() {
	printf("%d\n", 0x1f);
	printf("%d\n", 045);
	printf("%d\n", strLen("hello"));
	
	printf("%c\n", 'X' + 32); // convert to lower case

	char s[5] = {'X', 'N', 'r', 'f', 'G'};

	for (int i = 0; i < 5; ++i)
		printf("%c\n", s[i]);

	printf("-------------------\n"); // convert to lower case

	lower(s);
	for (int i = 0; i < 5; ++i)
		printf("%c\n", s[i]);

	printf("%lX\n", 465561465546869);
	printf("%.2f\n", (double) 55);
	printf("%d\n", (int) 55.6);

	unsigned long int xx = 1;

	printf("%ld\n", sizeof(xx));

	char ss[100];
	int i = 0;

}

int strLen(char s[]) {
	int i;

	while(s[i] != '\0')
		++i;
	return i;
}

void lower(char s[]) {
	int i = 0;
	while(s[i] != '\0') {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] += ( 'a' - 'A' );
		}
		++i;
	}
}
