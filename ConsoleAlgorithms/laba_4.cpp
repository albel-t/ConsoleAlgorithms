#include "laba_4.h"








void push_A_B(int data, int& a, int& b)
{
	if (!a)
	{
		a = data;
	} else {
		b = data;
	}
}

void l4task1()
{

	list<booking_type> list_(new leaf<booking_type>({0, 0, 0, 0, 0, 0}));
	list_.pushBack(booking_type{ 1, 2, 3, 4, 5, 6 });
	list_.pushBack(booking_type{ 9, 5, 4, 1, 6, 4 });
	list_.pushBack(booking_type{ 8, 5, 6, 4, 5, 4 });
	list_.pushBack(booking_type{ 8, 5, 6, 4, 5, 4 });
	actionsWithlist(list_);



}
template<typename data_list_type>
void addiction(std::pair<const char* ,int> param_a, std::pair<const char*, int> param_b, list<data_list_type>& list_with_params)
{
	//list_with_params.print();
	for (list_with_params.reset(); !(list_with_params.end()); list_with_params.next())
	{
		int* ptr = reinterpret_cast<int*>(reinterpret_cast<char*>(list_with_params.current()) + list_with_params.current()->padding());

		cout << "block: {" * process_color << (int)ptr << "}" << mcl::endl;

		cout << param_a.first * data_color << " = " << *(ptr + param_a.second - 1) << mcl::endl;
		cout << param_b.first << " = " << *(ptr + param_b.second - 1) << mcl::endl;
	}

}

void actionsWithlist(list<booking_type> list_)
{
	bool out = true;
	const int com = 11;
	const char* actions[com] = { "show addiction", "id_booking",  "term", "type", "stars", "data", "person count", "print", "[-] delete", "[+] add", "<- Exit" };
	int select_a = 0, select_b = 0;
	
	Sleep(500);

	while ((!(GetAsyncKeyState(VK_SPACE) & 0x8000)) && out)
	{
		{
			system("cls");
			int select = 0;
			while ((!(GetAsyncKeyState(VK_SPACE) & 0x8000)) && out)
			{
				cout(0, 2) << "Select action: " * process_color << mcl::endl;
				cout(0, 3) << "select_a = " * process_color << (select_a ? actions[select_a] : "---") <<
							"; select_b = " * process_color << (select_b ? actions[select_b] : "---") << mcl::endl;

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
				char i;
				addiction(std::make_pair(actions[select_a], select_a), std::make_pair(actions[select_b], select_b), list_);
				std::cin >> i;//костыль
				select_a = 0;
				 select_b = 0;
			}
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			{
				push_A_B(select, select_a, select_b);
			}break;			
			case 7://print
			{
				char i;
				list_.print();
				std::cin >> i;//костыль
			}break;
			case 8://del
			{
				Sleep(300);
				list_.reset();
				bool out_del = true;

				while ((!(GetAsyncKeyState(VK_SPACE) & 0x8000)) && out_del)
				{
					const char* actions_del[3] = { "next ->", "delete", "previous <-" };
					system("cls");
					int select_del = 0;
					while ((!(GetAsyncKeyState(VK_SPACE) & 0x8000)) && out_del)
					{
						if (GetAsyncKeyState(VK_TAB) & 0x8000)
						{
							select_del++;
							if (select_del >= 3)
								select_del = 0;
							Sleep(90);
						}
						for (int l_del = 0; l_del < 3; l_del++)
						{
							if (select_del == l_del)
							{
								cout(0, l_del + 4) << " >" * select_color << actions_del[l_del] << mcl::endl;
							}
							else
							{
								cout(0, l_del + 4) << actions_del[l_del] * data_color << "     " << mcl::endl;
							}
						}
						list_.print(true);
					}
					switch (select_del)
					{
					case 0:
					{
						list_.next();
					}break;
					case 1:
					{
						delete list_.popThis(list_.current());
						out_del = false;
					}break;
					case 2:
					{
						list_.previous();
					}break;
					}
					Sleep(300);
				}

			}break;
			case 9://add
			{
				int id_booking, term, type, stars, data, person_count;
				cout << "enter data with spaces: id_booking, term, type, stars, data, person_count." << mcl::endl;
				std::cin >> id_booking
					>> term
					>> type
					>> stars
					>> data
					>> person_count;
				list_.pushBack({ id_booking, term, type, stars, data, person_count });
			}break;
			case 10:
			{
				out = false;
			}break;
			default:
			{

			}break;
			}
			cout << "\t\tpress any key to continue..." * process_color << mcl::space;
			_getch();
			Sleep(300);
			system("cls");
		}
	}
}
























