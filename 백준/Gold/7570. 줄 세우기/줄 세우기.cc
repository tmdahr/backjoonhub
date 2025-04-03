#include<stdio.h>

int p, N, arr[1000001], ans;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &ans);
		arr[ans] = arr[ans - 1] + 1;
		if (arr[ans] > p) p = arr[ans];
	}
	printf("%d", N - p);
	return 0;
}