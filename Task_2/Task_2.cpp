#include <iostream>


int main() {
    double x, y, z;
    std::cout << "Vvedite x, y, z:";
    std::cin >> x >> y >> z;
    if (x + y > z & x + z > y & z + y > x) {
        std::cout << "takoy treugolnik suchestvuet";
    } else {
        std::cout << "takoy trugolnik ne suchestvuet";
    }
    return 0;
}
