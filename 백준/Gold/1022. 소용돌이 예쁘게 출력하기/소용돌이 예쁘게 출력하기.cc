#include <cstdio>
#include <cstring>

int mapArr[50][5] = {0,};
int r1, c1, r2, c2;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// 숫자 길이 구하기 (itoa 없이 직접 구현)
int digit_len(int x) {
    int cnt = 0;
    while(x > 0) {
        x /= 10;
        cnt++;
    }
    return cnt == 0 ? 1 : cnt;
}

void makeMap() {
    int offset = 0;
    int num = 1;
    int count = 0;
    int x = 0, y = 0;

    while(true) {
        // 정사각형 범위 내부
        if(-offset <= x && x <= offset && -offset <= y && y <= offset) {
            if(r1 <= x && x <= r2 && c1 <= y && y <= c2) {
                mapArr[x - r1][y - c1] = num;
                if(++count == (r2 - r1 + 1) * (c2 - c1 + 1)) return;
            }
            num++;
        }

        int k = 0;
        while(k < 4) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(-offset <= nx && nx <= offset && -offset <= ny && ny <= offset) {
                if(r1 <= nx && nx <= r2 && c1 <= ny && ny <= c2) {
                    mapArr[nx - r1][ny - c1] = num;
                    if(++count == (r2 - r1 + 1) * (c2 - c1 + 1)) return;
                }
                x = nx;
                y = ny;
                num++;
            } 
            else k++;
        }

        offset++;
        y += 1;
    }
}

int findDigit() {
    int maxNum = -1;
    for(int i=0; i<= r2 - r1; i++)
        for(int j = 0; j <= c2 - c1; j++)
            if(mapArr[i][j] > maxNum) 
                maxNum = mapArr[i][j];
    return digit_len(maxNum);
}

void printSolution() {
    int digit = findDigit();

    for(int i=0; i<= r2 - r1; i++) {
        for(int j=0; j<= c2 - c1; j++) {
            int size = digit_len(mapArr[i][j]);

            // 앞 공백 처리
            for(int k = 0; k < digit - size; k++) printf(" ");

            // 마지막 값은 뒤에 공백 X
            if(j == c2 - c1) printf("%d", mapArr[i][j]);
            else printf("%d ", mapArr[i][j]);
        }
        printf("\n");
    }
}


int main(void) {
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    makeMap();
    printSolution();
    return 0;
}