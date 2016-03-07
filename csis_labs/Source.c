#include <stdio.h>

int main() {
	int i = 1234;
	do {
		printf("%d\n", i);
		i /= 10;
	} while (i > 0);
	return 0;
}