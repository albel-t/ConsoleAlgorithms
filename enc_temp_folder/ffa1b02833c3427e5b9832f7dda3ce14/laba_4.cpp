#include "laba_4.h"










void l4task1()
{

	list<booking_type> list_(new leaf<booking_type>({0, 0, 0, 0, 0, 0}));
	list_.pushBack(booking_type{ 1, 2, 3, 4, 5, 6 });
	actionsWithlist(list_);



}
template<typename data_list_type>
void addiction(std::pair<const char* ,int> param_a, std::pair<const char*, int> param_b, list<data_list_type>& list_with_params)
{
	list_with_params.print();
	for (list_with_params.reset(); !(list_with_params.end()); list_with_params.next())
	{
		int* ptr = reinterpret_cast<int*>(reinterpret_cast<char*>(list_with_params.current()) + list_with_params.current()->padding());
		std::cout << param_a.first << " = " << *(ptr + param_a.second) << std::endl;
		std::cout << param_b.first << " = " << *(ptr + param_b.second) << std::endl;
	}

}

void actionsWithlist(list<booking_type> list_)
{
	bool out = true;
	const int com = 10;
	const char* actions[com] = { "id_booking",  "term", "type", "stars", "data", "person count", "print", "[-] delete", "[+] add", "<- Exit" };
	Sleep(500);

	while ((!(GetAsyncKeyState(VK_SPACE) & 0x8000)) && out)
	{
		{
			system("cls");
			int select = 0;
			while ((!(GetAsyncKeyState(VK_SPACE) & 0x8000)) && out)
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
				char i;
				addiction(std::make_pair(actions[select], select), std::make_pair(actions[select+1], select+1), list_);
				std::cin >> i;
			}
			case 1:
			{

			}
			case 2:
			{

			}
			case 3:
			{

			}
			case 4:
			{

			}
			case 5:
			{

			}break;			
			case 6://print
			{

			}break;
			case 7://del
			{

			}break;
			case 8://add
			{
				int id_booking, term, type, stars, data, person_count;
				std::cin >> id_booking
					>> term
					>> type
					>> stars
					>> data
					>> person_count;
				list_.pushBack({ id_booking, term, type, stars, data, person_count });
			}break;
			case 9:
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
























