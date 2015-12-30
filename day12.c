#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int calc_array(void);
int calc_object(void);

int gsum = 0;

int calc_int(char head, char *last)
{
	int n = 0, x;
	char ss[32];
	char c;
	ss[n++] = head;
	while (scanf("%c", &c) == 1) {
		if (!isdigit(c))
			break;
		ss[n++] = c;
	}
	ss[n] = '\0';
	*last = c;
	sscanf(ss, "%d", &x);
	gsum += x;
	return x;
}

int check_red(void)
{
	int state = 0;
	char c;
	while (scanf("%c", &c) == 1) {
		if (c == '"')
			break;
		if (state == 0 && c == 'r')
			state = 1;
		else if (state == 1 && c == 'e')
			state = 2;
		else if (state == 2 && c == 'd')
			state = 3;
		else
			state = -1;
	}
	if (state == 3)
		return 1;
	return 0;
}

int calc_object(void)
{
	int sum = 0;
	char c;
	int state = 0;
	int red = 0;
	while (scanf("%c", &c) == 1) {
next:
		if (c == '}')
			break;
		if (state == 0 && c == '"')
			state = 1;
		else if (state == 1 && c == '"')
			state = 2;
		else if (state == 2 && c == ':')
			state = 3;
		else if (state == 3) {
			if (c == '{')
				sum += calc_object();
			else if (c == '[')
				sum += calc_array();
			else if (c == '-' || isdigit(c)) {
				sum += calc_int(c, &c);
				state = 0;
				goto next;
			} else if (c == '"') {
				int a = check_red();
				if (!red)
					red = a;
			}
			state = 0;
		}
	}
	return (red ? 0 : sum);
}

int calc_array(void)
{
	int sum = 0;
	char c;
	while (scanf("%c", &c) == 1) {
next:
		if (c == ']')
			break;
		if (c == '{')
			sum += calc_object();
		else if (c == '[')
			sum += calc_array();
		else if (c == '-' || isdigit(c)) {
			sum += calc_int(c, &c);
			goto next;
		} else if (c == '"')
			check_red();
	}
	return sum;
}

int main(void) {
	char c;
	int sum = 0;
	scanf("%c", &c);
	if (c == '{')
		sum = calc_object();
	else if (c == '[')
		sum = calc_array();
	printf("%d\n%d\n", gsum, sum);
	return 0;
}
