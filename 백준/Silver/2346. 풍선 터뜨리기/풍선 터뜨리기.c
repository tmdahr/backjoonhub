#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int data;
	int c;
	struct _node *next;
	struct _node *prev;
}node;
node *head;
node *tail;
node *cur;

void init()
{
	head=(node*)malloc(sizeof(node));
	tail=(node*)malloc(sizeof(node));
	
	head->data = 0;
	head->next = tail;
	head->prev = tail;
	
	tail->data = 0;
	tail->next = head;
	
	cur = head;
}

void insert(int data)
{
	node *newnode=(node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->prev = cur;
	
	cur->next = newnode;
	cur = cur->next;
}

int main()
{
	int n, m, t;
	init();
	scanf("%d", &n);
	
	for(m=1; m<=n; m++) insert(m);
	cur->next = tail;
	tail->prev = cur;
	
	cur=head->next;
	for(m=0; m<n; m++)
	{
		scanf("%d", &cur->c);
		cur=cur->next;
	}
	
	cur = head->next;
	t=0;
	while(n!=0)
	{
		if(t>0)
		{
			for(m=0; m<t-1; m++)
			{
				cur = cur->next;
				if(cur==tail) cur = cur->next->next;
			}
		}
		else if(t<0)
		{
			for(m=0; m>t; m--)
			{
				cur = cur->prev;
				if(cur==head) cur = cur->prev->prev;
			}
		}
		printf("%d ",cur->data);
		n--;
		if(n==0) break;
		t=cur->c;
		cur->next->prev=cur->prev;
		cur->prev->next=cur->next;
		cur=cur->next;
		if(cur==tail) cur = cur->next->next;
	}
	
	return 0;
}