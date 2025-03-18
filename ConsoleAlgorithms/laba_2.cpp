
#include "laba_2.h"

#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*column::column(const char* name_)
{
	for (int i = 0; i < 10; i++)
	{
		name[i] = name_[i];
		if (name[i] == 0)
			break;
	}
}*/
file_journal::file_journal(int seed) : name("name"), second_name("s_name"), 
age("age"), login("login"), pass("pass"), booking("booking"), term("term"), 
size(LEN_PARAM)
{
	srand(seed);

	const char* g = "aeoiuy";
	const char* s = "bcdfghjklmnpqrstvwxz";
	const char* l = "aeoiuybcdfghjklmnpqrstvwxyz";
	const char* a = "aeoiuybcdfghjklmnpqrstvwxyz1234567890";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j % 2 == 0)
				name.param[i][j] = g[rand() % (6 + (j > 3))];
			else
				name.param[i][j] = s[rand() % (21 + (j > 3))];
			
		}
		for (int j = 0; j < 9; j++)
		{
			if (j % 3 == 0)
				second_name.param[i][j] = g[rand() % (6 + (j > 3))];
			else if (j % 3 == 1)
				second_name.param[i][j] = l[rand() % (27 + (j > 3))];
			else
				second_name.param[i][j] = s[rand() % (21 + (j > 3))];
		}
		for (int j = 0; j < 9; j++)
		{
			login.param[i][j] = rand() % ('a' - 'z') + 'a';
		}
		for (int j = 0; j < 6; j++)
		{
			pass.param[i][j] = a[rand() % 37];
		}
		pass.param[i][6] = '\0';
		second_name.param[i][9] = '\0';
		name.param[i][6] = '\0';
		login.param[i][9] = '\0';

		booking.param[i] = rand() % 1000 + 100000;
		age.param[i] = rand() % 40 + 18;
		term.param[i] = rand() % 12 + 2;

	}
}


void file_journal::PrintRow(int index, int& nstr, int padding = 0)
{
	cout(padding, nstr) << "[" * data_color << index+1 << "]" << mcl::space;

	cout(5  + padding, nstr) << this->name.param[index] << mcl::tab;
	cout(15 + padding, nstr) << this->second_name.param[index] << mcl::tab;
	cout(30 + padding, nstr) << this->age.param[index] << mcl::tab;
	cout(40 + padding, nstr) << this->login.param[index] << mcl::tab;
	cout(50 + padding, nstr) << this->pass.param[index] << mcl::tab;
	cout(60 + padding, nstr) << this->booking.param[index] << mcl::tab;
	cout(70 + padding, nstr) << this->term.param[index] << mcl::endl;

	nstr++;
}

