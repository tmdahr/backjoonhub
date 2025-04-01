#include <stdio.h>
int main(void)
{
	int i, j, x, y, n, m, k, num1, num2, l, p, il=0, jl=0;
	int num[305][305];
	
	scanf("%d %d", &n, &m);
	for(num1=1; num1<=n; num1++)
	{
		for(num2=1; num2<=m; num2++)
		{
			scanf(" %d", &num[num1][num2]);
		}
	}
	scanf("%d", &k);
	for(l=0; l<k; l++)
	{
		p=0;
		scanf("%d %d %d %d", &i, &j, &x, &y);
		for(il=i; il<=x; il++)
		{
			for(jl=j; jl<=y; jl++)
			{
				p+=num[il][jl];
			}
		}
		printf("%d\n", p);
	}
	return 0;
}