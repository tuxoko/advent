#include <stdio.h>
#include <string.h>
char names[10][16] = {
"children:",
"cats:",
"samoyeds:",
"pomeranians:",
"akitas:",
"vizslas:",
"goldfish:",
"trees:",
"cars:",
"perfumes:",
};

int target[10] = { 3,7,2,3,0,0,5,3,2,1 };

int nameid(char *name)
{
	int i;
	for (i = 0; strcmp(name, names[i]) != 0; i++);
	return i;
}

int greater(int id)
{
	return id == 1 || id == 7;
}

int fewer(int id)
{
	return id == 3 || id == 6;
}

int main(void)
{
	char t[16];
	int i;
	char n[3][16];
	int v[3];
	int id = 0, id1 = 0, id2 = 0;
	while(scanf("%s", t) == 1) {
		id++;
		for (i = 0; i < 9; i++) {
			if (i == 2 || i == 5 || i == 8)
				scanf("%d", &v[(i-2)/3]);
			else if (i == 1 || i == 4 || i == 7)
				scanf("%s", n[(i-1)/3]);
			else
				scanf("%s", t);
		}
		for (i = 0; i < 3; i++) {
			if (target[nameid(n[i])] != v[i])
				break;
			if (i == 2)
				id1 = id;
		}
		for (i = 0; i < 3; i++) {
			int aid = nameid(n[i]);
			if (greater(aid) && v[i] <=target[aid])
				break;		
			if (fewer(aid) && v[i] >= target[aid])
				break;
			if (!greater(aid) && !fewer(aid) && v[i] != target[aid])
				break;
			if (i == 2)
				id2 = id;
		}
	}
	printf("%d\n%d\n", id1, id2);
	return 0;
}
