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
		leaf<data_list_type>* new_leaf = new leaf<data_list_type>(data_leaf);
		leaf<data_list_type>* _leaf = start;
		while (_leaf->next != nullptr)
			_leaf = _leaf->next;
		
		new_leaf->before(_leaf->before(new_leaf));

		if (_leaf->next != nullptr)
		{
			_leaf = _leaf->next;
			new_leaf->after(_leaf->after(new_leaf));
		}
		else {
			new_leaf->after(_leaf);
		}
	}
	void print()
	{
		leaf<data_list_type>* _leaf = start;

		while (_leaf != nullptr)
		{
			std::cout << _leaf->print() << std::endl;
			_leaf = _leaf->next;
		}
	}
};









void l4task1();







