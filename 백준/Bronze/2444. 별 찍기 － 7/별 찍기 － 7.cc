#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	n*=2;
	int J = n/2-1;
	int K=1;
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<J; j++) printf(" ");
		for(int k=0; k<K; k++) printf("*");
		printf("\n");
		if(i>=n/2)
		{
			J++;
			K-=2;
		}
		else
		{
			J--;
			K+=2;
		}
	}
	return 0;
}