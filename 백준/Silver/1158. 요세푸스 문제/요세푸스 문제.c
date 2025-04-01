#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int q[5002];
	int n, k, i, l, r, f, t;
	
	scanf("%d %d", &n, &k);
	for(i=0; i<n; i++) q[i] = i+1;
	f = n;
	r = 0;
	
	printf("<");
	for(i=0; i<n; i++)
	{
		for(l=0; l<k-1; l++)
		{
			t = q[r];
			if(r==n) r=0;
			else r++;
			q[f] = t;
			if(f==n) f=0;
			else f++;
		}
		printf("%d", q[r]);
		if(r==n) r=0;
		else r++;
		if(i!=n-1) printf(", ");
		else
		{
			printf(">");
			break;
		}
	}
	
	return 0;
}