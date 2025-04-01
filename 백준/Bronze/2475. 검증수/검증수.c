#include <stdio.h>

int main(void)
{
	int qjs1, qjs2, qjs3, qjs4, qjs5, qjs6;
	scanf("%d %d %d %d %d", &qjs1, &qjs2, &qjs3, &qjs4, &qjs5);
	qjs6 = ((qjs1 * qjs1) + (qjs2 * qjs2) + (qjs3 * qjs3) + (qjs4 * qjs4) + (qjs5 * qjs5)) % 10;
	printf("%d", qjs6);
	
	return 0;
}