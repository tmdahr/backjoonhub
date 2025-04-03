#include <stdio.h>
int main(void)
{
	char n[21]={0}, m[21];
	int i, j=0, x=0;
	scanf("%s", n);
	for(i=20; i>=0; i--)
	{
		m[j] = n[i];
		j++;
	}
	for(i=20; i>=0; i--)
	{
		if(n[i]!='\0') break;
	}
	for(j=20; j>=20-i; j--)
	{
		if(n[i]!=m[j]) x++;
		i--;
	}
	if(x!=0) printf("false");
	else printf("true");
	
	return 0;
}