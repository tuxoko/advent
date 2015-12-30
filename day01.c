#include <stdio.h>

int main(void)
{
	char c;
	int i = 0;
	int n = 0;
	int b = 0;
	while (scanf("%c", &c) == 1) {
		if (c == '(') {
			i++;
			n++;
		} else if (c == ')') {
			i++;
			n--;
			if (b == 0 && n == -1)
				b = i;
		}
	}
	printf("%d\n%d\n", n, b);
	return 0;
}
