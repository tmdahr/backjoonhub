#include <stdio.h>
int main(void)
{
	int n[100];
	int i, l, m;
	scanf("%d", &l);
	for(i=0; i<l; i++) scanf("%d", &n[i]);
	m = n[0];
	for(i=1; i<l; i++)
	{
		if(n[i-1] != 0 && n[i] == 1) 
		{
			n[i] = n[i-1] + 1;
		}
		m = m + n[i];
	}
	printf("%d", m);
	
	return 0;
}