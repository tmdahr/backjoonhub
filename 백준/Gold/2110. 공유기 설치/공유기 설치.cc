#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1000002];

int main(void)
{
	int n, c, ans=0;
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; i++) scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int left=1, right=arr[n-1];
	while(left<=right)
	{
		int mid = (left+right)/2;
		int cnt=1;
		int prev = arr[0];
		for(int i=1; i<n; i++)
		{
			if(arr[i]-prev>=mid)
			{
				cnt++;
				prev = arr[i];
			}
		}
		
		if(cnt>=c)
		{
			ans=max(ans,mid);
			left=mid+1;
		}
		else right=mid-1;
	}
	printf("%d",ans);
	
	return 0;
}