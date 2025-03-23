#pragma once

#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>

#include "MultiColorLine.h"


struct new_booking
{
	new_booking(int term) : term(term)
	{
		last_id += rand() % 10;
		id = last_id;
		//data = last_id % 1000 + rand() % 100;
	}
	
	
	struct data 
	{
		data()
		{
			YYYY = 2000 + rand() % 30;
			MM = rand() % 12 + 1;
			DD = rand() % 31 + 1;
		}
		int YYYY, MM, DD;

	};
	data data;
	int id, term;
	static int last_id;
};

class person
{
public:
	person(const char* name, const char* second_name, const char* login, const char* pass);

	void editProfile();

	void print();

	void makeBooking(int term);
	bool newPass(char* _newPass, char* _check);
	void bithday();
	bool clearBooking(char* _pass);

	char* myName();
	char* myPass();


	~person();

private:
	//friend bool writeToHeap(const char* from, char*& to);
	void setPass(char* _newPass);

	static int last_id;

	char* name, * second_name;
	char* pass, * login;

	char* country, * phone;

	int age, id, privateKey;
	new_booking** bookings;
	int count_bookings;



};

//bool equality(char* str1, char* str2);


//extern int new_booking::last_id = 0;
//extern int person::last_id = 0;





void l3task1();











