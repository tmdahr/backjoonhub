#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, m, l;
	char n[260];
	while(1)
	{
		l=0;
		gets(n);
		m = strlen(n);
		if (strcmp(n, "#") == 0) break;
		for(i=0; i<m; i++)
		{
			
			if(n[i]==65||n[i]==69||n[i]==73||n[i]==79||n[i]==85) l++;
			if(n[i]==97||n[i]==101||n[i]==105||n[i]==111||n[i]==117) l++;
		}
		printf("%d\n", l);
	}
	
	return 0;
}