#pragma once



#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>







template<typename data_list_type>
struct leaf {
	leaf* next;
	leaf* prev;
	data_list_type data;
	leaf(data_list_type new_data) : data(new_data)
	{
		next = nullptr;
		prev = nullptr;
	}
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
		return data;
	}
};

template<typename data_list_type>
class list {
public:
	leaf<data_list_type>* start;
	void pushBack(data_list_type data_leaf)
	{
		//leaf<data_list_type>* new_leaf = new leaf<data_list_type>(data_leaf);
		leaf<data_list_type>* _leaf = start;
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
		leaf<data_list_type>* _leaf = start;

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
	leaf<data_list_type>* emplase(leaf<data_list_type>* pop_after)
	{
		leaf<data_list_type>* next_pop_leaf = pop_after->next;
		leaf<data_list_type>* next_leaf = next_pop_leaf->next;

		pop_after->before(next_leaf);
		next_leaf->after(pop_after);

		return next_pop_leaf;
	}
};









void l4task1();







