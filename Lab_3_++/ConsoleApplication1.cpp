#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <direct.h>
#include <sstream>
#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include <cctype> 
std::string cod_pasword(std::string pas) {
    std::string lower = pas;
    std::transform(lower.begin(), lower.end(), lower.begin(),
        [](char c) { return std::tolower(static_cast<unsigned char>(c)); });
    char arr_code[37] = { 'a', 'b', 'c', 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' ,
                          't', 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '0', '1' , '2' , '3' , '4', '5', '6', '7', '8', '9', '-' };

    std::string result;
    for (char c : lower) {
        for (int k = 0; k < 36; ++k) {
            if (c == arr_code[k]) {
                result += arr_code[(k + 1)];
                break;
            }
        }
    }
    return result;

}
sqlite3* BD;


class Time {
public:
    int day;
    int month;
    int year;
    std::string getCurrentDate() {
        time_t now = time(0);
        tm ltm{};
        
        localtime_s(&ltm, &now);
        char buffer[9];
        strftime(buffer, sizeof(buffer), "%d.%m.%y", &ltm);
        
        day = ltm.tm_mday;
        month = ltm.tm_mon;
        year = ltm.tm_year + 1900;
        mktime(&ltm);
        return std::string(buffer);
    }
   
    std::string formatDate(int s) {
        time_t now = time(0);
        tm ltm{};
        localtime_s(&ltm, &now);
        ltm.tm_mday -= s;
        mktime(&ltm);
        char buffer[9];
        strftime(buffer, sizeof(buffer), "%d.%m.%y", &ltm);
        return std::string(buffer);
    }

};
class Record {
    
    std::string NAME_LIST;
    std::vector<std::string> NAME_COL;
    std::vector<std::string> NAME_TIPE_COL;
    int NUMBER_COL;

public:
    Record(int number_col, std::string name_list, std::vector<std::string> name_col, std::vector<std::string> name_tipe_col) {
        NAME_LIST = name_list;
        NAME_COL = name_col;
        NUMBER_COL = number_col;
        NAME_TIPE_COL = name_tipe_col;

    }

