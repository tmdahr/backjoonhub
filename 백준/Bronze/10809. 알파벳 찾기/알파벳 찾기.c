#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, r=97, l, m, n = -1;
	char s[100];
	scanf("%s", s);
	
	m = strlen(s);
	for(i=0; i<26; i++)
	{
		for(l=0; l<m; l++)
		{
			if(r==s[l])
			{
				printf("%d ", l);
				break;
			}
			else if(l==m-1) 
			{
				printf("-1 ");
				break;
			}
		}
		r++;
	}
	
	return 0;
}