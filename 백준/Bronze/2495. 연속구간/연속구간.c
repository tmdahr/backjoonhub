#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, j=1, m=0;
	char n[8];
	for(l=0; l<3; l++)
	{
		scanf("%s", n);
		for(i=1; i<=8; i++)
		{
			if(n[i]==n[i-1]) j++;
			else if(j!=0)
			{
				if(j>m) m = j;
				j=1;
			}
		}
		if(m==0) m=8;
		printf("%d\n", m);
		j=1;
		m=0;
	}
	
	return 0;
}