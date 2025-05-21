#include <iostream>
#include <cstdlib> 
#include <string>
//Задача № 1
//Напишите функцию вычисления факториала числа.
void Faktorial() {
    int n;
    std::cout << "Эта функция высчитывает факториал числа.\nВведите число, факториал которого хотите посчитать...";
    std::cin >> n;
    int faktorial = 1;
    for (int i = 1; i < n+1; i++) {
        faktorial = faktorial * i;
    }
    std::cout <<n <<"! = " << faktorial<<"\n\n";
}

//Задача № 2
//Напишите функцию поиска минимума и максимума в массиве.
void MinMax() {
    std::cout << "Эта функция найдёт максимум и минимум в ряде чисел:\n";
    int arr[10];
    int Min = 100;
    int Max = 0;
    for (int i = 0; i < 10; i++) {
        arr[i] = rand()%100;
        std::cout << arr[i] << "; ";
        if (arr[i] > Max) {
            Max = arr[i];
        }
        else if (arr[i] < Min) {
            Min = arr[i];
        }
    }
    std::cout << "\nMax = " << Max <<"\nMin = " << Min<<"\n\n";
}

//Задача № 3
//Напишите функцию рекурсивного рисования треугольника высотой n :
void Triangle() {

    int h;
    std::cout << "Эта функция нарисует треугольник с высотой H.\nВведите Н...";
    std::cin >> h;
    for (int i = 0; i < h; i++) {
        for (int l = 0; l < 20 - i; l++) {
            std::cout << " ";
        }

        std::cout << "*";
        if (i == 0) {
            std::cout << "*";
        }
        for (int k = 0; k < i*2; k++) {
            std::cout << "_";

        }
        if (i != 0) {
            std::cout << "*";
        }
        std::cout << "\n\n";
    }
    
}

//Задача № 4
//Напишите программу, подсчета числа вхождений символа "c" в строке символов "s".
void Count() {
    
    std::cout << "Эта функция посчитает количество заданных символов с строке."
        "\nВведите строку без пробелов на английском, в которой будем искать символ.\n";
    
    std::string line;
    std::cin >> line;
    char s;
    std::cout << "\nТеперь введите символ, который нужно найти. Программа вернёт количество этих символов в заданной строке."
        "\nСимвол...";
    std::cin >> s;
    int count = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line.at(i) == s) {
            count += 1;
        }
    }
    std::cout << "Количество символов ("<< s<< ") в строке = " << count;

}

//меню
void Menu() {
    std::cout << "Вас приветствует программа\n";
    while (true) {

        char number;
       
        std::cout << "\n\n Эта программа может:\n1.посчитать факториал числа"
                  << "\n2.Найти минимум и максимум в массиве\n3.Нарисовать треугольник с заданной высотой h"
                  <<"\n4.Сощитать количество заданных символов с строке\n\nКакую операцию нужно сделать? Введите её номер."
                  <<"\tДля выхода из программы нажмите 0\n";
        std::cin >> number;
        system("cls");
        switch (number) {
        case '1':Faktorial(); break;
        case '2':MinMax();break;
        case '3':Triangle();break;
        case '4':Count();break;
        default: break;
        }
        if (number == '0') {
            system("cls");
            std::cout << "Программа завершена";
            break;
        }


    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    Menu();
}

