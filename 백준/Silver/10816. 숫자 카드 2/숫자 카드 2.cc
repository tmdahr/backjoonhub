#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[500002];

int serch(int key, int l, int r)
{
	int mid, left, right, start, end;
	
	left=l;
	right=r;
	while(left<right)
	{
		mid = (left+right)/2;
		if(key<=arr[mid]) right=mid;
		else left = mid+1;
	}
	start=right;
	
	left=l;
	right=r;
	while(left<right)
	{
		mid = (left+right)/2;
		if(key<arr[mid]) right=mid;
		else left = mid+1;
	}
	end=right;
	
	return end-start;
}

int main(void)
{
	int n, m, i, k, c;
	
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr,arr+n);
	scanf("%d", &m);
	for(i=0; i<m; i++)
	{
		scanf("%d", &k);
		c = serch(k,0,n);
		printf("%d ", c);
	}
	
	return 0;
}