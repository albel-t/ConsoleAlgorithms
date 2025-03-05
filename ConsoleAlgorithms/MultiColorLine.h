#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>
#include <cstdlib>

#ifndef text_color
#define text_color


namespace mcl {
    void setConsoleColor(HANDLE hConsole, int textColor, int backgroundColor);

    struct cmd_color
    {
        int textColor;
        int backgroundColor;
        cmd_color();
        cmd_color(int textColor, int backgroundColor);
    };

    struct letter {
        std::string string;
        cmd_color color;
        letter(double x, cmd_color color);
        letter(int x, cmd_color color);
        letter(std::string s, cmd_color color);
    };

    letter operator * (std::string string, cmd_color color);
    letter operator * (double number, cmd_color color);
    letter operator * (int number, cmd_color color);
    letter operator * (const char* string, cmd_color color);
    enum tag
    {
        tab,
        endl,
        nsep
    };

    class print
    {
        HANDLE hConsole;
        std::vector<letter> string;
    public:
        cmd_color last_color;

        print();
        void add(letter str);
        void out(tag tag_);
        void SetPos(short x, short y);

        print& operator()(short x, short y);
    };

    print& operator << (print& out, tag tag_);
    print& operator << (print& out, letter str);
    print& operator << (print& out, std::string str);
    print& operator << (print& out, const char* str);
    print& operator << (print& out, double num);
    print& operator << (print& out, int num);
} ;

extern mcl::print cout;
extern mcl::cmd_color error_color;
extern mcl::cmd_color success_color;
extern mcl::cmd_color process_color;
extern mcl::cmd_color data_color;


/*
0 = Черный
1 = Синий
2 = Зеленый
3 = Голубой
4 = Красный
5 = Лиловый
6 = Желтый
7 = Белый
8 = Серый
9 = Светло-синий
A/10 = Светло-зеленый
B/11 = Светло-голубой
C/12 = Светло-красный
D/13 = Светло-лиловый
E/14 = Светло-желтый
F/15 = Ярко-белый
*/

#endif