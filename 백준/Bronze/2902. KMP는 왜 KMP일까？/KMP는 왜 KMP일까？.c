#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, m;
	char n[100];
	
	scanf("%s", n);
	m = strlen(n);
	for(i=0; i<m; i++)
	{
		if(n[i] > 64 && n[i] < 91) printf("%c", n[i]);
	}
	
	return 0;
}