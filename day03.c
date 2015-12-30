#include <stdio.h>
#include <stdlib.h>

struct pos {
	union {
		struct {
			int x;
			int y;
		};
		long xy;
	};
};

int pos_cmp(const void *a, const void *b)
{
	const struct pos *pa = a;
	const struct pos *pb = b;

	return (pa->xy < pb->xy) - (pa->xy > pb->xy);
}

int main(void)
{
	char c;
	struct pos *pos;
	struct pos *pos2;
	int i;
	int n = 1;
	int total, total2;
	pos = malloc(16384*sizeof(struct pos));
	pos2 = malloc(16384*sizeof(struct pos));
	pos[0] = (struct pos){ .xy = 0 };
	pos2[0] = (struct pos){ .xy = 0 };
	pos2[1] = (struct pos){ .xy = 0 };
	pos2 = &pos2[1];

	while (scanf("%c", &c) == 1) {
		int dx = 0, dy = 0;
		switch (c) {
			case '<':
				dx = -1;
				break;
			case '>':
				dx = 1;
				break;
			case '^':
				dy = 1;
				break;
			case 'v':
				dy = -1;
				break;
		}
		pos[n] = (struct pos){ .x = pos[n-1].x + dx, .y = pos[n-1].y + dy};
		pos2[n] = (struct pos){ .x = pos2[n-2].x + dx, .y = pos2[n-2].y + dy};
		n++;
	}
	qsort(pos, n, sizeof(struct pos), pos_cmp);
	qsort(pos2, n, sizeof(struct pos), pos_cmp);

	for (total = 1, total2 = 1, i = 1; i < n; i++) {
		if (pos[i].xy != pos[i-1].xy)
			total++;
		if (pos2[i].xy != pos2[i-1].xy)
			total2++;
	}
	printf("%d\n%d\n", total, total2);
	return 0;
}
