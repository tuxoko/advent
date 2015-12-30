#include <stdio.h>
int light[1000][1000];
int light2[1000][1000];
int main(void)
{
	char cmd[16];
	int sx,sy,ex,ey;
	char t[16],u[16],v[16];
	int sum = 0, sum2 = 0;
	int i, j;
	while (scanf("%s", cmd) == 1) {
		if (cmd[1] == 'u')
			scanf("%s", cmd);
		scanf("%d%c%d%s%d%c%d", &sx, t, &sy, u, &ex, v, &ey);

		for (i = sx; i <= ex; i++) {
			for (j = sy; j <= ey; j++) {
				if (cmd[0] == 't') {
					light[i][j] = !light[i][j];
					light2[i][j] += 2;
				} else if (cmd[1] == 'n') {
					light[i][j] = 1;
					light2[i][j]++;
				} else {
					light[i][j] = 0;
					light2[i][j] = light2[i][j] > 0 ? light2[i][j]-1 : 0;
				}
			}
		}
	}
	for (i = 0; i < 1000; i++) {
		for (j = 0; j < 1000; j++) {
			sum += light[i][j];
			sum2 += light2[i][j];
		}
	}
	printf("%d\n%d\n", sum, sum2);
	return 0;
}
