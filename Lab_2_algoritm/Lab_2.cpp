#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h> 
#include <map>
#include <string>
#include <locale>
#include <codecvt>
#include <cwctype>
class READ {

public:

    static void ReadFile(std::vector<int>& num, std::string& filename) {
        std::ifstream input_file(filename);
        std::string line;

        if (input_file.is_open())
        {
            while (std::getline(input_file, line))
            {
                std::istringstream iss(line);
                int number;
                while (iss >> number)
                {
                    num.push_back(number);

                }

            }
            input_file.close();
        }
        else {
            std::cout << "FileOpen Eror";
        }
    }
    static void ReadFile(std::vector<std::string>& num, std::string& filename) {
        std::ifstream input_file(filename);
        std::string line;

        if (input_file.is_open())
        {
            while (std::getline(input_file, line))
            {
                std::istringstream iss(line);
                std::string number;
                while (iss >> number)
                {
                    num.push_back(number);

                }
            }
            input_file.close();
        }
        else {
            std::cout << "ReadFileString Eror";
        }
    }
    static void ReadFileText(std::vector<std::string>& num, std::string& filename) {
        std::ifstream input_file(filename);
        std::string line;

        if (input_file.is_open())
        {
            while (std::getline(input_file, line))
            {
                num.push_back(line);
            }
            input_file.close();
        }
        else {
            std::cout << "ReadFileText Eror";
        }
    }
    static void ReadFileText(std::vector<std::wstring>& num, const std::string& filename) {
        std::wifstream file(filename);
        file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

        if (!file.is_open()) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return;
        }

        std::wstring line;
        while (std::getline(file, line)) {
            num.push_back(line);
        }

        file.close();
    }
};
class WRITE {

public:
static void WriteFileString(std::vector<std::string>& num, std::string& filename) {
    std::ofstream output_file(filename);
    for (std::string ws : num)
    {
        output_file << ws << " ";
    }
}
static void WriteMatrixInt(std::vector<int>& num, int& columns, int& pos_begin, int& indent_end) {
    int SIZE = num.size();
    int h = 0; int m = 0; int summa = 0; int i_size; int i_size_max = 0; int c = 0;

    for (int i = 0; i < SIZE; i++) {
        i_size = std::to_string(num.at(i)).length();
        if (i_size > i_size_max) {
            i_size_max = i_size;
        }
    }

    std::map<int, std::string> prob_count;
    for (int l = i_size_max; l > 0; l--) {
        for (int k = i_size_max; k > l; k--) {
            prob_count[l] += " ";
        }
    }

    std::cout << "\n\n";
    if (SIZE > columns * columns) {
        for (int i = 0 + pos_begin; i < SIZE - indent_end; i++) {
            i_size = std::to_string(num.at(i)).length();
            std::cout << "|" << num.at(i) << prob_count[i_size];
            h += 1;
            if (h % columns == 0) {
                std::cout << "|\n";
                h = 0;
                c += 1;
            }
            if (c == columns) {
                break;
            }
        }
    }
    else {
        std::cout << "\n\nВ файле недостаточно чисел\n\n";
    }

}
static void WriteFileTextRus(const std::vector<std::wstring>& num, const std::string& filename) {
    std::wofstream file(filename);
    file.imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t>));

    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return;
    }

    for (const auto& line : num) {
        file << line << std::endl;
    }

    file.close();
}
};
class NUMBER {
public:
    