    int createDirectoryIfNotExists() {

        int rc = sqlite3_open("SQlite.db", &BD);
        char* err_msg = 0;
        if (rc != SQLITE_OK)
        {
            sqlite3_close(BD);
            return 1;
        }

        std::string createComand = "CREATE TABLE IF NOT EXISTS " + NAME_LIST +"(id INTEGER PRIMARY KEY AUTOINCREMENT,";
        for (int i = 1; i < NUMBER_COL ; i++) {
            createComand += NAME_COL.at(i)+" " + NAME_TIPE_COL.at(i);
            if (i < NUMBER_COL - 1) {
                createComand += ",";
            }
        }
        createComand += ");";

        const char* comand = createComand.c_str();
        rc = sqlite3_exec(BD, comand, 0, 0, &err_msg);
        if (rc != SQLITE_OK)
        {
            printf("SQL error: %s\n", err_msg);
            sqlite3_free(err_msg);      // очищаем ресурсы
            sqlite3_close(BD);
            return 1;
        }
       
        return 0;

    }
    int addRecord(const char* date, const int workshop, const int machine) {
        char sql[200];

        char* err_msg = 0;
        std::string createComand = "INSERT INTO " + NAME_LIST + "(";
        for (int i = 1; i < NUMBER_COL; i++) {
            createComand += NAME_COL.at(i);
            if (i < NUMBER_COL - 1) {
                createComand += ",";
            }
        }
        createComand += ") VALUES (";
        for (int i = 1; i < NUMBER_COL; i++) {
            if (i == 1) {
                createComand += "'%s'";
            }
            else {
                createComand += "'%d'";
            }
            
            if (i < NUMBER_COL - 1) {
                createComand += " ,";
            }
        }
        createComand += ")";
        const char* comand = createComand.c_str();
        sprintf_s(sql, comand, date, workshop, machine);
        int rc = sqlite3_exec(BD, sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(BD);
            return 1;
        }
       
        return 0;
    }
    void getRecord(std::string& date) {

        std::cout << "Введите номер цеха: ";
        int workshop;
        std::cin >> workshop;

        std::cout << "Введите номер аппарата: ";
        int machine;
        std::cin >> machine;


        char ch[100];
        strcpy_s(ch, date.c_str());
        addRecord(ch, workshop, machine);

        std::cout << "Запись успешно добавлена  " << std::endl;
    }
    void print0(sqlite3_stmt* stmt, int columnCount) {
        for (int i = 0; i < columnCount; i++) {
            std::cout << sqlite3_column_name(stmt, i) << "\t";
        }
        std::cout << std::endl << "----------------------------" << std::endl;
    }
    void printFilteredRows(sqlite3* BD, const std::string& column) {

        Time timee;

        for (int i = 0; i < 7; i++) {

            std::string value = timee.formatDate(i);
            sqlite3_stmt* stmt;

            std::string sql = "SELECT * FROM " + NAME_LIST + " WHERE " + column + " = ?;";


            // Подготовка запроса
            if (sqlite3_prepare_v2(BD, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
                std::cerr << "Ошибка при подготовке запроса: " << sqlite3_errmsg(BD) << std::endl;
                return;
            }

            // Привязка параметра (значения) к `?` в SQL-запросе
            if (sqlite3_bind_text(stmt, 1, value.c_str(), -1, SQLITE_STATIC) != SQLITE_OK) {
                std::cerr << "Ошибка привязки параметра: " << sqlite3_errmsg(BD) << std::endl;
                sqlite3_finalize(stmt);
                return;
            }

            // Вывод заголовков (первый ряд — названия столбцов)


            int columnCount = sqlite3_column_count(stmt);
            if (i == 0) {
                print0(stmt, columnCount);
            }

            // Вывод строк с нужным значением
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                for (int j = 0; j < columnCount; j++) {

                    const unsigned char* text = sqlite3_column_text(stmt, j);
                    if (text) {
                        std::cout << (text ? reinterpret_cast<const char*>(text) : "-") << "\t";
                    }
                }
                std::cout << std::endl;
            }
            // Освобождение ресурсов
            sqlite3_finalize(stmt);
        }
    }
    void editRecord(sqlite3* BD) {


        // Вывод всех записей за эту дату
        std::cout << "Записи за последнюю неделю:\n";
        printFilteredRows(BD, "date");

        int id;
        std::cout << "Введите ID записи, которую нужно удалить: ";
        std::cin >> id;
        std::string createComand = "DELETE FROM " + NAME_LIST + " WHERE  id = ?;";
      
        const char* comand = createComand.c_str();
        sqlite3_stmt* stmt;

        if (sqlite3_prepare_v2(BD, comand, -1, &stmt, nullptr) != SQLITE_OK) {
            std::cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(BD) << std::endl;
            return;
        }

        sqlite3_bind_int(stmt, 1, id);                                // Привязка ID

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            std::cout << "Строка успешно удалена!" << std::endl;
        }
        else {
            std::cerr << "Ошибка при удалении: " << sqlite3_errmsg(BD) << std::endl;
        }

