#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void looknsay(char *str, char *new)
{
	int n = 0;
	int i, j;
	for (i = 0; str[i];) {
		for (j = i+1; str[j] == str[i]; j++);
		new[n] = '0' + (j - i);
		new[n+1] = str[i];
		n += 2;
		i = j;
	}
	new[n] = 0;
}

int main(void)
{
	int i;
	char *str, *new, *t;
	str = malloc(10000000);
	new = malloc(10000000);
	strcpy(str, "1321131112");
	for (i = 0; i < 50; i++) {
		looknsay(str, new);
		t = str;
		str = new;
		new = t;
		if (i == 39)
			printf("%lu\n", strlen(str));
	}
	printf("%lu\n", strlen(str));
	return 0;
}
