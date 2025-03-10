
#include "MultiColorLine.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>
#include <cstdlib>

void mcl::setConsoleColor(HANDLE hConsole, int textColor, int backgroundColor)
{
    SetConsoleTextAttribute(hConsole, (backgroundColor << 4) | textColor);
}

mcl::cmd_color::cmd_color() : textColor(0), backgroundColor(0)
{   }
mcl::cmd_color::cmd_color(int textColor, int backgroundColor) : textColor(textColor), backgroundColor(backgroundColor)
{   }


mcl::letter::letter(double x, cmd_color color) : string(std::to_string(x)), color(color)
{   }
mcl::letter::letter(int x, cmd_color color) : string(std::to_string(x)), color(color)
{   }
mcl::letter::letter(std::string s, cmd_color color) : string(s), color(color)
{   }

mcl::letter mcl::operator * (std::string string, cmd_color color) {
    return mcl::letter(string, color);
}
mcl::letter mcl::operator * (double number, cmd_color color) {
    return letter(number, color);
}
mcl::letter mcl::operator * (int number, cmd_color color) {
    return letter(number, color);
}
mcl::letter mcl::operator * (const char* string, cmd_color color) {
    return mcl::letter(string, color);
}
enum tag
{
    tab,
    endl,
    nsep
};

mcl::print::print() : last_color(7, 0)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}
void mcl::print::add(letter str)
{
    string.push_back(str);
}
void mcl::print::out(tag tag_)
{
    for (auto it : string)
    {
#ifdef text_color
        setConsoleColor(hConsole, it.color.textColor, it.color.backgroundColor);
#endif // text_color
        std::cout << it.string;
    }
#ifdef text_color
    setConsoleColor(hConsole, 7, 0);
#endif // text_color

    switch (tag_)
    {
    case tab:
        std::cout << "\t";
        break;
    case endl:
        std::cout << "\n";
        break;
    case nsep:
        break;
    default:
        break;
    }
    string.clear();
}
void mcl::print::SetPos(short x, short y)
{
    SetConsoleCursorPosition(hConsole, COORD{ x, y });
}

mcl::print& mcl::print::operator()(short x, short y)
{
    SetPos(x, y);
    return *this;
}


mcl::print& mcl::operator << (print& out, tag tag_) {
    out.out(tag_);
    return out;
}

mcl::print& mcl::operator << (print& out, letter str) {
    out.add(str);
    out.last_color = str.color;
    return out;
}

mcl::print& mcl::operator << (print& out, std::string str) {
    out.add(letter(str, out.last_color));
    return out;
}

mcl::print& mcl::operator << (print& out, const char* str) {
    out.add(letter(str, out.last_color));
    return out;
}

mcl::print& mcl::operator << (print& out, double num) {
    out.add(letter(std::to_string(num), out.last_color));
    return out;
}

mcl::print& mcl::operator << (print& out, int num) {
    out.add(letter(std::to_string(num), out.last_color));
    return out;
}


mcl::print cout;
mcl::cmd_color error_color(4, 0);
mcl::cmd_color success_color(2, 0);
mcl::cmd_color process_color(3, 0);
mcl::cmd_color data_color(15, 0);
mcl::cmd_color select_color(15, 8);
