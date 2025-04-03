#include <stdio.h>
int main(void)
{
	int count[10002]={0};
	int n, i, l;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &l);
		count[l]++;
	}
	for(i=0; i<=10000; i++)
	{
		for(l=0; l<count[i]; l++)
		{
			printf("%d\n", i);
		}
	}
	
	return 0;
}