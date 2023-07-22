#include <stdio.h>
#include <stdlib.h>
#define LOWER 0 /* lower limit of table */
#define UPPER 300
#define STEP 20

void count_voids() {
	char ch;
	int count = 0;
	while ( (ch = getchar()) != EOF ) {
		if(ch == ' ' || &ch == "\t" || &ch == "\n")
			++count;
	}

	printf("Count is: %d\n", count);
}

void replace() {
	char ch;
	int count = 0;
	while ( (ch = getchar()) != EOF ) {
		if(ch == ' ') {
			++count;
			if(count == 1) { putchar(ch); continue; }
			else --count; continue;
		}
		
		if(ch != ' ') {
			count = 0;
			putchar(ch);
		}
	}
}

void replace2() {
	char ch;
	while ( (ch = getchar()) != EOF ) {
		if(ch == '\t') { putchar(*"\\"); putchar(*"t"); }
		else if(ch == '\b') { putchar(*"\\"); putchar(*"b"); }
		else if(ch == '\\') { putchar(*"\\"); putchar(*"\\"); }
		else putchar(ch);
	}
}

void perline() {
	int count = 0;
	char ch;
	while ( (ch = getchar()) != EOF ) {
		if (ch == ' ') {
			++count;
			if(count == 1) { putchar(*"\n"); continue; }
			else --count; continue;
		}

		if(ch != ' ') {
			count = 0;
			putchar(ch);
		}
	}
}

int main()
{
	float fahr, cels;
	int define = 69;

	int i = 5/9;
	float f = 5.0/9.0;
	char ch = 'a';

	putchar(ch);
	printf("\n");

	fahr = LOWER;
	printf("%d", i);
	printf("\n");
	printf("%.2f", f+5);
	printf("\n");
	printf("----------------\n");

	while (fahr <= UPPER) {
		cels = 5.0 * (fahr - 32.0) / 9.0;
		printf("%3.0f\t%6.2f\n", fahr, cels);
		fahr = fahr + STEP;
	}

	printf("----------------\n");

	for (fahr = 0; fahr <= 300; fahr = fahr + 20)
		printf( "%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr-32) );

	printf("----------------\nReverse Order: \n");

	for (fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf( "%3.0f %6.1f\n", fahr, (5.0/9.0)*(fahr-32) );

	char num1 = 1;
	printf("%d\n", num1);
	printf("%d\n", num1+6);

	char c;

	printf("----------------\n");

	char cc = '9';
	printf("digit: %d\n", cc-'0');
	perline();
}
