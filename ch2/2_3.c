#include <stdio.h>
#include <ctype.h>
#include <math.h>

void htoi(char s[]);

int main() {
	char s[50];
	//printf("%d\n", 10 + 'f' - 'a');
	scanf("%s", s);
	htoi(s);
}

// converts hexadecimal numbers into decimal
void htoi(char s[]) {
	int i = 0; // to loop over s
	int n = 0; // to loop over res
	int res[50];
	int dec = 0;

	while(s[i] != '\0') {
		if (s[i] == '0' && s[i+1] == 'x' || s[i+1] == 'X') {
			i+=2;
			continue;
		}
		
		if (isdigit(s[i]))
			res[n] = s[i] - '0'; // convert the digit to its numeric value

		else if ( s[i] >= 'A' && s[i] <= 'F' )
			res[n] = 10 + s[i] - 'A'; // convert the letter to its hexa value

		else if ( s[i] >= 'a' && s[i] <= 'f' )
			res[n] = 10 + s[i] - 'a'; // same

		++i;
		++n;
	}

	int y = 0;
	for (int j = n-1; j >= 0; --j) {
		dec += res[j] * pow(16, y);
		++y;
	}

	printf("RESULT: %d\n", dec);
}

