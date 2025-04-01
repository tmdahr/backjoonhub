#include <stdio.h>

typedef struct _node{
	int num;
	int pr;
}node;

int n, m, f = 0, r = 0;
node q[102];

int next(int p)
{
	if(p==n) return 0;
	else return p+1;
}
node pop()
{
	f = next(f);
	return q[f];
}
void push(node data)
{
	r = next(r);
	q[r] = data;
}

int main(void)
{
	int tc, i, l, t;
	node data;
	
	scanf("%d", &tc);
	for(i=0; i<tc; i++)
	{
		t=0;
		f=0;
		r=0;
		scanf("%d %d", &n, &m);
		for(l=0; l<n; l++)
		{
			scanf("%d", &data.pr);
			//if(h<data.pr) h = data.pr;
			data.num = l;
			push(data);
		}
		
		while(1)
		{
			int flag=0;
			int copy_f = f;
			int copy_r = r;
			int ppr = q[next(copy_f)].pr;
			
			while(copy_f != copy_r)
			{
				copy_f = next(copy_f);
				if(ppr<q[copy_f].pr)
				{
					flag=1;
					break;		
				}
			}
			if(flag==1) push(pop()); 
			else
			{
				t++;
				data = pop();
				if(data.num == m)
				{
					printf("%d\n", t);
					break;
				}
			} 
		}
	}
	
	return 0;
}