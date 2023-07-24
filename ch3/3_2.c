#include <stdio.h>
#define MAX 1000

void escape(char[], char[]);
void revescape(char[], char[]);

int main() {
	char t[MAX] = {}; // input
	char s[2 * MAX] = {}; // output
	char c;
	int i = 0;

	while ( (c = getchar()) != EOF) {
		t[i] = c;
		++i;
	}

	printf("\n");
	
	revescape(s, t);

	for(int i = 0; i < MAX; ++i)
		printf("%c", s[i]);
	printf("\n");
}

void escape(char s[], char t[]) {
	int j = 0; // to loop over s

	for(int i = 0; i < MAX; ++i) {
		if ( t[i] == '\t' )
		{
			s[j] = '\\'; ++j; s[j] = 't'; ++j;
		}
		else if ( t[i] == '\n' ) {
			s[j] = '\\'; ++j;
			s[j] = 'n'; ++j;
		}
		else {
			s[j] = t[i]; ++j;
		}
	}
	s[j] = '\0';
}

void revescape(char s[], char t[]) {
	int j = 0; // to loop over s

	for(int i = 0; i < MAX; ++i) {
		if( t[i] == '\\') {
			switch (t[i+1]) {
				case 't':
					s[j] = '\t'; ++j; ++i;
					break;
				case 'n':
					s[j] = '\n'; ++j; ++i;
					break;
				default:
					s[j] = t[i]; ++j;
			}
		}
		else {
			s[j] = t[i]; ++j;
		}
	}
	s[j] = '\0';
}

