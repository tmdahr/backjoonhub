#include <cstdio>

int main(void) {
    int n;
    scanf("%d", &n);

    int original = n;
    int count = 0;

    do {
        int a = n / 10;
        int b = n % 10;
        int sum = a + b;

        n = (b * 10) + (sum % 10);
        count++;
    } while(n != original);

    printf("%d\n", count);
    return 0;
}
