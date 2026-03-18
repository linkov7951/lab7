#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1(double x) {
    return sin(x) / x;
}

double f2(double y) {
    return y * y + 2 * pow(y, 1.5);
}

double f3(double z) {
    return (z + 2) * (z + 1) * z;
}

void print(double x, double (*func)(double)) {
    printf("%f\n", func(x));
}

double R(double x, double y, double z) {
    return f1(x) + f2(y) * f3(f2(z));
}

int main() {
    system("chcp 65001 > nul");

    double x = 0.6, y = 0.3, z = 0.1;
    double result = R(x, y, z);
    printf("%f\n", result);

    return 0;
}