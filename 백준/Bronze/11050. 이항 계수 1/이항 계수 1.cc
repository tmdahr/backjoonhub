#include <stdio.h>
int main(void)
{
	int n,k,com = 1;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < k; i++)
    {
		com *= n;
		n--;
	}
	for(int i = k; i > 0; i--) com /= i;
	printf("%d\n", com);
	return 0;
}