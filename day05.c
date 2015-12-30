#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[32];
	int i;
	int count1 = 0;
	int count2 = 0;
	while(scanf("%s", str) == 1) {
		int vow = 0;
		int repeat = 0;

		if (strstr(str, "ab"))
			goto part2;
		if (strstr(str, "cd"))
			goto part2;
		if (strstr(str, "pq"))
			goto part2;
		if (strstr(str, "xy"))
			goto part2;
		for (i = 0; str[i]; i++) {
			if (str[i] == 'a' || str[i] == 'e' ||
					str[i] == 'i' ||
					str[i] == 'o' ||
					str[i] == 'u')
				vow++;
			if (i > 0 && str[i] == str[i-1])
				repeat = 1;
		}
		if (vow >= 3 && repeat)
			count1++;
part2:
		repeat = 0;
		for (i = 0; str[i]; i++) {
			if (i > 1 && str[i] == str[i-2])
				repeat |= 1;
			if (i > 2) {
				char *sp;
				char temp[] = { str[i-1], str[i], 0 };
				sp = strstr(str, temp);
				if (sp && sp <= &str[i-3])
					repeat |= 2;
			}
		}
		if (repeat == 3)
			count2++;
	}
	printf("%d\n%d\n", count1, count2);
	return 0;
}
