#include <stdio.h>
#define MAX 1000

/* this program removes comments */
/* Exercise 1-23 */

int main() {
	int c;
	int count = 0;
	char arr[MAX];
	while((c = getchar()) != EOF) {
		arr[count] = c;
		if (c == '\n') {
			for(int i = 0; i < count; ++i) {
				if(arr[i] == '/') { break; }
				putchar(arr[i]);
			}
			putchar('\n');
			count = 0;
			continue;
		}
		count++;
	}
}
