#include <iostream>

double sqrt(double x) {
    double low, high;
    if (x >= 1) {
        low = 1;
        high = x;
    } else {
        low = x;
        high = 1;
    }
    while (high - low > 1e-9) {
        double mid = (high + low) / 2;
        if (mid * mid >= x) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low;
}

const double pi = 3.141592653589793;

double sin_taylor(double x) {
    double term = x;
    double sum = term;
    double x_squared = x * x;
    for (int n = 1; n < 20; ++n) {
        term *= -x_squared / ((2 * n) * (2 * n + 1));
        sum += term;
    }
    return sum;
}

double arcsin(double x) {
    double low, high;
    if (x == 1)
        return 1.570796326794897;
    if (x == -1)
        return -1.570796326794897;
    if (x == 0)
        return 0;
    low = -1.570796326794897;
    high = 1.570796326794897;
    while (high - low > 1e-13) {
        double mid = (high + low) / 2;
        double sin_mid = sin_taylor(mid);
        if (sin_mid <= x)
            low = mid;
        else
            high = mid;
    }
    return low;
}

double deg(double rad) {
    return (rad * 180) / pi;
}

int main() {
    double x1, x2, y1, y2, x3, y3;
    std::cout << "Введите координаты x1,y1= ";
    std::cin >> x1 >> y1;
    std::cout << "Введите координаты x2,y2= ";
    std::cin >> x2 >> y2;
    std::cout << "Введите координаты x3,y3= ";
    std::cin >> x3 >> y3;
    double a1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)); // стороны
    double a2 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    double a3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    long double P = (a1 + a2 + a3) / 2; // пер
    long double p = (a1 + a2 + a3) / 2; // полупер
    long double l = p * (p - a1) * (p - a2) * (p - a3);
    long double h1 = 2 / a1 * sqrt(l); // высоты
    long double h2 = 2 / a2 * sqrt(l);
    long double h3 = 2 / a3 * sqrt(l);
    l = a2 * 2 * a2 + 2 * a3 * a3 - a1 * a1;
    long double m1 = sqrt(l) / 2; // медианы
    l = 2 * a1 * a1 + 2 * a3 * a3 - a2 * a2;
    long double m2 = sqrt(l) / 2;
    l = a1 * 2 * a1 + 2 * a2 * a2 - a3 * a3;
    long double m3 = sqrt(l) / 2;
    l = a2 * a3 * (a1 + a2 + a3) * (a3 + a2 - a1); //найдем бисс
    long double b1 = 1 / (a2 + a3) * sqrt(l);
    l = a1 * a3 * (a1 + a2 + a3) * (a3 + a1 - a2);
    long double b2 = 1 / (a1 + a3) * sqrt(l);
    l = a2 * a1 * (a1 + a2 + a3) * (a1 + a2 - a3);
    long double b3 = 1 / (a2 + a1) * sqrt(l);
    long double S = 0.5 * a1 * h1; // площадь высота на сторону
    long double R = (a1 * a2 * a3) / (4 * S); // рад опис
    long double r = S / p; // рад вписан
    long double SO = pi * R * R; // площади и периметры окр
    long double PO = 2 * pi * R;
    long double So = pi * r * r;
    long double Po = 2 * pi * r;
    long double ra1 = arcsin(a1 / (2 * R)); // углы в рад
    long double ra2 = arcsin(a2 / (2 * R));
    long double ra3 = arcsin(a3 / (2 * R));
    if (a1 >= a2 & a1 >= a3) {
        ra1 = pi - (ra2 + ra3);
    } else if (a2 >= a1 & a2 >= a3) {
        a2 = pi - (ra1 + ra2);
    } else if (a3 >= a1 & a3 >= a2) {
        ra3 = pi - (ra1 + ra2);
    }
    std::cout << "все стороны треугольника = " << a1 << " " << a2 << " " << a3 << std::endl;
    std::cout << "все высоты треугольника = " << h1 << " " << h2 << " " << h3 << std::endl;
    std::cout << "все медианы треугольника = " << m1 << " " << m2 << " " << m3 << std::endl;
    std::cout << "все биссектрисы треугольника = " << b1 << " " << b2 << " " << b3 << std::endl;
    std::cout << "радиальная мера углов = " << ra1 << " " << ra2 << " " << ra3 << std::endl;
    std::cout << "градусная мера углов = " << deg(ra1) << " " << deg(ra2) << " " << deg(ra3) << std::endl;
    std::cout << "радиус описанной окружности = " << R << " радиус вписанной окружности = " << r << std::endl;
    std::cout << "S и P описанной = " << SO << " " << PO << std::endl;
    std::cout << "S и P вписанной = " << So << " " << Po << std::endl;
    std::cout << "S и P треугольника = " << S << " " << P << std::endl;
    return 0;
}
