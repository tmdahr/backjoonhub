#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 200000
#define LEN 501

char words[MAX][LEN];
char result[MAX][LEN];

int compare(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    int N, M, total, i, res_cnt = 0;

    scanf("%d %d", &N, &M);
    total = N + M;

    for (i = 0; i < total; i++) {
        scanf("%s", words[i]);
    }

    // 사전순 정렬
    qsort(words, total, LEN, compare);

    // 인접한 단어 비교로 중복 확인
    for (i = 1; i < total; i++) {
        if (strcmp(words[i], words[i - 1]) == 0) {
            // 이전 단어와 같으면 중복
            // 중복되는 첫 단어만 저장 (중복 1회만 인정)
            if (res_cnt == 0 || strcmp(result[res_cnt - 1], words[i]) != 0) {
                strcpy(result[res_cnt++], words[i]);
            }
        }
    }

    printf("%d\n", res_cnt);
    for (i = 0; i < res_cnt; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
