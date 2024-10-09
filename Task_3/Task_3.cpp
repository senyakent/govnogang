#include <iostream>

int main() {
    double b1;
    std::cout << "Vvedite b1: ";
    std::cin >> b1;
    double q = 1 / 12.0;
    double S;
    S = b1 / (1 - q);
    std::cout << "summa progressii = " << S;
    return 0;
}
