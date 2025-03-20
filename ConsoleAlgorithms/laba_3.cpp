





#include "laba_3.h" 



bool writeToHeap(const char* from, char** to)
{
	int size = strlen(from)+2;
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
	cout << name * data_color << "|" << second_name << "|" << login << "|" << pass << "|" << privateKey << mcl::endl;
	if(country != nullptr)
	cout << phone << "|" << country << "|" << age << mcl::endl;
	if (bookings != nullptr)
	{
		for(int i = 0; i < count_bookings; i++)
			cout << bookings[i]->data << "|" << bookings[i]->id << "|" << bookings[i]->term << mcl::endl;
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
	delete[] bookings;
	bookings = booking_;
}
void person::newPass( char* _newPass)
{
	for(int i = 0; _newPass[i] != '0'; i++)
	pass[i] = _newPass[i];
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
	for (int i = 0; i < count_bookings; i++)
	{
		delete bookings[i];
	}
	delete[] bookings;
}

void l3task1()
{

	person p1("name", "second name", "login", "pass");
	p1.editProfile();
	p1.print();
	p1.makeBooking(12);
	p1.makeBooking(9);
	p1.makeBooking(2);
	p1.makeBooking(8);
	p1.makeBooking(6);
	p1.print();
	//p1.newPass("123--123");


 }








