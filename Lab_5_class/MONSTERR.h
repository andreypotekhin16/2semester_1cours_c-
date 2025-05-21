#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <string>



class MONSTERR {
    int age;
    int damage;
    int protect;
    int level;



public:
    int dam_stat = 0;
    int vin_stat = 0;
    int los_stat = 0;
    int HP;
    std::string HP_BATLE = "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    std::string HP_0 = "--------------------------------------------------------------------";
    std::string NAME;
    MONSTERR() {
        NAME = "(*_*)";
        age = 0;
        HP = 0;
        damage = 0;
        protect = 0;
        level = 0;
    }
    MONSTERR(int lev, std::string name) {
        level = lev;
        NAME = name;
        switch (lev) {
        case 1: {
            age = 10;
            HP = 10;
            damage = 3;
            protect = 0;
            break;
        };
        case 2: {
            age = 60;
            HP = 15;
            damage = 5;
            protect = 2;
            break;
        };
        case 3: {
            age = 238293742101378;
            HP = 20;
            damage = 10;
            protect = 4;
            break;
        };
        default: break;
        }

    }
    void print() {
        std::cout << "\n" << NAME << "\nLEVEL - " << level << "\nage - " << age << "\nHP - " << HP << "\ndamage - from 1 to " << damage << "\nprotect - " << protect << "\n\n\n";
    }
    void print_stat() {
        system("cls");
        std::cout << "��� ���� ����������\n";
        std::cout << "\n��������� ���� = " << dam_stat;
        std::cout << "\n����� ����� = " << vin_stat;
        std::cout << "\n����� ��������� = " << los_stat << "\n";

    }
    void BATELprint() {

        std::cout << "\n /\\_/\\ \t\t" << NAME <<
            "\n(>\'.\'<) \tHP = " << HP_BATLE.substr(0, HP) << HP_0.substr(0, (level * 5 + 5 - HP)) <<
            "\n(U   U)\t\tprotect = " << protect <<
            "\n(\")__(\")\n\n\n";
    }
    int DAMAGE() {

        return (rand() % (damage - 1)) + 1;
    }
    void PUNCH(int DAM) {
        std::cout << "\ndamage = " << DAM << "\n\n";
        if (DAM > protect) {
            HP = HP + protect - DAM;
            dam_stat += DAM - protect;
        }
    }
    void MENU() {
        system("cls");
        while (true) {
            system("cls");
            std::cout << "�����������, �� � ��������� ��� �������.\n";
            std::cout << "------------------------------------------------------\n";
            std::cout << "������ ��������� ������:\n";
            std::cout << "0. ����� �� ���������\n";
            std::cout << "1. ���������� ������ �������\n";
            std::cout << "2. ������ �����\n";
            std::cout << "3. ������� ���\n";
            std::cout << "4. ���������� ����������\n";
            std::cout << "------------------------------------------------------\n";
            std::cout << "\n������� �������...";
            int c;
            std::cin >> c;
            if (c == 0) {
                break;
            }
            switch (c) {
            case 1: {
                print();
                system("pause");
                break;
            }
            case 2: {
                MONSTERR Monster_2(2, "REDISCA");
                FIGHT(Monster_2);
                HP = level * 5 + 5;
                break;
            }
            case 3: {
                MONSTERR Monster_2(2, "REDISCA");
                FAST_FIGHT(Monster_2);
                HP = level * 5 + 5;
                break;
            }
            case 4: {
                print_stat();
                system("pause");
                break;
            }
            default: break;
            }
        }

    }
    void FAST_FIGHT(MONSTERR Monster_2) {
        int i;
        int j;
        int c;
        for (int k = 0; k < 5; k++) {
            system("cls");
            i = rand() % level + 5;
            j = rand() % Monster_2.level + 5;
            std::cout << "������ " << NAME << " - " << i << "\n������ " << Monster_2.NAME << " - " << j << "\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));

        }

        if (i > j) {
            Monster_2.HP = 0;
            Monster_2.BATELprint();
            std::cout << "�� ��������!";
            dam_stat += Monster_2.level * 5 + 5;
            vin_stat += 1;
        }
        else {
            HP = 0;
            BATELprint();
            std::cout << "�� ���������.";
            los_stat += 1;
        }
        system("pause");
    }
    void FIGHT(MONSTERR Monster_2) {

        system("cls");
        int c;
        while (true) {
            system("cls");
            std::cout << "�������� ��������:\n1. ���������\n2. ��������\n3. �������\n";
            std::cin >> c;
            switch (c) {
            case 1: {
                std::cout << NAME << " �������\n";
                Monster_2.PUNCH(DAMAGE());

                Monster_2.BATELprint();
                break;
            }
            case 2: {
                HP += level + 1;
                std::cout << "\n��� HP = " << HP << "\n";

                break;
            }
            case 3: {
                HP = 0;
            }
            default: break;
            }
            std::cout << Monster_2.NAME << " �������\n";
            PUNCH(Monster_2.DAMAGE());
            BATELprint();
            if (Monster_2.HP < 1 or HP < 1) {
                if (Monster_2.HP < 1) {
                    std::cout << "�� ��������!";
                    vin_stat += 1;
                    system("pause");
                }
                else {
                    std::cout << "�� ���������.";
                    los_stat += 1;
                    system("pause");
                }
                break;
            }
            system("pause");
        }
    }
};
