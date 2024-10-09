#include <iostream>

int main() {
    int a, b, n;
    std::cout << "введите значение целых a=";
    std::cin >> a;
    std::cout << "введите значение целого b=";
    std::cin >> b;
    std::cout << "введите количество шагов=";
    std::cin >> n;
    std::cout << "содержимое ячеек памяти = " << a << "|" << b << std::endl;
    for (int i = 1; i <= n; i++) {
        std::cout << a << " * " << b << " = " << a * b << std::endl;
        a = ++a;
        b = ++b;
    }
    return 0;
}
