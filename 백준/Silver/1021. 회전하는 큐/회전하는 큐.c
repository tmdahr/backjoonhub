#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
	struct _node *prev;
}node;
node *head;
node *tail;
node *cur;

void init()
{
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	
	head->data=0;
	head->prev=tail;
	
	tail->data=0;
	tail->next=head;
	
	cur = head;
}

void insert(int data)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
	newnode->prev=cur;
	
	cur->next=newnode;
	cur=cur->next;
}

void ak1()
{
	cur=head->next;
	head->next=cur->next;
	cur->next->prev=head;
}

void ak2(int n)
{
	cur=head->next;
	int temp=cur->data;
	for(int i=0; i<n-1; i++)
	{
		cur->data=cur->next->data;
		cur=cur->next;
	}
	tail->prev->data=temp;
}

void ak3(int n)
{
	cur=tail->prev;
	int temp=cur->data;
	for(int i=0; i<n-1; i++)
	{
		cur->data=cur->prev->data;
		cur=cur->prev;
	}
	head->next->data=temp;
}

int main(void)
{
	int n, m, i, num, t1, t2, t;
	scanf("%d %d", &n, &m);
	
	init();
	for(i=1; i<=n; i++) insert(i);
	cur->next=tail;
	tail->prev=cur;
	
	t=0;
	while(m!=0)
	{
		scanf("%d", &num);
		t1=0;
		t2=0;
		
		cur=head->next;
		while(cur->data!=num)
		{
			t1++;
			if(cur->data==num) break;
			cur=cur->next;
		}
		cur=tail->prev;
		while(cur->data!=num)
		{
			t2++;
			if(cur->data==num) break;
			cur=cur->prev;
		}
		t2++;
		
		
		if(t1==0)
		{
			ak1();
			n--;
		}
		else if(t2==0)
		{
			t++;
			ak3(n);
			ak1();
			n--;
		}
		else if(t1<t2)
		{
			for(i=0; i<t1; i++) ak2(n);
			t += i;
			ak1();
			n--;
		}
		else
		{
			for(i=0; i<t2; i++) ak3(n);
			t += i;
			ak1();
			n--;
		}
		
		m--;
	}
	
	printf("%d", t);
	
	return 0;
}