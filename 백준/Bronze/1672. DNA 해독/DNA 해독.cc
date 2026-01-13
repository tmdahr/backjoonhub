#include <stdio.h>
#include <string.h>

int main(void) {
    int N;
    scanf("%d", &N);

    char s[1000001];
    scanf("%s", s);

    char table[4][4] = {
        {'A','C','A','G'},
        {'C','G','T','A'},
        {'A','T','C','G'},
        {'G','A','G','T'}
    };

    for(int i=N-1; i>0; i--) {
        char a = s[i-1];
        char b = s[i];

        int x, y;
        if(a=='A') x=0;
        else if(a=='G') x=1;
        else if(a=='C') x=2;
        else x=3;

        if(b=='A') y=0;
        else if(b=='G') y=1;
        else if(b=='C') y=2;
        else y=3;

        s[i-1] = table[x][y];
    }

    printf("%c\n", s[0]);
    return 0;
}