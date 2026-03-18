#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double max(double arr[], int k) {
    double m = arr[0];
    for (int i = 1; i < k; i++) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

double min(double arr[], int k) {
    double m = arr[0];
    for (int i = 1; i < k; i++) {
        if (arr[i] < m) m = arr[i];
    }
    return m;
}

int main() {
    system("chcp 65001 > nul");

    double arr1[] = { 3.5, 1.2, 7.8, 2.3, 9.1 };
    double arr2[] = { 4.1, 6.7, 0.9, 5.4 };

    int k1 = 5, k2 = 4;

    double min1 = min(arr1, k1);
    double min2 = min(arr2, k2);
    double max1 = max(arr1, k1);
    double max2 = max(arr2, k2);

    double proizvedenie = min1 * min2;
    double srednee = sqrt(max1 * max2);

    cout << proizvedenie << endl;
    cout << srednee << endl;

    return 0;
}