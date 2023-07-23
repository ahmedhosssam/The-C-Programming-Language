#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	printf("Ranges of char, short, int: \n");
	printf("Range values of char: %d | %d\n", CHAR_MIN, CHAR_MAX);
	printf("Range values of short: %d | %d\n", SHRT_MIN, SHRT_MAX);
	printf("Range values of int: %d | %d\n", INT_MIN, INT_MAX);
	printf("Ranges of long variables: \n");
	printf("Range values of long: %ld | %ld\n", LONG_MIN, LONG_MAX);
	//printf("Range values of int: %Lf | %Lf\n", LDBL_MIN, LDBL_MAX); // very long
	printf("Range values of int: %d \n", LDBL_DIG);
	
}
