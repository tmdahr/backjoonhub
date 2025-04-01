#include <stdio.h>
int main(void)
{
	int n[9];
	int i, l, n9=0, m, j;
	for(i=0; i<9; i++)
	{
		scanf("%d", &n[i]);
		n9 = n9 + n[i];
	}
	m = n9 - 100;
	for(i=0; i<9; i++)
	{
		for(l=0; l<9; l++)
		{
			if(l==i) l++;
			else if(n[i] + n[l] == m)
			{
				n[i]=0;
				n[l]=0;
				
			}
			if(n[l]==0) break;
		}
		if(n[i]==0) break;
	}
	for(i=0; i<9; i++)
	{
		for(l=0; l<9; l++)
		{
			if(n[l] > n[l+1])
			{
				j = n[l];
				n[l] = n[l+1];
				n[l+1] = j;
			}
		}
	}
	for(i=3; i<=9; i++)
	{
		printf("%d\n", n[i]);
	}
	return 0;
}