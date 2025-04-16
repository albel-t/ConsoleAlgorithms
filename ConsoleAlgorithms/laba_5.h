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




enum debug_lvl
{
	only_sort_result, 
	sort_process, 
	inheritance_process
};

 debug_lvl debug = inheritance_process;


enum sorts
{

	selection_sort

};




class arr_for_sort {
public:
	arr_for_sort(int len)
	{
		random(len);
	}
	void random(int len)
	{
		if (data != nullptr)
			delete data;
		data = new int[len];
		for (int i = 0; i < len; i++)
		{
			data[i] = rand() % 1000;
		}
		size = len;
	}
	void Swap(int index_1, int index_2)
	{
		int tmp = data[index_1];
		data[index_1] = data[index_2];
		data[index_2] = tmp;
	}
	bool Check(int index_1, int index_2)
	{
		return data[index_1] > data[index_2];
	}
	int Min(int i)
	{
		int min = 2000000, ind = size;
		for (; i < size; i++)
		{
			if (min > data[i]) {
				min = data[i];
				ind = i;
			}
		}
		return ind;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << " | " << data[i] << mcl::nsep;
		}
		cout << " |" << mcl::endl;
	}
	int Size()
	{
		return size;
	}
private:
	int* data;
	int size;
};


class sort{
public:
	sort(sorts my_type) : my_type(my_type)
	{	}
protected:
	virtual void Sort(arr_for_sort& arr) {  };
	virtual void Info() {};
private:
	sorts my_type;

};

class selection : public sort
{
public:
	selection() : sort(selection_sort)
	{

	}
	void Sort(arr_for_sort& arr) override
	{
		for(int i = 0; i < arr.Size()-1; i++)
		{ 
			arr.Swap(arr.Min(i), i);
			if (debug >= sort_process)
				arr.Print();
		}
	}
	void Info() override
	{

	}
private:


};




