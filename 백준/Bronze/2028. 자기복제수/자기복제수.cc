#include <stdio.h>
#include <string.h>

int main(void) {
    int T;
    scanf("%d", &T);

    while(T--) {
        char n[20];
        scanf("%s", n);

        long long num = 0;
        for(int i=0; n[i]; i++) num = num * 10 + (n[i] - '0');
        long long sq = num * num;

        char sq_str[40];
        sprintf(sq_str, "%lld", sq);

        int len_n = strlen(n);
        int len_sq = strlen(sq_str);

        if(len_sq >= len_n && strcmp(n, sq_str + len_sq - len_n) == 0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}