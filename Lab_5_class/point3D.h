#include <iostream>
#include <cmath>

class Point3D {
    int x;
    int y;
    int z;

public:
    Point3D(int x_P, int y_P, int z_P) {
        x = x_P;
        y = y_P;
        z = z_P;
    }
    Point3D(int x_P, int y_P) {
        x = x_P;
        y = y_P;
        z = 0;
    }
    Point3D() {
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
    Point3D sum(Point3D point2)
    {
        return Point3D(x + point2.x, y + point2.y, z + point2.z);
    }
    Point3D sum(int x_2, int y_2, int z_2)
    {
        return Point3D(x + x_2, y + y_2, z + z_2);
    }

    double get_long (Point3D point2)
    {
        return sqrt(x * point2.x + y * point2.y + z*point2.z);
    }
    double get_long(int x_2, int y_2, int z_2)
    {
        return sqrt(x * x_2 + y * y_2  + z * z_2);
    }
   
};