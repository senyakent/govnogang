#include <iostream>
#include "gtest/gtest.h"

int main() {
    double x;
    std::cout << "Vvedite x=";
    std::cin >> x;
    double c = x * x;
    double y = 69 * c + 8;
    double z = (23 * c + 32) * x;
    std::cout << "Znachenie virozheniya 23х^3+69x^2+32x+8=" << y + z << "\n";
    std::cout << "Znachenie virozheniya -23х^3+69x^2-32x+8=" << y - z;
    return 0;
}
