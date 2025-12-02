#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[100001], b[100001];
	long long sum = 0;
	scanf("%s %s", a, b);
	int alen = strlen(a);
	int blen = strlen(b);
	for(int i=0; i<alen; i++)
        for(int j=0; j<blen; j++)
            sum += (int)(a[i]-48) * (int)(b[j]-48);
	printf("%lld", sum);
	return 0;
}