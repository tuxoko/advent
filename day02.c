#include <stdio.h>

int main(void)
{
	int l, w, h;
	char t, u;
	int total = 0;
	int totalr = 0;
	while (scanf("%d%c%d%c%d", &l, &t, &w, &u, &h) == 5) {
		int a1 = l*w;
		int a2 = w*h;
		int a3 = h*l;
		int maxl;
		int mina = a1 < a2 ? a1 : a2;
		mina = mina < a3 ? mina : a3;

		total += 2*a1 + 2*a2 + 2*a3 + mina;

		maxl = l > w ? l : w;
		maxl = maxl > h ? maxl : h;
		totalr += 2*(l+w+h-maxl) + l*w*h;
	}
	printf("%d\n%d\n", total, totalr);
	return 0;
}
