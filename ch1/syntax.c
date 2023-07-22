#include <stdio.h>
#define MAX 1000

/* not complete */

int main() {
	int c;
	int count = 0;
	char arr[MAX];

	while( (c = getchar()) != EOF ) {
		arr[count] = c;
		++count;

		if( c == '\n' ) {
			int l = 0;
			int r = 0;

			for(int i = 0; i < count; ++i) {
				if(arr[i] == '{') {
					++l;
					for (int j = i; j < count; ++j) {
						if(arr[j] == '}') {
							++r;  break;
						} 
					}
				}
				//else if(arr[i] == '}') { ++r; }
			}
			if (l != r) { printf("ERROR\n"); break; }
			count = 0;
		}
	}
}
