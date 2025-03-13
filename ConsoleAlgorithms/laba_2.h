#pragma once

//#include "laba_2.h"
#include "filework.h"
#include "MultiColorLine.h"

#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define LEN_PARAM 30


template<typename param_type>
struct column
{
	char name[10];
	param_type param[LEN_PARAM];
	column(const char* name_)
	{
		for (int i = 0; i < 10; i++)
		{
			name[i] = name_[i];
			if (name[i] == 0)
				break;
		}
	}
}; 

struct file_journal
{
	column<char[7]> name;
	column<int> age;
	column<char[10]> login;
	column<char[7]> pass;
	column<int> booking;

	file_journal(int seed);
};

void l2task1();
