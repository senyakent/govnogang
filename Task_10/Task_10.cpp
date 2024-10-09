#include <iostream>

int main() {
    double x1, x2, y1, y2, r1, r2, l;
    long double ogranichenie = 1e-9;
    long double left, right;
    long double mid;
    std::cout << "Введите координаты M1 x1,y1= ";
    std::cin >> x1 >> y1;
    std::cout << "Введите координаты r1= ";
    std::cin >> r1;
    std::cout << "Введите координаты M2 x2,y2= ";
    std::cin >> x2 >> y2;
    std::cout << "Введите координаты r2= ";
    std::cin >> r2;
    bool T = false;
    l = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    left = 0;
    right = l;
    while (right - left > ogranichenie) {
        mid = (left + right) / 2;
        if (mid * mid <= l) {
            left = mid;
        } else {
            right = mid;
        }
    }
    l = right;
    if (r1 < r2 && r2 > (l - r1) + 2 * r1) {
        T = true;
        std::cout << "M1 лежит в M2" << "\n";
    } else if (r1 > r2 && r1 > (l - r2) + 2 * r2) {
        T = true;
        std::cout << "M2 лежит в M1" << "\n";
    } else if (l == 0 && r1 > r2) {
        T = true;
        std::cout << "M2 лежит в M1" << "\n";
    } else if (l == 0 && r2 > r1) {
        T = true;
        std::cout << "M2 лежит в M1" << "\n";
    } else if (l < r1 + r2 && T == false) {
        std::cout << "Фигуры пересекаются" << "\n";
    } else {
        std::cout << "Фигуры не пересекаются" << "\n";
    }
    return 0;
}
