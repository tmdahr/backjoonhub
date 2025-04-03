#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, j, o=0;
	char a[100005], b[100005] ,n[100005] = {'0',};
	for(i=0; i<100005; i++) n[i] = '0';
	scanf("%s %s", a, b);
	if(strlen(a) > strlen(b))
	{
		i = strlen(a);
		j = strlen(a) - strlen(b);
		for(l=0; i>=0; i--)
		{
			if(i-j < 0) n[l] = n[l] + a[i]-'0';
			else n[l] = n[l] + a[i]-'0' + b[i-j]-'0';
			if(n[l]>'9')
			{
				n[l+1] = '1';
				n[l] = n[l] - 10;
			}
			l++;
		}
	}
	else
	{
		i = strlen(b);
		j = strlen(b) - strlen(a);
		for(l=0; i>=0; i--)
		{
			if(i-j < 0) n[l] = n[l] + b[i]-'0';
			else n[l] = n[l] + a[i-j]-'0' + b[i]-'0';
			if(n[l]>'9')
			{
				n[l+1] = '1';
				n[l] = n[l] - 10;
			}
			l++;
		}
	}
	l = strlen(n) -1;
	for(; l>0; l--)
	{
		if(n[l] > '0') o=1;
		if(o==1) printf("%c", n[l]);
	}
	
	return 0;
}