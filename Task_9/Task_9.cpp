#include <iostream>
#include <cmath>

int main() {
    double a, b, x, y, z;
    int N;
    std::cout << "Введите a=";
    std::cin >> a;
    std::cout << "Введите b=";
    std::cin >> b;
    std::cout << "Введите z=";
    std::cin >> z;
    if (z > 0) {
        x = 1 / pow(z, 2) + 2 * z;
    } else {
        x = 1 - pow(z, 3);
    }
    std::cout << "Выберите с каким значением x будет выполняться ф-ция" << '\n';
    std::cout << "1->2x 2->x^3 3->x/3 n=";
    std::cin >> N;
    switch (N) {
        case 1: x *= 2;
            y = (2.5 * a * exp(-3 * x) - 4 * b * x * x) / (log(fabs(x)) + x);
            std::cout << "ваше значение ф-ции при f(x)=2x= " << y << std::endl;
            break;
        case 2: x = x * x * x;
            y = (2.5 * a * exp(-3 * x) - 4 * b * x * x) / (log(fabs(x)) + x);
            std::cout << "ваше значение ф-ции при f(x)=x^3= " << y << std::endl;
            break;
        case 3: x /= 3;
            y = (2.5 * a * exp(-3 * x) - 4 * b * x * x) / (log(fabs(x)) + x);
            std::cout << "ваше значение ф-ции при f(x)=x/3= " << y << std::endl;
            break;
        default: std::cout << "такого варианта нету елы палы";
    }
    return 0;
}
