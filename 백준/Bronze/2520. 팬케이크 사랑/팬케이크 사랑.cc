#include <stdio.h>

int main(void) {
    int t;
    if(scanf("%d", &t) == EOF) return 0;

    while(t--) {
        double cm, y, ssu, ssa, f;
        double b, gs, gc, w;

        if(scanf("%lf %lf %lf %lf %lf", &cm, &y, &ssu, &ssa, &f) == EOF) break;
        if(scanf("%lf %lf %lf %lf", &b, &gs, &gc, &w) == EOF) break;

        double x = cm / 8.0;
        if(y / 8.0 < x) x = y / 8.0;
        if(ssu / 4.0 < x) x = ssu / 4.0;
        if(ssa / 1.0 < x) x = ssa / 1.0;
        if(f / 9.0 < x) x = f / 9.0;

        long long max_dough = (long long)(16.0 * x + 1e-9); 
        long long max_toppings = (long long)b + (long long)(gs / 30) + (long long)(gc / 25) + (long long)(w / 10);
        long long result = (max_dough < max_toppings) ? max_dough : max_toppings;

        printf("%lld\n", result);
    }

    return 0;
}