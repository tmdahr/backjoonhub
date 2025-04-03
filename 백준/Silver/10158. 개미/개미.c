#include <stdio.h>
int main(void)
{
	int w, h, p, q, t, pp = 1, qq = 1, tp, tq;
	scanf("%d %d", &w, &h);
	scanf("%d %d", &p, &q);
	scanf("%d", &t);
	
	tp = t % (w * 2);
	for(; tp > 0; tp--)
	{
		if(p == w)
		{
			pp = -1;
		}
		if(p == 0)
		{
			pp = 1;
		}
		p = p + pp;
	}
	
	tq = t % (h * 2);
	for(; tq > 0; tq--)
	{
		if(q == h)
		{
			qq = -1;
		}
		if(q == 0)
		{
			qq = 1;
		}
		q = q + qq;
	}
	
	printf("%d %d", p, q);
	
	return 0;
}