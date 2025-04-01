#include <stdio.h>
typedef long long ll;
ll n,k;

	ll cnt=0;
	

int main(void)
{
	ll left, right, mid, ans;
	scanf("%lld %lld", &n, &k);
	left=1;
	right=n*n;
	
	while(left<=right)
	{
		mid=(left+right)/2;
		ll cnt = 0;
		for(int i=1; i<=n; i++)
		{
			if(i*n<mid) cnt+=n;
			else cnt+=mid/i;
		}
		if(cnt < k) left=mid+1;
		else
		{
			ans = mid;
			right = mid-1;
		}
	}
	printf("%lld", ans);
	
	return 0;
}