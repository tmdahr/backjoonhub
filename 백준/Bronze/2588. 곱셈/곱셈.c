#include <stdio.h>

int main(void)
{
	int dlf, dl, tka, tk, dh, dbr;
	scanf ("%d %d", &dlf, &dl);
	tka = dlf * (dl % 10);
	printf("%d\n", tka);
	tk = dlf * (dl % 100 - dl % 10) / 10;
	printf("%d\n", tk);
	dh = dlf * (dl - dl % 100) / 100;
	printf("%d\n", dh);
	dbr = tka + tk * 10 + dh * 100;
	printf("%d\n", dbr);
	
	return 0;
}