        sqlite3_finalize(stmt);
    }

    void printLog( const std::string& value, const char* value1, const std::string& column, const std::string& column2) {
            
            std::string value2 = value1;
            
            sqlite3_stmt* stmt;

            std::string sql = "SELECT * FROM " + NAME_LIST + " WHERE " + column + " = ? AND " + column2 + " = ? AND " + column + " IS NOT NULL AND " + column2 + " IS NOT NULL;";

            // Подготовка запроса
            if (sqlite3_prepare_v2(BD, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
                std::cerr << "Ошибка при подготовке запроса: " << sqlite3_errmsg(BD) << std::endl;
                return;
            }

            // Привязка параметра (значения) к `?` в SQL-запросе
            if (sqlite3_bind_text(stmt, 1, value.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
                sqlite3_bind_text(stmt, 2, value2.c_str(), -1, SQLITE_STATIC) != SQLITE_OK) {
                std::cerr << "Ошибка привязки параметра: " << sqlite3_errmsg(BD) << std::endl;
                sqlite3_finalize(stmt);
                return;
            }
            

            
            int columnCount = sqlite3_column_count(stmt);
            bool hasRows = false;
            for (int i = 3; i < columnCount; i++) {
                std::cout << sqlite3_column_name(stmt, i) << "\t";
            }
            std::cout << std::endl << "----------------------------" << std::endl;

            // Вывод строк с нужным значением
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                for (int i = 3; i < columnCount; i++) {

                    const unsigned char* text = sqlite3_column_text(stmt, i);
                    
                        std::cout << (text ? reinterpret_cast<const char*>(text) : "-") << "\t";
                        hasRows = true;
                }
                std::cout << std::endl;
            }
            
            if (!hasRows) {
                std::cout << "Нет записей, удовлетворяющих условиям.\n";
            }
            // Освобождение ресурсов

            
            
            sqlite3_finalize(stmt);
        
    }
    int addRecord(const char* login, const char* pasvord, const char* name, const int age, const char* work) {
        char sql[200];

        char* err_msg = 0;
        std::string createComand = "INSERT INTO " + NAME_LIST + "(";
        for (int i = 1; i < NUMBER_COL; i++) {
            createComand += NAME_COL.at(i);
            if (i < NUMBER_COL - 1) {
                createComand += ",";
            }
        }
        createComand += ") VALUES (";
        for (int i = 1; i < NUMBER_COL; i++) {
            if( (i % 2 != 0) or (i == 2)) {
                createComand += "'%s'";
            }
            else {
                createComand += "'%d'";
            }

            if (i < NUMBER_COL - 1) {
                createComand += " ,";
            }
        }
        createComand += ")";
        
        const char* comand = createComand.c_str();
        sprintf_s(sql, comand, login, pasvord, name, age, work);
        int rc = sqlite3_exec(BD, sql, 0, 0, &err_msg);
        if (rc != SQLITE_OK)
        {
            sqlite3_close(BD);
            return 1;
        }

        return 0;
    }
    void getRecord2() {

        std::cout << "\nВведите логин\nЛогин: ";
        std::string l;
        std::cin >> l;
        char log[100];
        strcpy_s(log, l.c_str());
        std::cout << "\nПридумайте пароль. \nОн должен содержать только латинские буквы и цифры от 0 до 9.\nПароль: ";
        std::string p;
        std::cin >> p;
        std::cout << "\nКак вас зовут? \nИмя: ";
        std::string n;
        std::cin >> n;
        char nam[100];
        strcpy_s(nam, n.c_str());
        std::cout << "\nСколько вам лет?\nВозраст: ";
        int ag;
        std::cin >> ag;
        std::cout << "\nКем вы работаете? \nДолжность: ";
        std::string w;
        std::cin >> w;
        char wor[100];
        strcpy_s(wor, w.c_str());


        addRecord( log, cod_pasword(p).c_str(), nam, ag, wor);

        std::cout << "Запись успешно добавлена  " << std::endl;
    }
    void login() {
        std::cout << "\nВведите логин\nЛогин: ";
        std::string log;
        std::cin >> log;
        char ch1[100];
        strcpy_s(ch1, log.c_str());
        std::cout << "\nВведите пароль\nПароль: ";
        std::string pus;
        std::cin >> pus;

        printLog(ch1, cod_pasword(pus).c_str(), "login", "pasvord");
    }
    void recover_pas_chek(std::vector <std::string>& vec) {
        std::cout << "\nВведите логин\nЛогин: ";
        std::string log;
        std::cin >> log;
        std::cout << "\nПроверка данных\n---------------------------------- ";
        std::cout << "\nКак вас зовут? \nИмя: ";
        std::string nam;
        std::cin >> nam;
        std::cout << "\nСколько вам лет?\nВозраст: ";
        int ag;
        std::cin >> ag;
        std::cout << "\nКем вы работаете? \nДолжность: ";
        std::string wor;
        std::cin >> wor;
        

        if (recover_stat(log, nam, ag, wor, vec.at(1), vec.at(3), vec.at(4), vec.at(5)) == true) {
            std::cout << "\nДанные введены верно!\n";
            recover_pas(log, nam, ag, wor);
        }
        else {
            std::cout << "\nНеверно введены данные. \nПопробуйте ещё раз позже.\n";
        }

    }
    bool recover_stat(const std::string& login, const std::string& name, const int& age, const std::string& work, const std::string& column_log, const std::string& column_name, const std::string& column_age, const std::string& column_work) {
            sqlite3_stmt* stmt;

            std::string sql =
                "SELECT " + column_name + ", " + column_age + ", " + column_work +
                " FROM " + NAME_LIST +
                " WHERE " + column_log + " = ?" +
                " AND " + column_name + " = ?" +
                " AND " + column_age + " = ?" +
                " AND " + column_work + " = ?";

            if (sqlite3_prepare_v2(BD, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
                std::cerr << "Ошибка подготовки запроса: " << sqlite3_errmsg(BD) << std::endl;
                return false;
            }

            // Привязка параметров
            if (
                sqlite3_bind_text(stmt, 1, login.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
                sqlite3_bind_text(stmt, 2, name.c_str(), -1, SQLITE_STATIC) != SQLITE_OK ||
                sqlite3_bind_int(stmt, 3, age) != SQLITE_OK ||
                sqlite3_bind_text(stmt, 4, work.c_str(), -1, SQLITE_STATIC) != SQLITE_OK
                ) {
                std::cerr << "Ошибка привязки параметров: " << sqlite3_errmsg(BD) << std::endl;
                sqlite3_finalize(stmt);
                return false;
            }

            // Выполняем запрос
            bool match = false;
            if (sqlite3_step(stmt) == SQLITE_ROW) {
                
                match = true;
            }
            else {
                std::cout << "Пользователь не найден или данные не совпадают.\n";
            }

            sqlite3_finalize(stmt);
            return match;
        }
    void recover_pas(const std::string& login, const std::string& name, const int& age, const std::string& work) {
        std::string pasvord;
        std::cout << "\nВведите новый пароль\n";
        std::cin >> pasvord;
        pasvord = cod_pasword(pasvord);
        addRecord(login.c_str(), pasvord.c_str(), name.c_str(), age, work.c_str());
        std::cout << "\nПароль изменён успешно\n";


    }
};  
 
void menu() {
    int choice = -1;
    while (choice != 0) {
        std::cout << "Вы в программе для записи данных в таблицу\nВыберите пункт:\n0. Выход\n1. Записи о станках\n2. Записи о сотрудиках\n";
        std::cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            std::vector<std::string> col{ "id","date", "worcshop", "number" };
            std::vector<std::string> tipe{ "", "TEXT", "INTEGER", "INTEGER" };
            Record rec(4, "Log_book", col, tipe);
            rec.createDirectoryIfNotExists();
            bool h = true;
            int cho = -1;
            while (cho != 0) {
                std::cout << "Вы в программе для записи обслуживания станков.";
                std::cout << "\nВыберите действие:\n";
                std::cout << "1 - Добавить запись о проведённых работах\n";
                std::cout << "2 - Просмотреть график работ за последнюю неделю\n";
                std::cout << "3 - Удалить запись\n";
                std::cout << "0 - Выход\n";
                std::cout << "Ваш выбор: ";

                
                std::cin >> cho;
                system("cls");
                switch (cho) {
                case 1: {
                    Time timee;

                    std::string date = timee.getCurrentDate();
                    rec.getRecord(date);
                    break;
                }
                case 2:
                {
                    rec.printFilteredRows(BD, "date");
                    break;
                }

                case 3: {
                    rec.editRecord(BD);
                    break;
                }

                case 0: {
                    
                    break;
                }

                default: std::cout << "Ошибка: введите корректный номер.\n";
                }
                
            }
            break;
        }

        case 2: {
            std::vector<std::string> col2{ "id","login", "pasvord", "name", "age", "work" };
            std::vector<std::string> tipe2{ "", "TEXT", "TEXT", "TEXT", "INTEGER", "TEXT" };

            Record rec2(6, "Log_book_1", col2, tipe2);
            rec2.createDirectoryIfNotExists();
            bool g = true;
            int ch = -1;
            system("cls");
            while (ch != 0) {
                std::cout << "Вы в программе для записи информации о сотрудниках.";
                std::cout << "Выберите действие:\n1. Войти\n2. Зарегестрироваться\n3. Забыли пароль\n0. Выход\n";

                std::cin >> ch;
                system("cls");
                switch (ch) {
                case 1: {
                    rec2.login();
                    break;
                }
                case 2:
                {
                    rec2.getRecord2();
                    break;
                }

                case 3:
                {
                    rec2.recover_pas_chek(col2);
                    break;
                }

                case 0: {
                    
                    break;
                }

                default: std::cout << "\nОшибка: введите корректный номер.\n";
                }
            }
            break;
        }
        case 0: {
            std::cout << "\nВыход из программы.\n";
            return;
        }
        default: {
            std::cout << "\nОшибка: введите корректный номер.\n";
            }
        }
    }
            
}

int main() {
    setlocale(LC_ALL, "rus");
    
    menu();
     
    sqlite3_close(BD);
    
    return 0;
}




