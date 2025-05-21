

#include <iostream>
#include <math.h> 


class Сircle {
    int R;
    int x;
    int y;

public:
    Сircle(int& r) {
        R = r;
    }
    Сircle(int& x_, int& y_) {
        x = x_;
        y = y_;
    }
    Сircle() {
        R = 0;
        x = 0;
        y = 0;
    }
    double circle_length() {
        return(2 * 3.14 * R);
    }
    double circle_square() {
        return((3.14 * (R * R)) / 2);
    }
    void print() {
        std::cout << "(" << x << ", " << y << ") - координаты центра\n" << R << " - радиус окуружности\n";
        std::cout << circle_length() << " - длина окружности\n";
        std::cout << circle_square() << " - площадь окружности\n";

    }
    void set_R() {
        int r;
        std::cout << "input R...";
        std::cin >> r;
        R = r;
    }
    void set_cord() {
        int x_, y_;

        std::cout << "input x...";
        std::cin >> x_;
        x = x_;
        std::cout << "input y...";
        std::cin >> y_;
        y = y_;
    }
    
};
