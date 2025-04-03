#include <stdio.h>

int main(void)
{
	int n, m;
	scanf("%d", &n);
	
	for (m = n - 1; m >= 1; m--)
	{
		n = n * m;
	}
	if(n == 0)
	{
		n++;
	}
	printf("%d", n);
	
	return 0;
}