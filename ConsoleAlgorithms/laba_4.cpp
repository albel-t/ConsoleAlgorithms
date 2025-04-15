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
	list_.pushBack(booking_type{ 1, 6, 3, 4, 120422, 6 });
	list_.pushBack(booking_type{ 9, 7, 4, 1, 151122, 4 });
	list_.pushBack(booking_type{ 8, 5, 6, 4, 50523, 4 });
	list_.pushBack(booking_type{ 8, 12, 6, 5, 220424, 4 });
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

void statistics_1(list<booking_type> list_)
{
	int data[5] = { 0 };
	for (list_.reset(); !(list_.end()); list_.next())
	{
		data[list_.current()->data.stars % 5] += 1;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "[" << i << "]stars = " << data[i] << mcl::endl;
	}
}
int dateIncrement(int& input)
{
	int dd = input / 10000;
	int mm = (input / 100) % 100;
	int yy = input % 100;
	dd++;
	if(dd > 30)
	{
		dd = 1;
		mm++;
	}
	if (mm > 12)
	{
		mm = 1;
		yy++;
	}
	input = dd * 10000 + mm * 100 + yy;
	return  yy * 10000 + mm * 100 + dd;
}

void statistics_2(list<booking_type> list_)
{
	std::vector<int> days;
	for (list_.reset(); !(list_.end()); list_.next())
	{
		int date = list_.current()->data.date;
		int term = list_.current()->data.term;
		for (; term != 0; term--)
		{
			days.push_back(dateIncrement(date));
		}
	}
	std::sort(begin(days), end(days));
	int last_month = 0;
	cout << "all booking date: " << mcl::endl;

	for (auto it : days)
	{
		if (it / 100 != last_month)
		{
			last_month = it / 100;
			cout << "| " << mcl::endl;

		}
		cout << "| "<< it % 100 << "." << (it / 100) % 100 << "." << it / 10000 << mcl::nsep;
	}
}
void statistics_3(list<booking_type> list_)
{
	int person_count = 0;
	int stars = 0;
	for (list_.reset(); !(list_.end()); list_.next())
	{
		person_count += list_.current()->data.person_count;
		stars += list_.current()->data.stars * list_.current()->data.person_count;
	}

	cout << "person/stars degree:" << (double)stars/person_count << " stars per one persone " << mcl::endl;
	
}
void statistics_4(list<booking_type> list_)
{
	int date_1 = 0;
	int date_2 = 0;
	int type = 0;
	cout << "enter date from:" * data_color << mcl::endl;
	std::cin >> date_1;
	cout << "enter date to:" << mcl::endl;
	std::cin >> date_2;
	cout << "enter type:" << mcl::endl;
	std::cin >> type;

	date_1 = (date_1 % 100) * 10000 + ((date_1 / 100) % 100) * 100 + date_1 / 10000;
	date_2 = (date_2 % 100) * 10000 + ((date_2 / 100) % 100) * 100 + date_2 / 10000;
	std::vector<int> days;
	for (list_.reset(); !(list_.end()); list_.next())
	{
		if (type == list_.current()->data.type)
		{
			int date = list_.current()->data.date;
			int term = list_.current()->data.term;
			for (; term != 0; term--)
			{
				int date_ = (date % 100) * 10000 + ((date / 100) % 100) * 100 + date / 10000;

				if((date_ <= date_2)&&(date_ >= date_1))
				days.push_back(dateIncrement(date));
			}
		}
	}
	std::sort(begin(days), end(days));
	int last_month = 0;
	cout << "booking[" << date_1 << " - " << date_2 << "; type = " << type << "]:" << mcl::endl;
	for (auto it : days)
	{
		if (it / 100 != last_month)
		{
			last_month = it / 100;
			cout << "| " << mcl::endl;

		}
		cout << "| " << it % 100 << "." << (it / 100) % 100 << "." << it / 10000 << mcl::nsep;
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
		case 0://count persons / stars
		{
			statistics_1(list_);
		}break;
		case 1://data & time - all 
		{
			statistics_2(list_);
		}break;
		case 2://stars / all persons
		{
			statistics_3(list_);
		}break;
		case 3://type & count persons++
		{
			statistics_4(list_);
		}break;
		case 4:
		{
			addiction(std::make_pair(actions[select_a], select_a), std::make_pair(actions[select_b], select_b), list_);
			select_a = 0;
			select_b = 0;
		}break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		{
			push_A_B(select, select_a, select_b);
		}break;			
		case 11://print
		{
			list_.print();
		}break;
		case 12://del
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
		case 13://add
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
		case 14:
		{
			out = false;
		}break;
		default:
		{

		}break;
		}
		char i;
		std::cin >> i;//костыль
		cout << "\t\tpress any key to continue..." * process_color << mcl::space;
		//_getch();
		Sleep(300);
		system("cls");
	}
}
























