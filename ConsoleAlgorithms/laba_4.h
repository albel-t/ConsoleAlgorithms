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
	int id_booking, term, type, stars, data, person_count;

	std::string print()
	{
		std::string tmp = std::to_string(id_booking) + "|"
			+ std::to_string(term			) + "|"
			+ std::to_string(type			) + "|"
			+ std::to_string(stars			) + "|"
			+ std::to_string(data			) + "|"
			+ std::to_string(person_count   ) + "\n";
		return tmp;
	}

};

enum params {

};

template<typename data_list_type>
struct leaf {

	leaf(data_list_type new_data) : data(new_data)
	{
		next = nullptr;
		prev = nullptr;
		//data = data_list_type(new_data);
	}
	leaf()
	{
		if(next != nullptr)
		delete next;
	}
	int padding()
	{
		return (int(this) - int(&data));
	}
private:
	data_list_type data;
	leaf* next;
	leaf* prev;
	

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
	std::string print()
	{
		return data.print();
	}
	

	template<typename data_list_type>
	friend class  list;
};

template<typename data_list_type>
class list {
	leaf<data_list_type>* start_;
	leaf<data_list_type>* current_;

public:
	 list(leaf<data_list_type>* start) : start_(start)
	 {
		 current_ = start_->next;
	 }
	 leaf<data_list_type>* start() {
		 return start_;
	 }
	 leaf<data_list_type>*& current() {
		 return current_;
	 }
	 bool end() {
		 return current_ == nullptr;
	 }
	 void reset() {
		 current_ = start_->next;
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
	leaf<data_list_type>* next()
	{
		current_ = current_->next;
		return current_;
	}


};






void actionsWithlist(list<booking_type> list_);


void l4task1();







