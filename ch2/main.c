#include <stdio.h>
#include <limits.h>

int strLen(char s[]);

int main() {
	printf("%d\n", 0x1f);
	printf("%d\n", 045);
	printf("%d\n", strLen("hello"));
}

int strLen(char s[]) {
	int i;

	while(s[i] != '\0')
		++i;
	return i;
}
