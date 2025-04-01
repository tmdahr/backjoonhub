#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, m;
	char s[1000];
	
	scanf("%s", s);
	m = strlen(s);
	for(i=0; i<m; i++)
	{
		s[i] = s[i] - 3;
		if(s[i]<65) s[i] = s[i] + 26;
	}
	printf("%s", s);
	
	return 0;
}