
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
file_journal::file_journal(int seed) : name("name"), age("age"), login("login"), pass("pass"), booking("booking")
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
				name.param[i][j] = g[rand() % (6 + (j > 3))];
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
		pass.param[i][6] = '\0';
		name.param[i][6] = '\0';
		login.param[i][9] = '\0';

		booking.param[i] = rand() % 1000 + 100000;
		age.param[i] = rand() % 40 + 18;

	}
}

void l2task1()
{
	while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		file_journal* FILE_t1 = new file_journal(0);
		save<file_journal>("file2_1.txt", FILE_t1);
		const char* actions[4] = { "seed",  "name", "login", "booking" };
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
					if (select >= 4)
						select = 0;
					Sleep(90);
				}
				for (int l = 0; l < 4; l++)
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
				file_journal* FILE_t1 = new file_journal(seed);
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
				for (int i = 0; i < LEN_PARAM; i++)
				{
					if (FILE_t1->name.param[i][0] == letter)
					{
						flag_find ++;
						cout << "sucsess: " * success_color << mcl::tab;
						cout << FILE_t1->name.param[i] * data_color << mcl::tab;
						cout << FILE_t1->age.param[i] << mcl::tab;
						cout << FILE_t1->login.param[i] << mcl::tab;
						cout << FILE_t1->pass.param[i] << mcl::tab;
						cout << FILE_t1->booking.param[i] << mcl::endl;
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
				for (int i = 0; i < LEN_PARAM; i++)
				{
					if (FILE_t1->login.param[i][0] == letter)
					{
						flag_find++;
						cout << "sucsess: " * success_color << mcl::tab;
						cout << FILE_t1->name.param[i] * data_color << mcl::tab;
						cout << FILE_t1->age.param[i] << mcl::tab;
						cout << FILE_t1->login.param[i] << mcl::tab;
						cout << FILE_t1->pass.param[i] << mcl::tab;
						cout << FILE_t1->booking.param[i] << mcl::endl;
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
				for (int i = 0; i < LEN_PARAM; i++)
				{
					if (FILE_t1->booking.param[i] >= count)
					{
						flag_find++;
						cout << "sucsess: " * success_color << mcl::tab;
						cout << FILE_t1->name.param[i] * data_color << mcl::tab;
						cout << FILE_t1->age.param[i] << mcl::tab;
						cout << FILE_t1->login.param[i] << mcl::tab;
						cout << FILE_t1->pass.param[i] << mcl::tab;
						cout << FILE_t1->booking.param[i] << mcl::endl;
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
			default:
				break;
			}
			system("cls");
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