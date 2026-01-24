#include <stdio.h>
#include <string.h>

int main(void) {
    int K;
    char s[1001];
    
    scanf("%d", &K);
    scanf("%s", s);
    
    int len = strlen(s);
    int row = len / K;
    
    char table[100][100];
    int idx = 0;
    
    for(int i = 0; i < row; i++) {
        if(i%2 == 0)
            for(int j=0; j<K; j++)
                table[i][j] = s[idx++];
        else
            for(int j=K-1; j>=0; j--)
                table[i][j] = s[idx++];
    }
    
    for(int j=0; j<K; j++) {
        for(int i=0; i<row; i++)
            putchar(table[i][j]);
    }
    return 0;
}
