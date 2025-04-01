#include <stdio.h>

int main(void)
{
	int i, n;
	char a[3], b[3];
	scanf("%s %s", a, b);
	
	for(i=2; i>=0; i--)
	{
		if(a[i]-48>b[i]-48) 
		{
			for(i=2; i>=0; i--) printf("%c", a[i]);
			break;
		}
		else if(a[i]-48<b[i]-48) 
		{
			for(i=2; i>=0; i--) printf("%c", b[i]);
			break;	
		}
	} 
	
	return 0;
}