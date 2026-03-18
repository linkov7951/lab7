#include <stdio.h>
#include <stdlib.h> // Для system()

// Для целых чисел (через XOR)
void swapInt(int* x, int* y) {
    if (*x != *y) {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

// Для вещественных чисел (через сложение/вычитание)
void swapDouble(double* x, double* y) {
    if (*x != *y) {
        *x = *x + *y;
        *y = *x - *y;
        *x = *x - *y;
    }
}

int main() {
    system("chcp 65001 > nul"); // Установка UTF-8 для русского языка

    int a = 5, b = 10;
    printf("До обмена (int): a = %d, b = %d\n", a, b);
    swapInt(&a, &b);
    printf("После обмена (int): a = %d, b = %d\n\n", a, b);

    double c = 3.14, d = 2.71;
    printf("До обмена (double): c = %.2f, d = %.2f\n", c, d);
    swapDouble(&c, &d);
    printf("После обмена (double): c = %.2f, d = %.2f\n", c, d);

    return 0;
}