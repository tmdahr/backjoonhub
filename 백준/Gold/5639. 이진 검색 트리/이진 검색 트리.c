#include <stdio.h>

typedef struct _node
{
	int data;
	struct _node *left;
	struct _node *right;
}node;
node *root;
node *cur;

void init()
{
	root = (node*)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
}

void push(int data)
{
	int n=0;
	cur = root;
	node *before;
	while(1)
	{
		if(cur==NULL)
		{
			node *newnode=(node*)malloc(sizeof(node));
			
			newnode->data = data;
			newnode->left = NULL;
			newnode->right = NULL;
			
			if(n==0)
				before->left = newnode;
			else
				before->right = newnode;
			
			break;
		}
	 	
		if(cur->data > data)
		{
			before = cur;
			cur = cur->left;
			n=0;
		}
		else
		{
			before = cur;
			cur = cur->right;
			n=1;
		}
	}
}

void postorder(node *now)
{
	if(now==NULL) return;
		
	postorder(now->left);
	postorder(now->right);
	printf("%d\n",now->data);
}

int main(void)
{
	int data;
	
	init();
	scanf("%d", &data);
	root->data = data;
	
	while(1)
	{
		int res = scanf("%d", &data);
		if(res == -1) break;
		push(data);
	}
	postorder(root);
	
	return 0;
}