#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
	struct _node *next;
	struct _node *prev;
	char data;
}node;
node *head;
node *tail;
node *cur;

void init()
{
	head = (node*)malloc(sizeof(node));
	tail = (node*)malloc(sizeof(node));
	head->data='o';
	head->next = tail;
	tail->data='o';
	tail->prev = head;
	cur=tail;
}

void insert(char data)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->prev = cur->prev;
	cur->prev->next = newnode;
	newnode->next = cur;
	cur->prev=newnode;
}

int main(void)
{
	char n[100000];
	int m, i, len;
	char c, p;
	
	init();
	scanf("%s", n);
	len = strlen(n);
	for(i=0; i<len; i++) insert(n[i]);
	scanf("%d", &m);
	
	for(i=0;i<m;i++)
	{
		scanf(" %c", &c);
		if(c=='L'&&cur!=head->next)
		{
			cur = cur->prev;
		}
		else if(c=='D'&&cur!=tail)
		{
			cur=cur->next;
		}
		else if(c=='B'&&cur!=head->next)
		{
			cur->prev->prev->next=cur;
			cur->prev=cur->prev->prev;
		}
		else if(c=='P')
		{
			scanf(" %c", &p);
			insert(p);
		}
	}
	
	cur=head->next;
	while(cur!=tail)
	{
		printf("%c", cur->data);
		cur=cur->next;
	}
	
	return 0;
}