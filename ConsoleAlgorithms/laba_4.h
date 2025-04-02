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

template<typename data_list_type>
class list;

class booking_type{
public:
	std::string print()
	{
		std::cout << id_booking << "|"
			<< term << "|"
			<< type << "|"
			<< stars << "|"
			<< data << "|"
			<< person_count << std::endl;
	}
	int id_booking, term, type, stars, data, person_count;
};

enum params {

};

template<typename data_list_type>
struct leaf {

	leaf(data_list_type new_data)
	{
		next = nullptr;
		prev = nullptr;
		data = new data_list_type(new_data);
	}
	leaf()
	{
		if(next != nullptr)
		delete next;
	}
private:

	leaf* next;
	leaf* prev;
	data_list_type* data;

	leaf* after(leaf* after)
	{
		leaf* tmp = prev;
		prev = after;
		return tmp;
	}
	leaf* before(leaf* before)
	{
		leaf* tmp = next;
		next = before;
		return tmp;
	}
	data_list_type print()
	{
		return data->print();
	}


	template<typename data_list_type>
	friend class  list;
};

template<typename data_list_type>
class list {
	leaf<data_list_type>* start_;

public:
	 list(leaf<data_list_type>* start) : start_(start)
	 {	}
	leaf<data_list_type>*& start() {
		return start_;
	}

	void pushBack(data_list_type data_leaf)
	{
		//leaf<data_list_type>* new_leaf = new leaf<data_list_type>(data_leaf);
		leaf<data_list_type>* _leaf = start_;
		while (_leaf->next != nullptr)
			_leaf = _leaf->next;
		pushPtr(_leaf, data_leaf);
	}

	void pushPtr(leaf<data_list_type>* push_after, data_list_type data_leaf)
	{
		leaf<data_list_type>* new_leaf = new leaf<data_list_type>(data_leaf);
		leaf<data_list_type>* next_leaf = push_after->next;


		new_leaf->before(push_after->before(new_leaf));
		if (next_leaf)
			new_leaf->after(next_leaf->after(new_leaf));
		else
			new_leaf->after(push_after);
	}

	void print()
	{
		leaf<data_list_type>* _leaf = start_;

		std::cout << _leaf->print() << std::endl;

		while (_leaf->next != nullptr) 
		{
			_leaf = _leaf->next;
			std::cout << _leaf->print() << std::endl;
		}
		print_usd(_leaf);
	}

	void print_usd(leaf<data_list_type>* _leaf)
	{
		//leaf<data_list_type>* _leaf = start;
		std::cout << _leaf->print() << std::endl;

		while (_leaf->prev != nullptr)
		{
			_leaf = _leaf->prev;
			std::cout << _leaf->print() << std::endl;
		}
	}

	leaf<data_list_type>* popPtr(leaf<data_list_type>* pop_after)
	{
		leaf<data_list_type>* next_pop_leaf = pop_after->next;
		leaf<data_list_type>* next_leaf = next_pop_leaf->next;
		if (next_leaf != nullptr)
		{
			pop_after->before(next_leaf);
			next_leaf->after(pop_after);
		}
		else {
			pop_after->next = next_leaf;
			//next_leaf->prev = pop_after;
		}
		return next_pop_leaf;
	}

	leaf<data_list_type>* popBack()
	{
		leaf<data_list_type>* _leaf = start_;
		while (_leaf->next->next != nullptr)
			_leaf = _leaf->next;
		return popPtr(_leaf);
	}
	
	void find_for_param()
	{

	}

};






void actionsWithlist(list<booking_type> list_);


void l4task1();







