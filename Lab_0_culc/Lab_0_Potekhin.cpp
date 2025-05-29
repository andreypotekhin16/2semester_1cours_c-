#include <iostream>
// #include <conio.h> 
// тест
void Sum(int& a, int& b) {
	std::cout << a <<" + " <<b <<" = " << a + b << "\n";
}
void Min(int& a, int& b) {
	std::cout  << a << " - " << b << " = " << a - b << "\n";
}
void Mul(int& a, int& b) {
	std::cout << a << " * " << b << " = " << a * b << "\n";
}
void Div(int& a, int& b) {
	std::cout << a << " / " << b << " = " << a / b << "\n";
}

void Menu() {
	std::cout << "Вас приветствует калькулятор!\n";
	while (true) {
		
		char number;
		int a,  b;
		std::cout << "\nВведите два числа a и b:\n";
		std::cout << "a = ";
		std::cin >> a;
		std::cout << "b = ";
		std::cin >> b;
		std::cout << "Какую операцию нужно сделать? \t\t\t"
			"Для выхода из программы нажмите 0\n( + or - or * or / )\n";
		std::cin >> number;
		system("cls");
		std::cout << "Ответ:\t";
		switch (number) {
		case '+': Sum(a, b);break;
		case '-': Min(a, b);break;
		case '*': Mul(a, b);break;
		case '/': Div(a, b);break;
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
	return (0);
}

