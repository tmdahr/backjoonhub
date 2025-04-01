#include <stdio.h>

int n, t, f = 0, r = 0;
int q[500002];

int next(int p)
{
	if(p==n) return 0;
	else return p+1;
}
int pop()
{
	f = next(f);
	return q[f];
}
void push(int data)
{
	r = next(r);
	q[r] = data;
}

int main(void)
{
	int i;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++) push(i);
	
	for(i=0; i<n-1; i++)
	{
		t = pop();
		t = pop();
		push(t);
	}
	printf("%d", q[r]);
	
	return 0;
}