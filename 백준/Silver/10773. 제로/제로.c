#include <stdio.h>
int main(void)
{
	int n[100000];
	int k=0, i, m=0, l;
	scanf("%d",&l);
	for(i=0; i<l; i++)
	{
		scanf("%d",&n[k]);
		if(n[k]==0) k--;
		else k++;
	}
	for(i=0; i<k; i++) 
	{
		m=m+n[i];
	}
	printf("%d",m);
	
	return 0;
}