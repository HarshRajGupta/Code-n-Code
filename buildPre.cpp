#include <stdio.h>

int main(void) {
    char *arr = "Deltax";
    char c;
    for (int i = 0; i < 3; ++i) {
		c = *arr++;
	}
	printf("%c", c);
}