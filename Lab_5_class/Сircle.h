

#include <iostream>
#include <math.h> 


class �ircle {
    int R;
    int x;
    int y;

public:
    �ircle(int& r) {
        R = r;
    }
    �ircle(int& x_, int& y_) {
        x = x_;
        y = y_;
    }
    �ircle() {
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
        std::cout << "(" << x << ", " << y << ") - ���������� ������\n" << R << " - ������ �����������\n";
        std::cout << circle_length() << " - ����� ����������\n";
        std::cout << circle_square() << " - ������� ����������\n";

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
