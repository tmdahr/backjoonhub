#include <stdio.h>

typedef struct _node
{
	char left;
	char right;
}node;
node tree[30];

void preorder(char c)
{
	if(c=='.') return;
	
	printf("%c", c);
	preorder(tree[c].left);
	preorder(tree[c].right);
}
void inorder(char c)
{
	if(c=='.') return;
	
	inorder(tree[c].left);
	printf("%c", c);
	inorder(tree[c].right);
}
void postorder(char c)
{
	if(c=='.') return;
	
	postorder(tree[c].left);
	postorder(tree[c].right);
	printf("%c", c);
}

int main(void)
{
	int n, i;
	char t, l, r;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf(" %c %c %c", &t, &l, &r);
		tree[t].left = l;
		tree[t].right = r;
	}
	preorder('A');
	printf("\n");
	inorder('A');
	printf("\n");
	postorder('A');
	
	return 0;
}