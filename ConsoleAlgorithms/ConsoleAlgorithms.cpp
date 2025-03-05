
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>
#include <cstdlib>




#include "MultiColorLine.h"



int main()
{
    mcl::print cout;
    mcl::cmd_color color_1(10, 0);

    cout(10, 10) << "hello world" * color_1 << mcl::endl;

}
