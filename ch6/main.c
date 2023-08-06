#include <stdio.h>

struct Point{
	int x;
	int y;
};

int main(int argc, char *argv[]) {
	struct Point p, *ptr;
	ptr = &p;
	ptr->x = 5;
	ptr-> y = 10;
	printf("%d\n", ptr->x);
	printf("%d\n", ptr->y);
}
