#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll arr[1000002];
ll n, m, ans;

void high(ll start, ll end)
{
	while(start<=end)
	{
		ll count=0;
		ll mid = (start+end)/2;
		for(int i=0; i<n; i++)
			if(arr[i]>mid) count+=(arr[i]-mid);
			
		if(count>=m)
		{
			start=mid+1;
			if(ans<mid) ans = mid;
		}
		else end = mid-1;
	}
}

int main(void)
{
	scanf("%lld %lld", &n, &m);
	for(int i=0; i<n; i++) scanf("%lld", &arr[i]);
	sort(arr,arr+n);
	high(1,arr[n-1]);
	printf("%lld", ans);
	
	return 0;
}