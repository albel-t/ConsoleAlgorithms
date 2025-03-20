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
struct item {
	//item(param_type i) : i{ i }
	//{	}
	//item() : i{ 0 }
	//{	}
	param_type i;
};


template<typename param_type>
struct items
{
	items(int size = LEN_PARAM) : size(size)
	{
		d = new item<param_type>[size];
	}
	param_type& operator [](unsigned int index) const
	{
		return d[index].i;
	}
	void add(item<param_type> newitem)
	{		
		item<param_type>* tmp;
		size++; 
		tmp = new item<param_type>[(size)]();

		tmp[size-1] = newitem;

		for (int i = 0; i < (size)-1; i++)
		{
			tmp[i] = d[i];
		}		
		//tmp[(size)-1] = { 0 };

		/*(*this)[(size) - 1] = newitem;*/
		delete [] d;
		d = tmp;
	}

	item<param_type>* d;
	int size;

};

template<typename param_type>
struct column
{
	char name[10];
	items <param_type>param;
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
	column<char[10]> second_name;
	column<int> age;
	column<char[10]> login;
	column<char[7]> pass;
	column<int> booking;
	column<int> term;

	void PrintRow(int index, int& nstr, int padding);
	void PrintName(int index, int& nstr, int padding);
	file_journal(int seed);

	int size;
};

void l2task1();
