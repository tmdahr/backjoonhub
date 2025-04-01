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
	cur->prev = newnode;
}

int main(void)
{
	char key[1000000];
	int l, tc, i;
	
	init();
	scanf("%d", &tc);
	
	for(; tc>0; tc--)
	{
		scanf("%s", key);
		l = strlen(key);
		
		for(i=0; i<l; i++)
		{
			if(key[i]=='<')
			{
				if(cur!=head->next) cur = cur->prev;
			}
			else if(key[i]=='>')
			{
				if(cur!=tail) cur=cur->next;
			}
			else if(key[i]=='-')
			{
				if(cur!=head->next)
				{
					cur->prev->prev->next=cur;
					cur->prev=cur->prev->prev;
				}
			}
			else
			{
				insert(key[i]);
			}
		}
		
		cur=head->next;
		while(cur!=tail)
		{
			printf("%c", cur->data);
			cur=cur->next;
		}
		printf("\n");
		init();
	}
	
	return 0;
}