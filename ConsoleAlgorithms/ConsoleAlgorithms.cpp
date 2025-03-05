#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>
#include <cstdlib>




#include "MultiColorLine.h"
#include "laba_1.h"



int main()
{
    //mcl::print cout;
    mcl::cmd_color color_1(10, 0);
    cout << "task 1:" * process_color << mcl::endl;
    task1();
    cout << "task 2:" * process_color << mcl::endl;
    task2();
    cout << "task 3:" * process_color << mcl::endl;
    task3();
    cout << "task 4:" * process_color << mcl::endl;
    task4();
    cout << "task 5:" * process_color << mcl::endl;
    task5();

    cout << "task 6:" * process_color << mcl::endl;
    task6();
    /*
    cout(10, 10) << "hello world" * color_1 << mcl::endl;
    std::cin >> nameFile;
    auto file1 = open("file11.txt", READ_FILE);
    auto file2 = open("file12.txt", WRITE_FILE);
    char buffer[80] = { 0 };
    file_data* file1_ = read(file1);
    cout << "file: { " * process_color << mcl::nsep;

    for (int i = 0; i < file1_->size; i++)
    {
        cout << file1_->strings[i] * data_color << mcl::nsep;
    }
    cout << "} " * process_color << mcl::endl;

    write(file2, file1_);
    */


}
