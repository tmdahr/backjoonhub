#include <stdio.h>
int main(void)
{
	int n,i;
	scanf("%d", &n);
	int p[21] = {0,1};
	
	for(i = 2; i < 21; i++)
	{
		p[i] = p[i-2] + p[i-1];
	}
	n = p[n];
	printf("%d", n);
	
	return 0;
}