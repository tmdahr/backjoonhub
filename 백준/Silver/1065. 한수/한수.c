#include <stdio.h>
#include <string.h>
int main(void)
{
	int n, i, l, m;
	char t[6];
	scanf("%d", &n);
	
	if(n<100) m=n;
	else if(100 < n) m=99;
	for(i=100; i<=n; i++)
	{
		if(i>999)
		{
			t[1] = i/1000;
			t[2] = i/100-(i/1000)*10;
			t[3] = i/10-(i/100)*10;
			t[4] = i-(i/10)*10;
		}
		else
		{
			t[1] = i/100;
			t[2] = i/10-(i/100)*10;
			t[3] = i-(i/10)*10;
		}
		for(l=0; l<10; l++) 
		{
			if(t[2]-t[1]==l&&t[3]-t[2]==l&&t[4]-t[3]==l)
			{
				m++;
				break;
			}
			else if(t[2]-t[1]==l&&t[3]-t[2]==l)
			{
				m++;
				break;
			}
		}
		for(l=-1; l>-10; l--) 
		{
			if(t[2]-t[1]==l&&t[3]-t[2]==l&&t[4]-t[3]==l)
			{
				m++;
				break;
			}
			else if(t[2]-t[1]==l&&t[3]-t[2]==l)
			{
				m++;
				break;
			}
		}
	}
	printf("%d", m);
	
	return 0;
}