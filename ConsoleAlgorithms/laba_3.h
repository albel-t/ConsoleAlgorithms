#pragma once

#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MultiColorLine.h"



struct new_booking
{
	new_booking(int term) : term(term)
	{
		last_id += rand() % 100+ last_id;
		id = last_id;
		data = last_id % 1000;
	}
	int id, term, data;
	static int last_id;
};

class person
{
public:
	person(const char* name, const char* second_name, const char* login, const char* pass);

	void editProfile();

	void print();

	void makeBooking(int term);
	void newPass( char* _newPass);

	~person();

private:
	//friend bool writeToHeap(const char* from, char*& to);
	static int last_id;

	char* name, * second_name;
	char* pass, * login;

	char* country, * phone;

	int age, id, privateKey;
	new_booking** bookings;
	int count_bookings;



};


//extern int new_booking::last_id = 0;
//extern int person::last_id = 0;





void l3task1();











