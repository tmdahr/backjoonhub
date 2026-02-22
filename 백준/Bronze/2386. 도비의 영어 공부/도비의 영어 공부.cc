#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char line[1000];

    while(fgets(line, sizeof(line), stdin)) {
        if(line[0] == '#') break;

        char target = tolower(line[0]);
        int count = 0;

        for(int i=2; line[i] != '\0'; i++)
            if(tolower(line[i]) == target)
                count++;

        printf("%c %d\n", target, count);
    }
    return 0;
}