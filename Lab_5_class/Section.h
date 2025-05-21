#include <iostream>
#include <math.h> 



class Section {
    int x;
    int y;
    int z;


public:
    Section(int x_P, int y_P, int z_P) {
        x = x_P;
        y = y_P;
        z = z_P;
    }
    Section() {
        x = 0;
        y = 0;
        z = 0;
    }


    void print()
    {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
    void set_Point(const int& x_s, const int& y_s, const int& z_s) {
        x = x_s;
        y = y_s;
        z = z_s;
    }
    float sum(Section point2)
    {
        float sum;
        sum = sqrt((x - point2.x) * (x - point2.x) + (y - point2.y) * (y - point2.y) + (z - point2.z) * (z - point2.z));
        return sum;
    }
    float sum(int x_2, int y_2, int z_2)
    {
        float sum;
        sum = sqrt((x - x_2) * (x - x_2) + (y - y_2) * (y - y_2) + (z - z_2) * (z - z_2));
        return sum;
    }

};
