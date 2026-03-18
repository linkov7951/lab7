Задача 1 (zadanie1.cpp)
Полный код:
```
include <stdio.h>
include <stdlib.h>

void swapInt(int x, int y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

int main() {
    system("chcp 65001 > nul");
    
    int a = 5, b = 10;
    printf("До обмена: a = %d, b = %d\n", a, b);
    swapInt(&a, &b);
    printf("После обмена: a = %d, b = %d\n", a, b);
    
    return 0;
}
```

 Как работает:
1. Подключение библиотек:
- `include <stdio.h>` - нужна для функции `printf` (вывод на экран)
- `include <stdlib.h>` - нужна для функции `system` (выполнение команд ОС)
 2. Функция `system("chcp 65001 > nul");`
- `chcp 65001` - команда Windows для смены кодировки на UTF-8
- `> nul` - скрывает сообщение о смене кодировки
- Это нужно, чтобы русский текст в `printf` отображался правильно
 3. Функция `swapInt`
```
void swapInt(int x, int y) {
    x = x + y;    // Шаг 1: x = сумма
    y = x - y;    // Шаг 2: y = сумма - старое y = старое x
    x = x - y;    // Шаг 3: x = сумма - старое x = старое y
}
```
4. Вызов в `main`
```
int a = 5, b = 10;
swapInt(&a, &b);  // &a - взятие адреса переменной a
```
- `&a` - операция взятия адреса переменной a
- Функция получает адреса и меняет значения по этим адресам
Задача 2 (zadanie2.cpp)
Полный код:
```
include <stdio.h>
include <math.h>
include <stdlib.h>

double f1(double x) {
    return sin(x) / x;
}

double f2(double y) {
    return y  y + 2  pow(y, 1.5);
}

double f3(double z) {
    return (z + 2)  (z + 1)  z;
}

void print(double x, double (func)(double)) {
    printf("%f\n", func(x));
}

double R(double x, double y, double z) {
    return f1(x) + f2(y)  f3(f2(z));
}

int main() {
    system("chcp 65001 > nul");
    
    double x = 0.6, y = 0.3, z = 0.1;
    double result = R(x, y, z);
    printf("%f\n", result);
    
    return 0;
}
```
Как работает:
1. Подключение `math.h`
- Эта библиотека содержит математические функции: `sin`, `pow`
 2. Функция `f1`
```
double f1(double x) {
    return sin(x) / x;
}
```
- Вычисляет sin(x) и делит на x
- Принимает double, возвращает double
3. Функция `f2`
```
double f2(double y) {
    return y  y + 2  pow(y, 1.5);
}
```
- `y  y` - это y²
- `pow(y, 1.5)` - возведение в степень 1.5 (y^(3/2))
- Умножаем на 2 и складываем
4. Функция `f3`
```
double f3(double z) {
    return (z + 2)  (z + 1)  z;
}
```
- Просто перемножает три числа: (z+2), (z+1) и z
5. Функция `print` - 
```
void print(double x, double (func)(double)) {
    printf("%f\n", func(x));
}
```
(0.1, f3);  // напечатает f3(0.1)
```
6. Функция `R`
```
double R(double x, double y, double z) {
    return f1(x) + f2(y)  f3(f2(z));
}
```
Вычисляет по формуле: f1(x) + f2(y)  f3(f2(z))
Порядок вычислений:
1. Сначала `f2(z)` - получаем число
2. Это число передаём в `f3` - получаем `f3(f2(z))`
3. Умножаем на `f2(y)`
4. Прибавляем `f1(x)`
Задача 3 (zadanie3.cpp)
Полный код:
```
include <iostream>
include <cmath>
include <cstdlib>
using namespace std;

double max(double arr[], int k) {
    double m = arr[0];
    for(int i = 1; i < k; i++) {
        if(arr[i] > m) m = arr[i];
    }
    return m;
}

double min(double arr[], int k) {
    double m = arr[0];
    for(int i = 1; i < k; i++) {
        if(arr[i] < m) m = arr[i];
    }
    return m;
}

