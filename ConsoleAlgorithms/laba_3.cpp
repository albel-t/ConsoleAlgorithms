





#include "laba_3.h" 



bool writeToHeap(const char* from, char* &to)
{
	to = new char[strlen(from)];

	bool flag = false;
	for(int i = 0; i < strlen(from)+1; i++)
	if (!flag) {
		if ((from[i] == '\0') || (from[i] == '\n'))
			flag = true;
		to[i] = from[i];
	}
	return flag;
}

person::person(const char* name_, const char* second_name_, const char* login_, const char* pass_)
	//name(name_), second_name(second_name_), login(login_), pass(pass_)
{
	name		= new char[strlen(name_)];
	second_name = new char[strlen(second_name_)];
	login		= new char[strlen(login_)];
	pass		= new char[strlen(pass_)];
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
	country = nullptr;
	phone = nullptr;
	age = 0;
}


void person::editProfile()
{
	{
		cout << "enter country:" << mcl::space;
		char param[32] = { 0 };
		std::cin >> param;
		writeToHeap(param, this->country);
	} {
		cout << "enter phone:" << mcl::space;
		char param[32] = { 0 };
		std::cin >> param;
		writeToHeap(param, this->phone);
	} {
		cout << "enter age:" << mcl::space;
		int param = { 0 };
		std::cin >> param;
		this->age = param;
	}
}

void person::print()
{
	cout << name << "|" << second_name << "|" << login << "|" << pass << "|" << privateKey << mcl::endl;
	if(country != nullptr)
	cout << phone << "|" << country << "|" << age << mcl::endl;
}

person::~person()
{
	delete[] name;
	delete[] second_name;
	delete[] pass;
	delete[] login;
	delete[] country;
	delete[] phone;
}

void l3task1()
{

	person p1("name", "second name", "login", "pass");
	p1.editProfile();
	p1.print();






	return;
}








