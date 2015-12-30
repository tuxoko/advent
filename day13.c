#include <stdio.h>

#define swap(a, b) do { int __t = a; a = b; b = __t; } while (0)

int score[9][9];

int nameid(char *name)
{
	if (name[0] == 'M')
		return 7;
	return name[0] - 'A';
}

void calc(int p[], int r, int *max)
{
	int s = 0;
	int i;
	for (i = 0; i <= r + 1; i++) {
		if (i < r + 1) {
			s += score[p[i]][p[i+1]];
			s += score[p[i+1]][p[i]];
		} else {
			s += score[p[i]][p[0]];
			s += score[p[0]][p[i]];
		}
	}
	(*max) = (*max) > s ? (*max) : s;
}

void permute(int p[], int l, int r, void (*calc)(int *, int,  int *), int *max)
{
	int i;
	if (l == r) {
		calc(p, r, max);
		return;
	}

	for (i = l; i <= r; i++) {
		swap(p[l], p[i]);
		permute(p, l+1, r, calc, max);
		swap(p[l], p[i]);
	}
}

int main(void)
{
	char a[16], b[16], t[16];
	int p[9] = {0,1,2,3,4,5,6,7,8};
	int minus, s, i;
	int max = 0;
	while(scanf("%s", a) == 1) {
		for (i = 0; i < 10; i++) {
			if (i == 2) {
				scanf("%d", &s);
				s = (minus) ? -s : s;
			} else if (i == 9) {
				scanf("%s", b);
			} else {
				scanf("%s", t);
				if (i == 1)
					minus = (t[0] == 'l');
			}
		}
		score[nameid(a)][nameid(b)] = s;
	}

	permute(p, 0, 6, calc, &max);
	printf("%d\n", max);
	max=0;
	permute(p, 0, 7, calc, &max);
	printf("%d\n", max);

}
