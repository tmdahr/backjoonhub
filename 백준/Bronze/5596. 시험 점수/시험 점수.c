#include <stdio.h>

int main(void)
{
	int wjd, wjd2, tn, tn2, rhk, rhk2, dud, dud2, s, t, cnf;
	scanf("%d %d %d %d", &wjd, &tn, &rhk, &dud);
	scanf("%d %d %d %d", &wjd2, &tn2, &rhk2, &dud2);
	s = wjd + tn + rhk + dud;
	t = wjd2 + tn2 + rhk2 + dud2;
	cnf = (s >= t) ? s : t;
	printf("%d", cnf);
	
	return 0;
}