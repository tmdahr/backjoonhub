#include <cstdio>
#include <cstring>

int main(void) {
    int n;
    scanf("%d", &n);

    int cnt[26] = {0};
    char name[31];

    while(n--) {
        scanf("%s", name);
        cnt[name[0] - 'a']++;
    }

    bool printed = false;
    for(int i=0; i<26; i++) {
        if(cnt[i] >= 5) {
            putchar('a' + i);
            printed = true;
        }
    }

    if(!printed) printf("PREDAJA");

    return 0;
}
