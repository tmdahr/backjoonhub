#include <stdio.h>
int main(void)
{
	int num[1002];
	int i, l, t, n;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &num[i]);
	for(i=0; i<n-1; i++)
	{
		for(l=i+1; l<n; l++)
		{
			if(num[i]>num[l])
			{
				t=num[i];
				num[i]=num[l];
				num[l]=t;
			}
		}
	}
	for(i=0; i<n; i++) printf("%d\n", num[i]);
	
	return 0;
}