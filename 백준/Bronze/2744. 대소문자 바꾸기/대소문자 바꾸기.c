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
		if(n[i] >= 97) n[i] = n[i] - 32;
		else if (n[i] <= 90) n[i] = n[i] + 32;
	}
	puts(n);
	
	return 0;
}