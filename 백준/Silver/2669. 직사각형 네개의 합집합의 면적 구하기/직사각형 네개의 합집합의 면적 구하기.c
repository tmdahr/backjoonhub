#include <stdio.h>
int main(void)
{
	int n[100][100]={0,};
	int i, l, x, y, j, k, m, p=0;
	
	for(m=0; m<4; m++)
	{
		scanf("%d %d %d %d", &x, &y, &j, &k);
		for(i=x; i<j; i++)
		{
			for(l=y; l<k; l++)
			{
				if(n[i][l]!=1) p++;
				n[i][l]=1;
			}
		}
	}
	printf("%d", p);
	
	return 0;
}