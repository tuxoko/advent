#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	/*
	 * Sugar: capacity 3, durability 0, flavor 0, texture -3, calories 2
	 * Sprinkles: capacity -3, durability 3, flavor 0, texture 0, calories 9
	 * Candy: capacity -1, durability 0, flavor 4, texture 0, calories 1
	 * Chocolate: capacity 0, durability 0, flavor -2, texture 2, calories 8
	 */
	int i, j, k, l;
	int max = 0, max2 = 0;
	int attr[4][5] = {
		{ 3, 0, 0, -3, 2 },
		{ -3, 3, 0, 0, 9 },
		{-1, 0, 4, 0, 1 },
		{ 0, 0, -2, 2, 8 },
	};
	for (i = 0; i <= 100; i++)
		for (j = 0; j <= 100-i; j++)
			for (k = 0; k < 100-i-j; k++) {
				int sum[5];
				int a;
				int prod;
				l = 100 - i - j - k;
				for (a = 0; a < 5; a++) {
					sum[a] = i*attr[0][a] + j*attr[1][a] + k*attr[2][a] + l*attr[3][a];
					if (sum[a] <= 0)
						goto backout;
				}
				prod = sum[0]*sum[1]*sum[2]*sum[3];
				max = prod > max ? prod : max;
				if (sum[4] == 500)
					max2 = prod > max2 ? prod : max2;
backout:
				;
			}
	printf("%d\n%d\n", max, max2);
	return 0;
}
