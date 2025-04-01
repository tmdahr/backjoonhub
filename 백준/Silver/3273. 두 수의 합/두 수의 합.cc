#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int num[100002];
	int x, i, j, n, cnt=0;
	
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &num[i]);
	scanf("%d", &x);
	sort(num,num+n);
	
	int left = 0;
	int right = n-1;
	
	while(left<right)
	{
		if(num[left]+num[right]==x)
		{
			cnt++;
			left++;
			right--;
		}
		
		else if(num[left]+num[right]<x)
		{
			left++;
		}
		else if(num[left]+num[right]>x)
		{
			right--;
		}
	}
	printf("%d", cnt);
}