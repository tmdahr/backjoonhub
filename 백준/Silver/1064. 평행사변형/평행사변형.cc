#include <cstdio>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double cross(const Point &a, const Point &b, const Point &c) {
    return (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
}

double dist(const Point &a, const Point &b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

int main(void) {
    Point A, B, C;
    scanf("%lf %lf %lf %lf %lf %lf", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y);

    if(fabs(cross(A, B, C)) < 1e-12) {
        printf("-1.0\n");
        return 0;
    }

    double dAB = dist(A, B);
    double dBC = dist(B, C);
    double dAC = dist(A, C);

    double per1 = 2.0 * (dAB + dAC);
    double per2 = 2.0 * (dAB + dBC);
    double per3 = 2.0 * (dAC + dBC);

    double maxPer = per1;
    if(per2 > maxPer) maxPer = per2;
    if(per3 > maxPer) maxPer = per3;

    double minPer = per1;
    if(per2 < minPer) minPer = per2;
    if(per3 < minPer) minPer = per3;

    double answer = maxPer - minPer;
    printf("%.10f\n", answer);
    return 0;
}