#include <stdio.h>
typedef struct _node
{
	int num;
	int max;
} node;
int top=-1;
node stack[500002];

int empty()
{
	if(top==-1) return 1;
	return 0;
}

int main()
{
	int n, h, i;
	scanf("%d", &n);
	
	for(i=1; i<=n; i++)
	{
		scanf("%d", &h);
		while(empty()==0)
		{
			if(stack[top].max>h)
			{
				printf("%d ", stack[top].num);
				break;
			}
			top--;
		}
		if(empty()==1) printf("0 ");
		node temp = {i,h};
		stack[++top]=temp;
	}
	
	return 0;
}