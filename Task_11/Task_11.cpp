#include <iostream>

int main() {
    int h1, m1, h2, m2, h, m;
    std::cout << "Введите время начала решения задач= ";
    std::cin >> h1 >> m1;
    std::cout << "Введите время конца решения задач= ";
    std::cin >> h2 >> m2;
    m = m2 - m1;
    h = h2 - h1;
    if (m < 0) {
        h = --h;
        m = 60 + m;
        std::cout << "Введите время решения задач= " << h << ":" << m << std::endl;
    } else {
        std::cout << "Введите время решения задач= " << h << ":" << m << std::endl;
    }
    return 0;
}
