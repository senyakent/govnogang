#include <iostream>

int main() {
    double a, b, c, x;
    int N;
    std::cout << "Введите N=";
    std::cin >> N;
    a = -13.8;
    b = 8.9;
    c = 25.0;
    x = 0;
    switch (N) {
        case 1: x = b * c - pow(a, 2);
            break;
        case 56: x = b * c;
            break;
        case 7: x = pow(a, 7) + c;
            break;
        case 3: x = a - b * c;
            break;
        default: x = pow(a + b, 3);
    }
    std::cout << "Y = " << x;
    return 0;
}
