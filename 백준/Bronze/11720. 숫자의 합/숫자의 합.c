#include <stdio.h>

int main(void)
{
	int i, m, l = 0;
	char n[100]={0};

	scanf("%d", &m);
	getchar();
	gets(n);
	for(i=0; i<m; i++)
	{
		l = l + n[i]-48;
	}
	printf("%d", l);
	
	return 0;
}