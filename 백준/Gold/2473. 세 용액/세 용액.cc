#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll sum(ll i, ll n, ll m)
{
	if(i+n+m<0) return -1*(i+n+m);
	else return i+n+m;
}

int main(void)
{
	int n, l, r, ml, mr, mi;
	ll t, mt;
	ll num[5002];
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%lld", &num[i]);
	sort(num, num+n);
	
	mi=0;
	ml = mi+1;
	mr = n-1;
	mt=sum(num[mi],num[ml],num[mr]);
	for(int i=0;i<n-2;i++)
	{
		l=i+1;
		r=n-1;
		while(l<r)
		{
			t=sum(num[i],num[l],num[r]);
			if(t<mt)
			{
				mt=t;
				ml = l;
				mr = r;
				mi = i;
				if(mt==0) break;
			}
			if(sum(num[i],num[l+1],num[r])<sum(num[i],num[l],num[r-1])) l++;
			else r--;
		}
	}
	
	printf("%lld %lld %lld", num[mi], num[ml], num[mr]);
	
	return 0;
}