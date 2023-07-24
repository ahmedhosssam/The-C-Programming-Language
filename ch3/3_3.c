#include <stdio.h>
#define MAX 100

void expand(char s1[], char s2[], int size);

int main() {
	char c;
	int i = 0;
	char s1[10];
	char s2[MAX] = {};
	
	while( (c = getchar()) != '\n' ){
		s1[i] = c;
		++i;
	}

	/*for (int j = 0; j < i; ++j)
		printf("%c\n", s1[j]);*/

	expand(s1, s2, i);
}

void expand(char s1[], char s2[], int size) {
	int i;
	int n = 0; // to loop over s2
	for (i = 0; i < size + 1; ++i) {
		int c1;
		int c2;
		if (s1[i] >= 'a' && s1[i] <= 'z') {
			c1 = (int)s1[i]; // the ASCII value of s1[i]
			
			if (s1[i+1] == '-') {
				if (s1[i+2] >= 'a' && s1[i+2] <= 'z') {
					c2 = (int)s1[i+2]; // same as c1

					for (int j = c1; j <= c2; ++j) {
						s2[n] = j;
						++n;
						printf("%c", j);
					}
					
				} else { continue; }

			} else { continue; }
		} 
	}
	printf("\n");
}