void l2task1()
{		
	const int com = 5;
	
	const char* actions[com] = { "seed",  "name", "login", "booking", "add"};		
	file_journal* FILE_t1 = new file_journal(0);

	while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
	{		
		save<file_journal>("file2_1.txt", FILE_t1);

		file_journal file_ = load<file_journal>("file2_1.txt");

		if (GetAsyncKeyState(VK_TAB) & 0x8000)
		{
			system("cls");
			int select = 0;
			while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				cout(0, 2) << "Select action: " * process_color << mcl::endl;
				if (GetAsyncKeyState(VK_TAB) & 0x8000)
				{
					select++;
					if (select >= com)
						select = 0;
					Sleep(90);
				}
				for (int l = 0; l < com; l++)
				{
					if (select == l)
					{
						cout(0, l + 4) << " >" * select_color << actions[l] << mcl::endl;
					}
					else
					{
						cout(0, l + 4) << actions[l] * data_color << "     " << mcl::endl;
					}
				}
			}
			switch (select)
			{
			case 0:
			{
				int seed = 0;
				system("cls");
				cout << "enter seed: " << mcl::space;
				std::cin >> seed;
				delete FILE_t1;
				FILE_t1 = new file_journal(seed);
				save<file_journal>("file2_1.txt", FILE_t1);
				break;
			}
			case 1:
			{
				char letter = 0;
				system("cls");
				cout << "enter letter for find name: " * process_color << mcl::space;
				std::cin >> letter;
				int flag_find = 0;
				for (int i = 0, n = 3; i < FILE_t1->size; i++)
				{
					if (FILE_t1->name.param[i][0] == letter)
					{
						flag_find ++;
						cout(0, n) << "sucsess: " * success_color << mcl::tab;
						FILE_t1->PrintRow(i, n, 10);
					}
				}
				if (!flag_find)
				{
					cout << "nothing was find " * error_color << mcl::endl;
				}
				_getch();
				Sleep(300);
			}
				break;
			case 2:
			{
				char letter = 0;
				system("cls");
				cout << "enter letter for find ligin: " * process_color << mcl::space;
				std::cin >> letter;
				int flag_find = 0;
				for (int i = 0, n = 3; i < FILE_t1->size; i++)
				{
					if (FILE_t1->login.param[i][0] == letter)
					{
						flag_find++;
						cout(0, n) << "sucsess: " * success_color << mcl::tab;
						FILE_t1->PrintRow(i, n, 10);
					}
				}
				if (!flag_find)
				{
					cout << "nothing was find" * error_color << mcl::endl;
				}
				_getch();
				Sleep(300);
			}
			break;
			case 3:
			{
				int count = 0;
				system("cls");
				cout << "enter num for watching new booking: " * process_color << mcl::space;
				std::cin >> count;
				int flag_find = 0;
				for (int i = 0, n = 3; i < FILE_t1->size; i++)
				{
					if (FILE_t1->booking.param[i] >= count)
					{
						flag_find++;
						cout(0, n) << "sucsess: " * success_color << mcl::tab;
						FILE_t1->PrintRow(i, n, 10);
					}
				}
				if (!flag_find)
				{
					cout << "nothing was find" * error_color << mcl::endl;
				}
				_getch();
				Sleep(300);
			}
			break;
			case 4:
			{
				system("cls");
				{
					cout << "enter name: " * process_color << mcl::space;
					item<char[7]> param = { 0 };
					std::cin >> param.i;
					//cout << param.i;
					FILE_t1->name.param.add(param);
					//FILE_t1->name.param[FILE_t1->size] = param;

					//for (int i = 0; i < 7; i++)
					//{
					//	FILE_t1->name.param[FILE_t1->size][i] = param[i];
					//	if (param[i] == '\0')
					//		break;
					//}
					//FILE_t1->name.param[FILE_t1->size][6] = '\0'
				} {
					cout << "enter second name: " * process_color << mcl::space;
					item<char[10]> param = { 0 };
					std::cin >> param.i;
					FILE_t1->second_name.param.add(param);
				} {
					cout << "enter age: " * process_color << mcl::space;
					item<int> param = { 0 };
					std::cin >> param.i;
					FILE_t1->age.param.add(param);
				} {
					cout << "enter login: " * process_color << mcl::space;
					item<char[10]> param = { 0 };
					std::cin >> param.i;
					FILE_t1->login.param.add(param);
				} {
					cout << "enter pass: " * process_color << mcl::space;
					item<char[7]> param = { 0 };
					std::cin >> param.i;
					FILE_t1->pass.param.add(param);
				} {
					cout << "enter booking: " * process_color << mcl::space;
					item<int> param = { 0 };
					std::cin >> param.i;
					FILE_t1->booking.param.add(param);
				} {
					cout << "enter term: " * process_color << mcl::space;
					item<int> param = { 0 };
					std::cin >> param.i;
					FILE_t1->term.param.add(param);
				}
				FILE_t1->size++;
				cout << "add element:" * process_color << mcl::space;
				int n = 15;
				FILE_t1->PrintRow((FILE_t1->size)-1, n);
				_getch();
				Sleep(300);
			}
			break;
			default:
				break;
			}
			system("cls");
		}


		cout(5, 6)  << FILE_t1->name.name * process_color << mcl::tab;
		cout(15, 6) << FILE_t1->second_name.name * process_color << mcl::tab;
		cout(30, 6) << FILE_t1->age.name << mcl::tab;
		cout(40, 6) << FILE_t1->login.name << mcl::tab;
		cout(50, 6) << FILE_t1->pass.name << mcl::tab;
		cout(60, 6) << FILE_t1->booking.name << mcl::endl;
		cout(70, 6) << FILE_t1->term.name << mcl::endl;

		for (int i = 0, n = 7; i < FILE_t1->size; i++)
		{
			FILE_t1->PrintRow(i, n);
		}
	}

}