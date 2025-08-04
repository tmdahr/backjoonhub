#include <stdio.h>

#define MAX 100000

int inorder[MAX];
int postorder[MAX];
int pos_inorder[MAX+1];
int N;

void preorder(int in_start, int in_end, int post_start, int post_end)
{
    if(in_start > in_end || post_start > post_end) return;

    int root = postorder[post_end];
    printf("%d ", root);

    int root_idx = pos_inorder[root];
    int left_size = root_idx - in_start;

    preorder(in_start, root_idx-1, post_start, post_start+left_size-1);
    preorder(root_idx+1, in_end, post_start+left_size, post_end-1);
}

int main(void)
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &inorder[i]);
        pos_inorder[inorder[i]] = i;
    }
    for(int i=0; i<N; i++) scanf("%d", &postorder[i]);

    preorder(0, N-1, 0, N-1);
    printf("\n");

    return 0;
}