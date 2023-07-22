#include <stdio.h>

void test(int arr[]) { printf("%d\n", *arr); }

int main() {
	int count = 0;
	char ch;
	int arr[49];
	int count_arr = 0;
	
	test(arr);
	while ( (ch = getchar()) != EOF ) {
		if(ch == '\n') continue;
		if(ch != ' ') { arr[count_arr]++; continue; }
		if(ch == ' ') count_arr++;
	}

	for(int i = 0; i < count_arr+1; ++i) {
		for(int j = 0; j < arr[i]; ++j)
			printf("-");
		printf("\n");
	}


	printf("done\n");
}
