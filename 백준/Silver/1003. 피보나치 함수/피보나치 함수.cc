#include <stdio.h>

int main(void)
{
	int i, n, t;
	int fibo[41] = {0, 1};
	scanf("%d", &t);
	for(int i=2; i < 41; i++)
	{
		if(fibo[i] == 0) fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	for(int i=0; i < t; i++)
	{
		scanf("%d", &n);
		if(n == 0) printf("1 0\n");
		else printf("%d %d\n", fibo[n - 1], fibo[n]);
	}
}