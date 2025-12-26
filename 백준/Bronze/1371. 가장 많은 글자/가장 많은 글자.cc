#include <stdio.h>

int main(void) {
    int cnt[26] = {0};
    int c;

    while((c = getchar()) != EOF)
        if(c >= 'a' && c <= 'z') cnt[c - 'a']++;

    int max = 0;
    for(int i=0; i<26; i++)
        if(cnt[i] > max) max = cnt[i];

    for(int i=0; i<26; i++)
        if(cnt[i] == max) putchar('a' + i);

    return 0;
}