#include <stdio.h>

int main() {
	int lim = 100;
	int c;
	char s[lim];
	for (int i=0; ( c=getchar() ) != '\n'; ++i) {
		if( i == lim-1 ) break;
		else if ( c == EOF ) { break; }
		else { s[i] = c; }
	}
}
