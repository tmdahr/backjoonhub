#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[1001], s2[1001];
    int c1[26] = {0}, c2[26] = {0};
    
    scanf("%s", s1);
    scanf("%s", s2);
    
    for(int i=0; s1[i]; i++) c1[s1[i] - 'a']++;
    
    for(int i=0; s2[i]; i++) c2[s2[i] - 'a']++;
    
    int result = 0;
    for(int i=0; i<26; i++) {
        int diff = c1[i] - c2[i];
        if(diff < 0) diff = -diff;
        result += diff;
    }
    
    printf("%d\n", result);
    return 0;
}
