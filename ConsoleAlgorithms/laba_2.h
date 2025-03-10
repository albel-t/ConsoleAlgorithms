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

	file_journal(int seed) : name("name"), age("age"), login("login"), pass("pass"), booking("booking")
	{
		srand(seed);
		const char* g = "aeoiuy";
		const char* s = "bcdfghjklmnpqrstvwxyz";
		const char* a = "aeoiuybcdfghjklmnpqrstvwxyz1234567890";
		for (int i = 0; i < LEN_PARAM; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (j % 2 == 0)
					name.param[i][j] = g[rand() % (6  + (j > 3))];
				else
					name.param[i][j] = s[rand() % (21 + (j > 3))];

			}
			for (int j = 0; j < 9; j++)
			{
				login.param[i][j] = rand() % ('a' - 'z') + 'a';
			}
			for (int j = 0; j < 6; j++)
			{
				pass.param[i][j] = a[rand() % 37];
			}
			pass.param[i][6]  = '\0';
			name.param[i][6]  = '\0';
			login.param[i][9] = '\0';

			booking.param[i] = rand() % 1000 + 100000;
			age.param[i] = rand() % 40 + 18;

		}
	}
};

void l2task1()
{
	while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		file_journal* FILE_t1 = new file_journal(0);
		save<file_journal>("file2_1.txt", FILE_t1);
		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			int seed = 0;
			system("cls");
			cout << "enter seed: " << mcl::nsep;
			std::cin >> seed;
			file_journal* FILE_t1 = new file_journal(seed);
			save<file_journal>("file2_1.txt", FILE_t1);
		}
		file_journal file_ = load<file_journal>("file2_1.txt");


		cout(0, 6) << file_.name.name * process_color << mcl::tab;
		cout(13, 6) << file_.age.name << mcl::tab;
		cout(17, 6) << file_.login.name << mcl::tab;
		cout(30, 6) << file_.pass.name << mcl::tab;
		cout(40, 6) << file_.booking.name << mcl::endl;

		for (int i = 0; i < LEN_PARAM; i++)
		{

			cout(0, 7 + i) << file_.name.param[i] * data_color << mcl::tab;
			cout(13, 7 + i) << file_.age.param[i] << mcl::tab;
			cout(17, 7 + i) << file_.login.param[i] << mcl::tab;
			cout(30, 7 + i) << file_.pass.param[i] << mcl::tab;
			cout(40, 7 + i) << file_.booking.param[i] << mcl::endl;
		}
	}

}

