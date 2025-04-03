#include <stdio.h>
int main(void)
{
	char n[80];
	int i, l, j, m = 0, nm;
	scanf("%d", &l);
	
	for(j=0; j<l; j++)
	{
		scanf(" %s", n);
		for(i=0; i<80; i++) 
		{
			if(n[i]=='O')
			{
				for(nm=0; nm<=i; nm++)
				{
					if(n[i-nm]=='O') m++;
					else break;
				}
			}
			else if(n[i]=='\0') break;
		}
		printf("%d\n", m);
		m=0;
	}
	
	return 0;
}