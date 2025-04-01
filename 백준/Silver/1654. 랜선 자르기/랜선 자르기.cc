#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[1000002];
int k, n;
ll ans=0;

void solution(ll start, ll end)
{
	while(start<=end)
	{
		
		ll count=0;
		ll mid = (start+end)/2;
		for(int i=0;i<k;i++)
		{
			if(arr[i]>=mid)
			{
				count += (arr[i]/mid);
			}
		}
		
		if(count>=n)
		{
			start = mid+1;
			if(ans<mid||ans==0) ans = mid;
		}
		else end = mid-1;
	}
}

int main(void)
{
	scanf("%d %d", &k, &n);
	for(int i=0; i<k; i++) scanf("%lld", &arr[i]);
	sort(arr, arr+k);
	solution(1,arr[k-1]);
	printf("%lld",ans);
	
	return 0;
}