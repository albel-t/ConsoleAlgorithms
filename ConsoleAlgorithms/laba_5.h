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

	selection_sort,
	exchange_sort,
	insert_sort,
	shell_sort
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
	{ }
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
	{ }
private:
};

class exchange : public sort
{
public:
	exchange() : sort(exchange_sort)
	{ }
	void Sort(arr_for_sort& arr) override
	{
		bool ready = true;
		while (ready)
		{
			ready = false;
			for (int i = 0; i < arr.Size() - 1; i++)
			{
				if (arr.Check(i, i + 1))
				{
					arr.Swap(i, i + 1);
					ready = true;
				}
			}
			if (debug >= sort_process)
				arr.Print();
		}
	}
	void Info() override
	{ }
private:
};

class insert : public sort
{
public:
	insert() : sort(insert_sort)
	{ 
		step = 1;
		start = 0;
	}
	void Sort(arr_for_sort& arr) override
	{
		for (int i = start+step, j = start+step; i < arr.Size(); i += step, j = i - step)
		{
			for (; (j > 0)&&(arr.Check(j, j + step)); j -= step)
			{
				arr.Swap(j, j + step);
				
				if (debug >= sort_process)
					arr.Print();
			}
			if (debug >= sort_process)
				arr.Print();			
		}
	}
	void Info() override
	{ }
protected:
	void SetStep(int new_step)
	{
		step = new_step;
	}
	void SetStart(int new_start)
	{
		start = new_start;
	}
private:
	int step, start;
};

class shell : public sort, private insert
{
public:
	shell() : sort(shell_sort)
	{

	}
	void Sort(arr_for_sort& arr) override
	{
		int step = 0;
		for (int i = arr.Size(); i > 0; i--)
		{
			if(GetStep(log2(i), arr.Size()) == step)
			{ continue; }
			step = GetStep(log2(i), arr.Size());
			for (int j = 0; j < step; j++)
			{
				SetStep(step);
				SetStart(j);
				insert::Sort(arr);
			}
		}
	}
	void Info() override
	{

	}
private:
	int GetStep(int i, int n)
	{
		int res;
		if (i % 2 == 0)
			res = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
		else
			res = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
		if (res * 3 > n)
			return GetStep(i - 1, n);
		return res;
	}
};


