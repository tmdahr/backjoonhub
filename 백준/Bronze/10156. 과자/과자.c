#include <stdio.h>

int main(void)
{
	int k, n, m, qls;
	scanf("%d %d %d", &k, &n, &m);
	qls = (k * n > m) ? k * n - m : 0;
	printf("%d", qls);
	
	return 0;
}