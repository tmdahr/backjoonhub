#include <stdio.h>
int main(void)
{
	int n[8];
	int i, a = 0, d = 0;
	for(i=0; i<8; i++)
	{
		scanf("%d", &n[i]);
	}
	for(i=0; i<8; i++)
	{
		if(n[i] == i+1) a++;
		else if(n[i] == 8-i) d++;
	}
	if(a==8) printf("ascending");
	else if(d==8) printf("descending");
	else printf("mixed");
	
	return 0;
}