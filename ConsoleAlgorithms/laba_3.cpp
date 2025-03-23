





#include "laba_3.h" 

bool equality(char* str1, char* str2)
{
	for (int i = 0; (str1[i] != '\0') && (str2[i] != '\0'); i++)
	{
		if (str1[i] != str2[i])
			return false;
	}
	return true;
}

bool writeToHeap(const char* from, char** to)
{
	int size = strlen(from)+2;
	if (*to != nullptr)
	{
		delete [] *to;
	}
	*to = new char[size];
	
	bool flag = false;
	for(int i = 0; i < strlen(from)+1; i++)
	if (!flag) {
		if ((from[i] == '\0') || (from[i] == '\n'))
			flag = true;
		(*to)[i] = from[i];
	}
	//*to[size] = '\0';
	return flag;
}

person::person(const char* name_, const char* second_name_, const char* login_, const char* pass_)
	//name(name_), second_name(second_name_), login(login_), pass(pass_)
{
	name		= new char[strlen(name_)		+ 1];
	second_name = new char[strlen(second_name_)	+ 1];
	login		= new char[strlen(login_)		+ 1];
	pass		= new char[strlen(pass_)		+ 1];
	bool allready = false, f_nr = false, f_snr = false, f_lr = false, f_pr = false;
	int i = 0;
	while(!allready)
	{ 
		if (!f_nr){
			if (name_[i] == '\0')
				f_nr = true;
			name[i] = name_[i];
		}

		if (!f_snr){
			if (second_name_[i] == '\0')
				f_snr = true;
			second_name[i] = second_name_[i];
		}

		if (!f_lr){
			if (login_[i] == '\0')
				f_lr = true;
			login[i] = login_[i];
		}

		if (!f_pr){
			if (pass_[i] == '\0')
				f_pr = true;
			pass[i] = pass_[i];
		}

		if (f_nr && f_snr && f_lr && f_pr)
			allready = true;

		i++;
	}
	
	id = last_id++;

	privateKey = rand() % 1000;
	count_bookings = 0;
	country = nullptr;
	phone = nullptr;
	bookings = nullptr;
	age = 0;
}


void person::editProfile()
{
	{
		cout << "enter country:" * process_color << mcl::space;
		char param[32] = { 0 };
		std::cin >> param;
		writeToHeap(param, &(this->country));
	} {
		cout << "enter phone:" << mcl::space;
		char param[32] = { 0 };
		std::cin >> param;
		writeToHeap(param, &(this->phone));
	} {
		cout << "enter age:" << mcl::space;
		int param = { 0 };
		std::cin >> param;
		this->age = param;
	}
}

void person::print()
{
	cout << "name: " * data_color << name << "\tsecond_name: " << second_name << "\nlogin: " << login << "\tpass: " << pass << "\nO-< privateKey:" << privateKey << mcl::endl;
	if(country != nullptr)
		cout << "phone: " << phone << "\ncountry: " << country << "\nade: " << age << mcl::endl;
	if (bookings != nullptr)
	{
		for (int i = 0; i < count_bookings; i++)
		{
			cout << "data: " << bookings[i]->data.YYYY << "." << bookings[i]->data.MM << "." << bookings[i]->data.DD << mcl::endl;
			cout << "ID: " << bookings[i]->id << mcl::endl;
			cout << "term - " << bookings[i]->term << mcl::endl;
		}
	}

}

void person::makeBooking(int term)
{
	count_bookings++;
	new_booking** booking_ = new new_booking * [count_bookings];
	for (int i = 0; i < count_bookings - 1; i++)
	{
		booking_[i] = bookings[i];
	}
	booking_[count_bookings - 1] = new new_booking(term);
	if(bookings != nullptr)
	delete[] bookings;
	bookings = booking_;
}

void person::setPass( char* _newPass)
{
	if (pass != nullptr)
	{  delete [] pass;  }
	pass = new char[strlen(_newPass)];
	for(int i = 0; _newPass[i] != '0'; i++)
	pass[i] = _newPass[i];
}


bool person::newPass(char* _newPass, char* _check)
{
	if (strlen(_check) == strlen(pass) && equality(_check, pass))
	{
		return writeToHeap(_newPass, &pass);
	}
}

void person::bithday()
{
	age++;
}

bool person::clearBooking(char* _pass)
{
	if (strlen(_pass) == strlen(pass) && equality(_pass, pass))
	{
		for (int i = 0; i < count_bookings; i++)
		{
			delete bookings[i];
		}
		delete[] bookings;
		count_bookings = 0;
		bookings = nullptr;
	}
	return true;
}

char* person::myName() 
{
	return name;
}
char* person::myPass()
{
	return pass;
}


person::~person()
{
	delete[] name;
	delete[] second_name;
	delete[] pass;
	delete[] login;

	if (country != nullptr)
	{
		delete[] country;
		delete[] phone;
	}
	clearBooking(pass);
}

