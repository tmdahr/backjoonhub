#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    char *S = (char*)malloc(M + 1);
    scanf("%s", S);
    
    int p = 0;
    int result = 0;
    
    for(int i = 1; i < M - 1; i++)
    {
        if(S[i-1] == 'I' && S[i] == 'O' && S[i+1] == 'I')
        {
            p++;
            if(p >= N) result++;
            i++;
        }
        else p = 0;
    }
    
    printf("%d\n", result);
    free(S);
    return 0;
}