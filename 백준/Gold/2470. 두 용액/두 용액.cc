#include <stdio.h>
#include <algorithm>
using namespace std;

int sum(int n, int m)
{
	if(n+m<0) return -1*(n+m);
	else return n+m;
}

int main(void)
{
	int n, left, right, t, m, ml, mr;
	int num[100002];
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%d", &num[i]);
	sort(num, num+n);
	
	left=0;
	right=n-1;
	m=sum(num[left],num[right]);
	ml = left;
	mr = right;
	
	while(left<right)
	{
		if(sum(num[left+1],num[right])<sum(num[left],num[right-1])) left++;
		else right--;
		if(left==right) break;
		t=sum(num[left],num[right]);
		if(t<m)
		{
			m=t;
			ml = left;
			mr = right;
			
			if(t==0) break;
		}
	}
	printf("%d %d", num[ml], num[mr]);
	
	return 0;
}