void actionsWithPerson(person*& pers)
{
	bool out = true;
	const int com = 8;
	const char* actions[com] = { "make booking",  "new pass", "i have a bithday", "clear booking", "edit profile", "print all data", "[-] delete", "<- Exit"};
	Sleep(500);

	while ((!(GetAsyncKeyState(VK_SPACE) & 0x8000)) && out)
	{
		//if (GetAsyncKeyState(VK_TAB) & 0x8000)
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
				int data = 0;
				cout << "[Make new booking]\nHow long do you want to book? -  " * process_color << mcl::nsep;
				std::cin >> data;
				pers->makeBooking(data);
			}break;
			case 1:
			{
				char data_1[20] = { 0 };
				char data_2[20] = { 0 };
				cout << "[Set new pass]\nEnter old pass: " * process_color << mcl::nsep;
				std::cin >> data_1;
				cout << "Enter new pass: " * process_color << mcl::nsep;
				std::cin >> data_2;
				if (pers->newPass(data_2, data_1))
					cout << "you set new pass <" * success_color << pers->myPass() << ">" << mcl::endl;
				else
					cout << "oops something went wrong" * error_color << mcl::endl;
			}break;
			case 2:
			{
				char data = '\0';
				cout << "do you have a bithday? [Y/N]: " * process_color << mcl::nsep;
				std::cin >> data;

				if (data == 'Y')
				{
					cout << "oh, happy bithday!" * data_color << mcl::endl;
					pers->bithday();
				}
				else if(data == 'N')
					cout << "oh, sorry" * data_color << mcl::endl;
				else
					cout << "oops something went wrong" * error_color << mcl::endl;
			}break;
			case 3:
			{
				char data = '\0';
				cout << "you want to clean booking? [Y/N]: " * process_color << mcl::nsep;
				std::cin >> data;

				if (data == 'Y')
				{
					char pass_[20] = { 0 };
					cout << "ok! one second...\nEnter you pass:" * data_color << mcl::endl;
					std::cin >> pass_;
					cout << (pers->clearBooking(pass_)? "success"*success_color : "wrong pass!"*error_color) << mcl::endl;
				}
				else if (data == 'N')
					cout << "one second, return to menu" * data_color << mcl::endl;
				else
					cout << "oops something went wrong" * error_color << mcl::endl;
			}break;
			case 4:
				pers->editProfile();
				break;
			case 5:
			{/*
				char data = '\0';
				cout << "you want to see all? [Y/N]: " * process_color << mcl::nsep;
				std::cin >> data;
				if (data == 'Y')
				{
					cout << "oh, happy bithday!" * data_color << mcl::endl;
					pers->bithday();
				}
				else if (data == 'N')
					cout << "oh, sorry" * data_color << mcl::endl;
				else
					cout << "oops something went wrong" * error_color << mcl::endl;
				*/
				while(_kbhit())
					_getch();
				std::cin.ignore();
				pers->print();
				Sleep(1000);
				break;
			}
			case 6:
				pers->~person();
				pers = nullptr;
				break;
			case 7:
				out = false;
			default:
				break;
			}
			cout << "\t\tpress any key to continue..." * process_color << mcl::space;
			_getch();
			Sleep(300);
			system("cls");
		}
	}
}

void l3task1()
{	
	const int com = 10;
	person* persons[com] = { 0 };
	while (!(GetAsyncKeyState(VK_SPACE) & 0x8000))
	{
		//if (GetAsyncKeyState(VK_TAB) & 0x8000)
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
						cout(0, l + 4) << " >" * select_color << mcl::nsep;
						if (l < 9)
							cout << (persons[l] ? persons[l]->myName() : "--none--") << mcl::endl;
						else
							cout << "new" << mcl::endl;

					}
					else
					{
						if (l < 9)
							cout(0, l + 4) << (persons[l] ? persons[l]->myName() : "--none--") * data_color << mcl::nsep;
						else
							cout(0, l + 4) << "new" * data_color << mcl::nsep;
						cout << "     " << mcl::endl;
					}
				}
			}
			switch (select)
			{
			case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				if (persons[select] != nullptr)
					actionsWithPerson(persons[select]);
				else
					cout << "this person doesn't exist" * error_color << mcl::endl;
				break;
			case 9:
			{
				const int max_len = 20;
				char name[max_len], second_name[max_len], login[max_len], pass[max_len];
				cout << "enter name: " * process_color << mcl::nsep;
				std::cin >> name;
				cout << "enter second_name: " * process_color << mcl::nsep;
				std::cin >> second_name;
				cout << "enter login: " * process_color << mcl::nsep;
				std::cin >> login;
				cout << "enter pass: " * process_color << mcl::nsep;
				std::cin >> pass;



				for (int i = 0; i <= com; i++)
					if (i == com)
						cout << "Error: overflow" * error_color << mcl::endl;
					else
						if (persons[i] == nullptr)
						{
							persons[i] = new person(name, second_name, login, pass);
							break;
						}

				break;
			}
			default:
				break;
			}
			cout << "\t\tpress any key to continue..." * process_color << mcl::space;
			//_getch();
			Sleep(300);
			system("cls");
		}
	}
 }








