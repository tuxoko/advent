#include <stdio.h>
#include <limits.h>

int bn;
int box[21];
int method[151][21];
int method2[151][21];
int num[151][21];

int calc(int liter, int first)
{
	int i, v = 0;
	if (method[liter][first] >= 0)
		return method[liter][first];
	if (liter >= box[first]) {
		v = 0;
		for (i = first + 1; i < bn; i++)
			v += calc(liter - box[first], i);
	}
	method[liter][first] = v;
	return v;
}

int calc2(int liter, int first)
{
	int i, v = 0;
	if (method2[liter][first] >= 0)
		return method2[liter][first];
	if (liter >= box[first]) {
		v = 0;
		for (i = first + 1; i < bn; i++) {
			int t = calc2(liter - box[first], i);
			if (t == 0)
				continue;
			if (num[liter][first] > num[liter-box[first]][i]+1) {
				num[liter][first] = num[liter-box[first]][i]+1;
				v = t;
			} else if (num[liter][first] == num[liter-box[first]][i]+1) {
				v += t;
			}
		}
	}
	method[liter][first] = v;
	return v;
}

int main(void)
{
	int i, j;
	box[bn++] = 0;
	while (scanf("%d", &box[bn]) == 1)
		bn++;
	for (i = 0; i < bn; i++)
		for (j = 0; j < 151; j++) {
			method[j][i] = -1;
			method2[j][i] = -1;
			num[j][i] = INT_MAX;
		}
	for (i = 0; i < bn; i++) {
		method[box[i]][i] = 1;
		method2[box[i]][i] = 1;
		num[box[i]][i] = 1;
	}

	printf("%d\n", calc(150, 0));
	printf("%d\n", calc2(150, 0));
	return 0;
}
