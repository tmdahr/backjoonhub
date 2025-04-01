#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, t, r, l, m, k;
	char s[20];
	scanf("%d", &t);
	for(i=0; i<t; i++)
	{
		scanf("%d", &r);
		getchar();
		gets(s);
		m = strlen(s);
		for(l=0; l<m; l++)
		{
			for(k=0; k<r; k++) printf("%c", s[l]);
		}
		printf("\n");
	}
	
	return 0;
}