#include <stdio.h>

int main() {
	int i = 1;
	while (i <= 64) {
		printf("%d", i);
		i *= 2;
	}
	return 0;
}