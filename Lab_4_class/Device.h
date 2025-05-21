#include <iostream>



class Device {
    double number;
    int a = 10;
    int b = 11;
public:
    Device(double number_d) {
        number = number_d;
    }
    Device() {
        number = rand() % 126;
    }
    void print()
    {
        std::cout << number << "\n";
    }
    void Change() {

        number = (a * number * (3, 14159) + b) / (3, 14159 + 1);

    }

};
