#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double sum1(double x, double e) {
    double s = 0, t;
    int n = 1;
    do {
        t = pow(x, 2 * n - 1) / (2 * n - 1);
        s = s + t;
        n++;
    } while (t >= e || -t >= e);
    return s;
}

void sum2(double x, double e, double* r) {
    *r = 0;
    double t;
    int n = 1;
    do {
        t = pow(x, 2 * n - 1) / (2 * n - 1);
        *r = *r + t;
        n++;
    } while (t >= e || -t >= e);
}

int main() {
    system("chcp 65001 > nul");

    double x = 0.20;
    double e = 0.5e-4;

    double r1 = sum1(x, e);
    printf("%f\n", r1);

    double r2;
    sum2(x, e, &r2);
    printf("%f\n", r2);

    return 0;
}