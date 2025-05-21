
#include "Point3D.h"
#include "Section.h"
#include "Device.h"
#include "Сircle.h"
#include "MONSTERR.h"
#include <iostream>
#include <math.h> 
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>

void number_1_3() {
    std::cout << "\n";
    Point3D point;
    Point3D point1;
    for (int i = 0; i < 10; i++) {
        int x, y, z, x_, y_, z_;

        x = rand() % 100;
        y = rand() % 100;
        z = rand() % 100;
        x_ = rand() % 100;
        y_ = rand() % 100;
        z_ = rand() % 100;
        point.set_Point(x, y, z);
        point1.set_Point(x_, y_, z_);
        point.print();

        std::cout << "\nсумма1 ";
        point.sum(x_, y_, z_).print();
        std::cout << "\nсумма2 ";
        point.sum(point1).print();


        std::cout << "\n\n";

    }
}

void number_2() {
    Device device;

    for (int i = 0; i < 100; i++) {

        device.Change();

        device.print();

    }



}

void number_4_8() {
    Сircle number;

    number.set_R();
    number.set_cord();
    number.print();

}

void number_5() {
    std::string name;
    std::cout << "Здравствуйте, как зовут вашего монстра?\n";
    std::cin >> name;
    MONSTERR Monster_1(2, name);
    Monster_1.MENU();
}

void number_6_7() {
    Section point1;
    Section point2;
    int x1, x2, y1, y2, z1, z2;

    std::cout << "";
    for (int i = 0; i < 10; i++) {


        x1 = rand() % 100;
        y1 = rand() % 100;
        z1 = rand() % 100;
        x2 = rand() % 100;
        y2 = rand() % 100;
        z2 = rand() % 100;
        point1.set_Point(x1, y1, z1);
        point2.set_Point(x2, y2, z2);
        point1.print();
        point2.print();
        std::cout << "Длина отрезка = " << point1.sum(point2) << "\n\n\n";

    }

}

void menu() {
    int ch = -1;
    while (ch != 0) {
        std::cout << "\nВы в Лабараторной работе №4.";
        std::cout << "\nВыберите номер задания, которое нужно проверить";
        std::cout << "\n0. Выход из программы";
        std::cout << "\n1. Задания 1 и 3. про точки";
        std::cout << "\n2. Задание 2 про устройства";
        std::cout << "\n3. Задания 4 и 8 про окружность";
        std::cout << "\n4. Задание 5 про монстров";
        std::cout << "\n5. Задания 6 и 7 про отрезки";
        std::cout << "\nВведите номер задания...";
        std::cin >> ch;
        system("cls");
        switch (ch) {
        case 1: {
            number_1_3();
            break;
        }
        case 2: {
            number_2();
            break;
        }
        case 3: {
            number_4_8();
            break;
        }
        case 4: {
            number_5();
            break;
        }
        case 5: {
            number_6_7();
            break;
        }
        default: {
            std::cout << "Введён неверный номер...";
            break;
        }
        }
    }

}
