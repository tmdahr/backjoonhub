#include <stdio.h>

int abs(int data)
{
	if(data<0)
		return data*-1;
	return data;
}

int heap[100000];
int size=1, next, target, temp;

void push(int data)
{
	target = size;
	heap[size++] = data;
	while(abs(heap[target]) < abs(heap[target/2]) || (abs(heap[target]) == abs(heap[target/2]) && heap[target] < 0))
	{
		temp = heap[target];
		heap[target] = heap[target/2];
		heap[target/2] = temp;
		target = target/2;
	}
}

int pop()
{
	int res = heap[1];
	heap[1] = heap[--size];
	target = 1;
	while(1)
	{
		if(target*2<size)
		{
			if(target*2+1<size)
			{
				if(abs(heap[target*2]) == abs(heap[target*2+1]))
				{
					if(heap[target*2] == heap[target*2+1]) next = target*2;
					else next = heap[target*2] < heap[target*2+1] ? target*2 : target*2+1;
				}
				else next = abs(heap[target*2]) < abs(heap[target*2+1]) ? target*2 : target*2+1;
			}
			else next = target*2;
		}
		else break;
		
		if(abs(heap[target]) > abs(heap[next]) || (abs(heap[target]) == abs(heap[next]) && heap[next] < 0))
		{
			temp = heap[target];
			heap[target] = heap[next];
			heap[next] = temp;
			target = next;
		}
		else break;
	}
	
	return res;
}

int main(void)
{
	int n, x;
	
	scanf("%d", &n);
	while(n>0)
	{
		scanf("%d", &x);
		if(x==0)
		{
			if(size==1) printf("0\n");
			else printf("%d\n", pop());
		}
		else push(x);
		
		n--;
	}
	
	return 0;
}