#include <stdio.h>

int main()
{
	int i, n, t;
	int fibo[41] = {0, 1};
	scanf("%d", &t);
	i = 2;
	while (i < 41)
	{
		if (fibo[i] == 0)
		{
			fibo[i] = fibo[i - 1] + fibo[i - 2];
		}
		i++;
	}
	i = 0;
	while (i < t)
	{
		scanf("%d", &n);
		if (n == 0)
			printf("1 0\n");
		else 
			printf("%d %d\n", fibo[n - 1], fibo[n]);
		i++;
	}
}