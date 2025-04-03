#include <stdio.h>

int heap[100000];
int size=1, next, target, temp;

void push(int data)
{
	target = size;
	heap[size++] = data;
	while(heap[target]>heap[target/2])
	{
		if(target==1) break;
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
				next = heap[target*2] > heap[target*2+1] ? target*2 : target*2+1;
			}
			else next = target*2;
		}
		else break;
		
		if(heap[target]<heap[next])
		{
			temp = heap[target];
			heap[target] = heap[next];
			heap[next] = temp;
			target = next;
			if(target>size) break;
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