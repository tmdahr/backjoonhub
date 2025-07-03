#include <stdio.h>
#include <string.h>

// 큰 수를 문자열로 저장하고 2를 곱하는 함수
void multiply_by_2(char *num) {
    int carry = 0;
    int len = strlen(num);
    for (int i = 0; i < len; i++) {
        int digit = num[i] - '0';
        digit = digit * 2 + carry;
        carry = digit / 10;
        num[i] = (digit % 10) + '0';
    }
    if (carry > 0) {
        num[len] = carry + '0';
        num[len + 1] = '\0';
    }
}

// 1을 빼는 함수 (2^n - 1 계산용)
void subtract_1(char *num) {
    int len = strlen(num);
    int i = 0;
    while (i < len && num[i] == '0') i++;
    if (i < len) {
        num[i]--;
        for (int j = 0; j < i; j++) {
            num[j] = '9';
        }
    }
}

// 큰 수 출력 (역순으로 저장되어 있으므로 뒤집어서 출력)
void print_big_number(char *num) {
    int len = strlen(num);
    int start = len - 1;
    while (start >= 0 && num[start] == '0') start--;
    if (start < 0) {
        printf("0");
        return;
    }
    for (int i = start; i >= 0; i--) {
        printf("%c", num[i]);
    }
}

void hanoi(int n, int from_pos, int to_pos, int aux_pos)
{
    if(n == 1)
    {
        printf("%d %d\n", from_pos, to_pos);
        return ;
    }
    hanoi(n-1, from_pos, aux_pos, to_pos);
    printf("%d %d\n", from_pos, to_pos);
    hanoi(n-1, aux_pos, to_pos, from_pos);
}

int main(void) {
    int n;
    scanf("%d", &n);

    // 2^n 계산 (문자열로 처리)
    char result[1000] = "1"; // 초기값: 1 (2^0)
    for (int i = 0; i < n; i++) {
        multiply_by_2(result);
    }

    // 2^n - 1 계산
    subtract_1(result);

    // 결과 출력
    print_big_number(result);
    printf("\n");

    // n ≤ 20일 때만 이동 과정 출력
    if (n <= 20) {
        hanoi(n, 1, 3, 2);
    }

    return 0;
}