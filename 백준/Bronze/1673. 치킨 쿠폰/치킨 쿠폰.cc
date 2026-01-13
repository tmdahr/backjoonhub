#include <stdio.h>

int main(void) {
    long long n, k;
    while(scanf("%lld %lld", &n, &k) == 2) {
        long long coupon = n;
        long long stamp = 0;
        long long total = 0;

        while(coupon > 0) {
            total += coupon;          // 현재 가진 쿠폰으로 모두 주문
            stamp += coupon;          // 주문 수만큼 도장 적립
            coupon = stamp / k;       // 교환 가능한 새 쿠폰
            stamp %= k;               // 남은 도장
        }

        printf("%lld\n", total);
    }
    return 0;
}