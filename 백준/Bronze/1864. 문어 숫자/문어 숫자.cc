#include <stdio.h>
#include <string.h>

int val(char c){
    switch(c){
        case '-': return 0;
        case '\\': return 1;
        case '(': return 2;
        case '@': return 3;
        case '?': return 4;
        case '>': return 5;
        case '&': return 6;
        case '%': return 7;
        case '/': return -1;
    }
    return 0;
}

int main(void) {
    char s[100];
    
    while(1){
        scanf("%s", s);
        if(strcmp(s, "#")==0) break;
        
        long long result = 0;
        int len = strlen(s);
        
        for(int i=0;i<len;i++)
            result = result * 8 + val(s[i]);
        
        printf("%lld\n", result);
    }
    return 0;
}