#include <stdio.h>

int r,c,cnt=0;

void solution(int h, int w, int n)
{
	if(h==r&&w==c&&n==1) printf("%d", cnt);
	else
	{
		int num=n*n/4;
		if(r<n/2+h)
		{
			if(c<n/2+w) solution(h,w,n/2);
			else
			{
				cnt+=num;
				solution(h,w+n/2,n/2);
			}
		}
		else
		{
			if(c<n/2+w)
			{
				cnt+=num*2;
				solution(h+n/2,w,n/2);
			}
			else
			{
				cnt+=num*3;
				solution(h+n/2,w+n/2,n/2);
			}
		}
	}
	return;
}

int main(void)
{
	int n,num=1;
	scanf("%d %d %d", &n, &r, &c);
	for(int i=0; i<n; i++) num = num*2;
	solution(0,0,num);
	
	return 0;
}