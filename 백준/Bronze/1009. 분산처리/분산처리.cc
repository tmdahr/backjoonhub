#include<stdio.h>
int main(void)
{
	int t; 
	scanf("%d", &t);
	while(t--)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		int task = a;
		for (int j = 1; j < b; j++) task = task * a %10;
		if (task % 10== 0) printf("%d\n", 10);
		else printf("%d\n", task % 10);
	}
    return 0;
}