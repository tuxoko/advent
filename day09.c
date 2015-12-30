#include <stdio.h>
#include <string.h>
#include <limits.h>

#define swap(a, b) do { int __t = a; a = b; b = __t; } while (0)

int score[9][9];

char names[8][16] = {
"AlphaCentauri",
"Snowdin",
"Tambi",
"Faerun",
"Norrath",
"Straylight",
"Tristram",
"Arbre",
};

int nameid(char *name)
{
	int i;
	for (i = 0; strcmp(name, names[i]) != 0; i++);
	return i;
}

void calc(int p[], int r, int *max, int *min)
{
	int s = 0;
	int i;
	for (i = 0; i < r; i++) {
		s += score[p[i]][p[i+1]];
	}
	(*max) = (*max) > s ? (*max) : s;
	(*min) = (*min) < s ? (*min) : s;
}

void permute(int p[], int l, int r, void (*calc)(int *, int,  int *, int *), int *max, int *min)
{
	int i;
	if (l == r) {
		calc(p, r, max, min);
		return;
	}

	for (i = l; i <= r; i++) {
		swap(p[l], p[i]);
		permute(p, l+1, r, calc, max, min);
		swap(p[l], p[i]);
	}
}

int main(void)
{
	char a[16], b[16], t[16];
	int p[8] = {0,1,2,3,4,5,6,7};
	int s, i;
	int min = INT_MAX;
	int max = 0;
	while(scanf("%s", a) == 1) {
		for (i = 0; i < 4; i++) {
			if (i == 3) {
				scanf("%d", &s);
			} else if (i == 1) {
				scanf("%s", b);
			} else {
				scanf("%s", t);
			}
		}
		score[nameid(a)][nameid(b)] = s;
		score[nameid(b)][nameid(a)] = s;
	}

	permute(p, 0, 7, calc, &max, &min);
	printf("%d\n%d\n", min, max);
	return 0;
}
