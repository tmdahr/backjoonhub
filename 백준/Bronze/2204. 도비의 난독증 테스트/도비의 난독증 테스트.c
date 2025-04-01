#include <stdio.h>
#include <string.h>

int main(void)
{
	int n=1, i, l, m;
	char s1[20], s2[20], s12[20], s22[20];
	
	while(n!=0)
	{
		scanf("%d", &n);
		if(n==0) break;
		scanf("%s", s1);
		m = strlen(s1);
		strcpy(s12, s1);
		for(l=0; l<m; l++) if(s1[l] < 97) s1[l] = s1[l] + 32;
		for(i=1; i<n; i++)
		{
			scanf("%s", s2);
			m = strlen(s2);
			strcpy(s22, s2);
			for(l=0; l<m; l++) if(s2[l] < 97) s2[l] = s2[l] + 32;
			if(strcmp(s1, s2) > 0) 
			{
				strcpy(s1,s2);
				strcpy(s12,s22);
			}
		}
		printf("%s\n", s12);
	}
	
	return 0;
}