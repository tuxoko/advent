#include <stdio.h>
#include <stdlib.h>

int calc_dist(int speed, int dur, int rest, int time)
{
	int total_seg = time / (dur+rest);
	int residue = time % (dur+rest);
	int dist = 0;

	dist += speed * dur * total_seg;
	residue = residue > dur ? dur : residue;
	dist += speed * residue;
	return dist;
}

int main(void)
{
	char t[64];
	char name[16][16];
	int speed[16], dur[16], rest[16];
	int i, j, n = 0;
	int time = 2503;
	int maxd;
	int score[16] = {};
	/* Rudolph can fly 22 km/s for 8 seconds, but then must rest for 165 seconds. */
	while (scanf("%s", name[n]) == 1) {
		for (i = 0; i < 14; i++) {
			if (i == 2)
				scanf("%d", &speed[n]);
			else if (i == 5)
				scanf("%d", &dur[n]);
			else if (i == 12)
				scanf("%d", &rest[n]);
			else scanf("%s", t);
		}
		n++;
	}
	for (maxd = 0, i = 0; i < n; i++) {
		int d = calc_dist(speed[i], dur[i], rest[i], time);
		if (d > maxd) {
			maxd = d;
		}
	}
	printf("%d\n", maxd);

	for (j = 1; j <= time; j++) {
		for (maxd = 0, i = 0; i < n; i++) {
			int d = calc_dist(speed[i], dur[i], rest[i], j);
			if (d > maxd) {
				maxd = d;
			}
		}
		for (i = 0; i < n; i++) {
			if (calc_dist(speed[i], dur[i], rest[i], j) == maxd)
				score[i]++;
		}
	}
	for (maxd = 0, i = 0; i < n; i++)
		if (score[i] > maxd)
			maxd = score[i];
	printf("%d\n", maxd);
	return 0;
}