    static void One(std::vector<int>& num) {
        std::string filename = "input.txt";
        READ::ReadFile(num, filename);

        int col = 3; int pos_b = 0; int int_e = 0;
        WRITE::WriteMatrixInt(num, col, pos_b, int_e);
        std::cout << "\nразмерность = 3x3 \nсумма элементов побочной диоганали = " << num.at(2) + num.at(4) + num.at(6) << "\n\n";

    }
    static void Two(std::vector<int>& num) {
        int sum = 0;
        int col = 5; int pos_b = 0; int int_e = 0;
        WRITE::WriteMatrixInt(num, col, pos_b, int_e);
        for (int i = 0; i < 5; i++) {
            sum += num.at(5 * 3 + i);
        }
        std::cout << "\nсумма элементов предпоследней строки = " << sum << "\n";
    }
    static void Three(std::vector<std::string>& num1, std::vector<std::string>& num2) {
        std::string filename = "input1.txt";
        READ::ReadFile(num1, filename);
        std::string filename1 = "input2.txt";
        READ::ReadFile(num2, filename1);

        std::vector<std::string> num3;

        int SIZE = num2.size();
        if (num1.size() > num2.size()) {
            SIZE = num1.size();
        }
        for (int i = 0; i < SIZE; i++) {
            if (i < num1.size()) {

                num3.push_back(num1.at(i));
            }
            if (i < num2.size()) {

                num3.push_back(num2.at(i));
            }
        }
        std::cout << "\n\n";
        for (std::string g : num3) {
            std::cout << g << " ";
        }

        std::cout << "\n\n";
        std::string fileputputname = "output.txt";
        WRITE::WriteFileString(num3, fileputputname);
    }
    static void Four(std::vector<std::string>& num) {
        std::vector<std::string> seven_num;
        for (std::string g : num) {
            if (g.length() == 7) {
                seven_num.push_back(g);
            }
        }
        std::cout << "\n\n";
        std::sort(begin(seven_num), end(seven_num));
        for (std::string y : seven_num) {
            std::cout << y << " ";
        }
        std::cout << "\n\n";
    }
    static void Five(std::vector<int>& num) {
        int SIZE = num.size();
        int col = 4; int pos_b = SIZE - 16; int int_e = 0; int sum = 0; int m = 0;
        WRITE::WriteMatrixInt(num, col, pos_b, int_e);

        for (int i = SIZE - 16; i < SIZE; i++) {
            m += 1;
            if (m < col) {
                sum += num.at(i);
            }
            if (m == 4) {
                col -= 1;
                m = 0;
            }
        }
        std::cout << "Сумма чисел выше главной диагонали = " << sum;
    }
    static void Six(std::vector<std::string>& num) {
        std::string filename = "output.txt";
        READ::ReadFile(num, filename);
        std::cout << "\n\n";
        bool stat = true;
        for (std::string sl : num) {
            int sl_length = sl.length();
            for (int i = 0; i < sl_length; i++) {
                if (sl.at(i) != sl.at(sl_length - i - 1)) {
                    stat = false;
                    break;
                }
                else {
                    stat = true;
                }
            }
            if (stat == true) {
                std::cout << sl << " ";
            }
        }
        std::cout << "\n\n";
    }
    static void Seven(std::vector<int>& num) {
        stable_sort(num.begin(), num.end());
        std::ofstream output_file("output_1");
        for (int i = num.size() - 1; i > 0; i--)
        {

            std::cout << num.at(i) << " ";
            output_file << num.at(i) << " ";
        }
        std::cout << "\nМаксимальное число = " << num.at(num.size() - 1) << "\nМинимальное число = " << num.at(1);
        std::cout << "\n\n";
    }
    static void Eight(std::vector<std::string>& num) {
        std::string filename = "input_text.txt";
        READ::ReadFileText(num, filename);
        int LENGTH_1 = 0; int LENGTH_2 = 0;
        for (char j : num.at(1)) {
            if ((std::isalpha(j))) {
                LENGTH_1 += 1;
            }
        }
        for (char f : num.at(2)) {
            if ((std::isalpha(f))) {
                LENGTH_2 += 1;
            }
        }
        if (LENGTH_1 > LENGTH_2) {
            std::cout << num.at(1) << "\n количество букв = " << LENGTH_1 << "\n\n";
        }
        else {
            std::cout << num.at(3) << "\n количество букв = " << LENGTH_2 << "\n\n";
        }

    }
    static void Nine(std::vector<std::wstring>& num) {
        std::string file = "rus_text.txt";
        std::cout << "1";
        READ::ReadFileText(num, file);
        std::cout << "2";

        if (num.size() < 2) {
            std::cerr << "Вектор содержит меньше двух строк!" << std::endl;
            return;
        }

        for (wchar_t& j : num.at(1)) {
            if (std::iswalpha(j) && j == L'и') {
                j = L'е';
            }
        }
        for (wchar_t& j : num.at(num.size() - 3)) {
            if (std::iswalpha(j) && j == L'а') {
                j = L'о';
            }
        }

        WRITE::WriteFileTextRus(num, file);
        std::cout << "9";
    }
    static void Ten(std::vector<std::string>& num) {
        std::string filename = "input_text.txt";
        READ::ReadFile(num, filename);
        char simvol; int count_num = 0;
        int count_simvol = 0;
        int count_max = 0;
        std::string max_count_word = "";
        std::cout << "input simvol...";
        std::cin >> simvol;
        for (int i = 0; i < num.size(); i++) {

            if (num.at(i).at(0) == simvol) {
                count_num += 1;
                if (num.at(i).length() > max_count_word.length()) {
                    max_count_word = num.at(i);

                }
            }
        }
        std::cout << count_num << " - count of words\nThe max word is " << max_count_word << "\n\n";
    }

};
int main()
{
    setlocale(LC_ALL, "rus");
     std::vector<int> numbers;
     std::vector<std::string> slova;
     std::vector<std::string> slova1;
     std::vector<std::string> text;
     std::vector<std::wstring> text_rus;
    NUMBER::One(numbers);
    NUMBER::Two(numbers);
    NUMBER::Three(slova, slova1);
    NUMBER::Four(slova);
    NUMBER::Five(numbers);
    NUMBER::Six(slova);
    NUMBER::Seven(numbers);
    NUMBER::Eight(text);
    NUMBER::Nine(text_rus);
    NUMBER::Ten(text);
    return 0;
}
