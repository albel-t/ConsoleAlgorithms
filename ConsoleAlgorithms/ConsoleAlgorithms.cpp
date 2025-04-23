/****
    Связный список состоит из класса контейнера и классов элементов. каждый имеет полое с данными и указатели на прошлый и следующий элемент, нулевой явзяется экземпляром класса, без него работа невозможна. имеются функции добавления и удаленияб показа зависимости двух параметров
****/
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>
#include <cstdlib>

#include "filework.h"
#include "laba_1.h"
#include "laba_2.h"
#include "laba_3.h"
#include "laba_4.h"
#include "laba_5.h"

#define LABSCOUNT 5

//#define TEST_MODE

void MenuLab5()
{
    system("cls");
    cout << "Цель работы. Освоить основные алгоритмы сортировки данных линейной структуры." << mcl::endl;
    cout << "********************************************************" << mcl::endl;

    int select = 1;
    while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (GetAsyncKeyState(VK_TAB) & 0x8000)
        {
            select++;
            if (select > 1)
                select = 1;
            Sleep(70);
        }
        for (int l = 1; l <= 1; l++)
        {
            if (select == l)
            {
                cout(0, l + 5) << " >Task #" * select_color << l << mcl::endl;
            }
            else {
                cout(0, l + 5) << "task #" * data_color << l << "     " << mcl::endl;
            }
        }
    }
    switch (select)
    {
    case 1:
        system("cls");
        Sleep(500);
        l5task1();
        break;
    default:
        break;
    }

}
void MenuLab4()
{
    system("cls");
    cout << "Цель работы. Освоить основы работы со связными списками в языке С++." << mcl::endl;
    cout << "********************************************************" << mcl::endl;

    int select = 1;
    while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (GetAsyncKeyState(VK_TAB) & 0x8000)
        {
            select++;
            if (select > 1)
                select = 1;
            Sleep(70);
        }
        for (int l = 1; l <= 1; l++)
        {
            if (select == l)
            {
                cout(0, l + 5) << " >Task #" * select_color << l << mcl::endl;
            }
            else {
                cout(0, l + 5) << "task #" * data_color << l << "     " << mcl::endl;
            }
        }
    }
    switch (select)
    {
    case 1:
        system("cls");
        Sleep(500);
        l4task1();
        break;
    default:
        break;
    }

}
void MenuLab3()
{
    system("cls");
    cout << "Цель работы. Освоить основы работы с классами в языке С++." << mcl::endl;
    cout << "********************************************************" << mcl::endl;

    int select = 1;
    while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (GetAsyncKeyState(VK_TAB) & 0x8000)
        {
            select++;
            if (select > 1)
                select = 1;
            Sleep(70);
        }
        for (int l = 1; l <= 1; l++)
        {
            if (select == l)
            {
                cout(0, l + 5) << " >Task #" * select_color << l << mcl::endl;
            } else {
                cout(0, l + 5) << "task #" * data_color << l << "     " << mcl::endl;
            }
        }
    }
    switch (select)
    {
    case 1:
        system("cls");
        Sleep(500);
        l3task1();
        break;
    default:
        break;
    }
    
}

void MenuLab2()
{
    system("cls");
    cout << "Цель работы.Освоить основы работы с базой данных в языке С++." << mcl::endl;
    cout << "********************************************************" << mcl::endl;

    int select = 1;
    while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (GetAsyncKeyState(VK_TAB) & 0x8000)
        {
            select++;
            if (select > 1)
                select = 1;
            Sleep(70);
        }
        for (int l = 1; l <= 1; l++)
        {
            if (select == l)
            {
                cout(0, l + 5) << " >Task #" * select_color << l << mcl::endl;
            } else {
                cout(0, l + 5) << "task #" * data_color << l << "     " << mcl::endl;
            }
        }
    }

    switch (select)
    {
    case 1:
        system("cls");
        Sleep(500);
        l2task1();
        break;
    default:
        break;
    }

}

void MenuLab1()
{
    system("cls");
    cout << "Цель работы.Освоить основы работы с базовой системой ввода - вывода в языке С++." << mcl::endl;
    cout << "1. Дан текстовый файл. Удалить из него третью строку. Результат записать в другой файл;" << mcl::endl;
    cout << "2. Имеется текстовый файл, в каждой строке которого первые два символа \nявляются буквами.Получить слово, образованное первыми буквами каждой \nстроки;" << mcl::endl;
    cout << "3. Дан текстовый файл.Переписать его строки в обратном порядке(справа \nналево) в другой файл.Порядок строк во втором файле должен совпадать с \nпорядком строк в заданном файле;" << mcl::endl;
    cout << "4. Имеется типизированный файл, в котором записаны восемнадцать целых \nчисел.Переписать все положительные числа файла в массив в том же \nпорядке;" << mcl::endl;
    cout << "5. Дан типизированный файл, элементами которого являются отдельные \nслова.Найти количество слов, начинающихся на букву ‘м’(кириллица);" << mcl::endl;
    cout << "6. Имеется типизированный файл, элементами которого являются целые \nчисла.Все четные числа этого файла записать во второй файл, а нечетные – в \nтретий файл.Порядок следования чисел сохраняется." << mcl::endl;
    int select = 1;
    while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (GetAsyncKeyState(VK_TAB) & 0x8000)
        {
            select++;
            if (select > 6)
                select = 1;
            Sleep(70);
        }
        for (int l = 1; l <= 6; l++)
        {
            if (select == l)
            {
                cout(0, l + 15) << " >Task #" * select_color << l << mcl::endl;
            }
            else
            {
                cout(0, l + 15) << "task #" * data_color << l << "     " << mcl::endl;
            }
        }
    }
    system("cls");
    switch (select)
    {
    case 1:
        l1task1();
        break;
    case 2:
        l1task2();
        break;
    case 3:
        l1task3();
        break;
    case 4:
        l1task4();
        break;
    case 5:
        l1task5();
        break;
    case 6:
        l1task6();
        break;
    default:
        break;
    }
}

void MainMenu()
{
    int select = 1;
    cout << "Hello! \n This program was made for the assembly of laboratory works." * data_color << mcl::endl;
    cout << "Use     and  to switching and select " << mcl::endl;
    cout << "Now you can select one of " << LABSCOUNT << " labs:" << mcl::endl;
    while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
    {
        if (GetAsyncKeyState(VK_TAB) & 0x8000)
        {
            select++;
            if (select > LABSCOUNT)
                select = 1;
            Sleep(90);
        }
        for (int l = 1; l <= LABSCOUNT; l++)
        {
            if (select == l)
            {
                cout(0, l + 4) << " >laboratory work #" * select_color << l << mcl::endl;
            }
            else
            {
                cout(0, l + 4) << "laboratory work #" * data_color << l << "     " << mcl::endl;
            }
        }
    }
    cout(0, LABSCOUNT + 5) << "You select to veiw laboratory work #" * data_color << select << mcl::endl;
    Sleep(300);

    switch (select)
    {
    case 1:
        MenuLab1();
        break;
    case 2:
        MenuLab2();
        break;
    case 3:
        MenuLab3();
        break;
    case 4:
        MenuLab4();
        break;
    case 5:
        MenuLab5();
        break;
    default:
        cout(0, LABSCOUNT + 5) << "Wrong select" * error_color << mcl::endl;
        break;
    }
}

int new_booking::last_id = 0;
int person::last_id = 0;

debug_lvl debug = only_sort_result;
DWORD last_time;



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


#ifdef TEST_MODE
    



#endif

#ifndef TEST_MODE

    MainMenu();

#endif



}
