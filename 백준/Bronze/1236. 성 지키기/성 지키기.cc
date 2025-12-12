#include <stdio.h>

char map[51][51];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) scanf("%s", map[i]);

    int rowNeed = 0, colNeed = 0;

    for(int i=0; i<n; i++) {
        int hasGuard = 0;
        for(int j=0; j<m; j++) {
            if(map[i][j] == 'X') {
                hasGuard = 1;
                break;
            }
        }
        if(!hasGuard) rowNeed++;
    }

    for(int j=0; j<m; j++) {
        int hasGuard = 0;
        for(int i=0; i<n; i++) {
            if(map[i][j] == 'X') {
                hasGuard = 1;
                break;
            }
        }
        if(!hasGuard) colNeed++;
    }

    int result = rowNeed > colNeed ? rowNeed : colNeed;
    printf("%d\n", result);

    return 0;
}