int main() {
    system("chcp 65001 > nul");
    
    double arr1[] = {3.5, 1.2, 7.8, 2.3, 9.1};
    double arr2[] = {4.1, 6.7, 0.9, 5.4};
    
    int k1 = 5, k2 = 4;
    
    double min1 = min(arr1, k1);
    double min2 = min(arr2, k2);
    double max1 = max(arr1, k1);
    double max2 = max(arr2, k2);
    
    double proizvedenie = min1  min2;
    double srednee = sqrt(max1  max2);
    
    cout << proizvedenie << endl;
    cout << srednee << endl;
    
    return 0;
}
```
Как работает:
1. Подключение библиотек C++
- `include <iostream>` - для `cout` (вывод в C++)
- `include <cmath>` - для `sqrt` (квадратный корень)
- `using namespace std;` - чтобы не писать std::cout
2. Функция `max`
```
double max(double arr[], int k) {
    double m = arr[0];        // Берём первый элемент как начальный максимум
    for(int i = 1; i < k; i++) {  // Проходим по остальным элементам
        if(arr[i] > m) m = arr[i];  // Если нашли больше - запоминаем
    }
    return m;  // Возвращаем максимум
}
```
Как работает цикл:
- `i = 1` начинаем со второго элемента (первый уже в m)
- `i < k` пока i меньше размера массива
- `i++` увеличиваем i на 1 после каждого шага
- Сравниваем каждый элемент с текущим максимумом
3. Функция `min` работает аналогично, только ищет минимум
4. В `main`
```
double arr1[] = {3.5, 1.2, 7.8, 2.3, 9.1};  // Создаём массив из 5 чисел
double arr2[] = {4.1, 6.7, 0.9, 5.4};       // Создаём массив из 4 чисел

int k1 = 5, k2 = 4;  // Размеры массивов

// Находим минимумы и максимумы
double min1 = min(arr1, k1);
double min2 = min(arr2, k2);
double max1 = max(arr1, k1);
double max2 = max(arr2, k2);

// Вычисления
double proizvedenie = min1  min2;           // Произведение минимумов
double srednee = sqrt(max1  max2);          // Среднее геометрическое

cout << proizvedenie << endl;  // Вывод с переводом строки
cout << srednee << endl;
```
Задача 4 (zadanie4.cpp)
Полный код:
```
include <stdio.h>
include <math.h>
include <stdlib.h>

double sum1(double x, double e) {
    double s = 0, t;
    int n = 1;
    do {
        t = pow(x, 2n - 1) / (2n - 1);
        s = s + t;
        n++;
    } while(t >= e || -t >= e);
    return s;
}

void sum2(double x, double e, double r) {
    r = 0;
    double t;
    int n = 1;
    do {
        t = pow(x, 2n - 1) / (2n - 1);
        r = r + t;
        n++;
    } while(t >= e || -t >= e);
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
```
Как работает:
1. Что такое ряд?
Ряд - это сумма последовательности чисел:
- n=1: x¹/1
- n=2: x³/3
- n=3: x⁵/5
- n=4: x⁷/7 и так далее
Общая формула: x^(2n-1)/(2n-1)
2. Первый способ - `sum1` (по значению)
```
double sum1(double x, double e) {
    double s = 0, t;    // s - сумма, t - текущий член
    int n = 1;           // начинаем с n=1
    do {
        t = pow(x, 2n - 1) / (2n - 1);  // вычисляем член
        s = s + t;                         // добавляем к сумме
        n++;                                // переходим к следующему n
    } while(t >= e || -t >= e);  // продолжаем пока |t| >= e
    return s;  // возвращаем сумму
}
```
Условие `t >= e || -t >= e` - это проверка модуля:
- Если t положительное: проверяем t >= e
- Если t отрицательное: проверяем -t >= e
- Проще было бы `fabs(t) >= e`, но для простоты написали так
 3. Второй способ - `sum2` (через указатель)
```
void sum2(double x, double e, double r) {
    r = 0;              // по адресу r записываем 0
    double t;
    int n = 1;
    do {
        t = pow(x, 2n - 1) / (2n - 1);
        r = r + t;     // добавляем к значению по адресу r
        n++;
    } while(t >= e || -t >= e);
    // ничего не возвращаем (void)
}
```
Отличие от первого способа:
- Не использует `return`
- Результат записывается прямо в переменную, адрес которой передали
- `r` - разыменование указателя (работа с переменной)
4. В `main`
```
double x = 0.20;
double e = 0.5e-4;  // это 0.5  10⁻⁴ = 0.00005

// Первый способ
double r1 = sum1(x, e);    // получаем результат через return
printf("%f\n", r1);

// Второй способ
double r2;
sum2(x, e, &r2);           // передаём адрес r2, функция сама запишет туда значение
printf("%f\n", r2);
```
Что происходит при вызове `sum2(x, e, &r2)`:
- `x` и `e` копируются в функцию
- `&r2` - передаётся адрес переменной r2
- Внутри функции `r` - это и есть переменная r2
- Когда пишем `r = 0`, меняется r2
- Когда пишем `r = r + t`, читаем и меняем r2
