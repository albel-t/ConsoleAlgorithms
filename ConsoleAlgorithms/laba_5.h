#pragma once
#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <sysinfoapi.h>
#include <thread>

#include "MultiColorLine.h"




enum sorts
{

	selection_sort,
	exchange_sort,
	insert_sort,
	shell_sort,
	merger_sort,
	fast_sort,
	heap_sort,
	radix_sort
};


class array {
public:
	array(int len = 1)
	{
		data = nullptr;
		Create(len);
	}
	array(array& another)
	{
		Create(another.size);
		for (int i = 0; i < size; i++)
		{
			data[i] = another[i];
		}
	}
	int& operator[](int index)
	{
		return data[index];
	}

	int* data;
	int size;
	void Create(int len)
	{
		if ((data != nullptr) && (size != len))
			delete data;
		data = new int[len];
		size = len;
	}
	void Copy(int* start, int len)
	{
		Create(len);
		for (int i = 0; i < len; i++)
		{
			data[i] = start[i];
		}
	}
	~array()
	{
		if (data != nullptr)
			delete[] data;
		data = nullptr;
	}
	void Print()
	{
		for (int i = 0; i < size; i+=50)
		{
			cout << " | " << data[i] << mcl::nsep;
		}
		cout << " |" << mcl::endl;
	}
};


class arr_for_sort : public array {
public:
	arr_for_sort(int len = 0) : array(len)
	{
		Random(len);
	}
	void Random(int len)
	{
		Create(len);
		for (int i = 0; i < len; i++)
		{
			data[i] = rand() % 1000;
		}
	}
	void Swap(int index_1, int index_2)
	{
		int tmp = data[index_1];
		data[index_1] = data[index_2];
		data[index_2] = tmp;
	}
	void Insert(int index_from, int index_to)
	{
		if (index_to < index_from)
		{
			int tmp = data[index_from];
			for (int i = index_from; i >= index_to; i--)
			{
				data[i] = data[i - 1];
			}
			data[index_to] = tmp;
		}
		else
		{
			int tmp = data[index_from];
			for (int i = index_from; i <= index_to; i++)
			{
				data[i] = data[i + 1];
			}
			data[index_to] = tmp;
		}
	}
	bool Check(int index_1, int index_2)
	{
		return data[index_1] > data[index_2];
	}
	void Append(int num)
	{
		arr_for_sort tmp = *this;
		Create(size + 1);
		for (int i = 0; i < size - 1; i++)
		{
			data[i] = tmp[i];
		}
		data[size - 1] = num;
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
	int Max(int i)
	{
		int max = 0, ind = size;
		for (; i < size; i++)
		{
			if (max < data[i]) {
				max = data[i];
				ind = i;
			}
		}
		return ind;
	}
	unsigned int Size()
	{
		return size;
	}

private:

};
class better_arr_for_sort// : public arr_for_sort
{
public:
	better_arr_for_sort(arr_for_sort& arr, unsigned int step, unsigned int start) :
		arr(&arr) , step(step) , start(start)
	{   }
	arr_for_sort* arr;
	unsigned int step, start;

};

class sort {
public:
	sort(sorts my_type) : my_type(my_type)
	{	}
	//protected:
	virtual void Sort(arr_for_sort& arr) {  };
	virtual void Info() {};
private:
	sorts my_type;

};


void simple_sort_insert(better_arr_for_sort arr)
{
	unsigned int step = arr.step, start = arr.start;

	for (int i = start + step, j = start + step; i < arr.arr->Size(); i += step, j = i - step)
	{
		for (; (j >= 0) && (arr.arr->Check(j, j + step)); j -= step)
		{
			arr.arr->Swap(j, j + step);
		}

	}
	//delete arr;
}



class shell : public sort
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
			if (GetStep(log2(i), arr.Size()) == step)
			{
				continue;
			}
			step = GetStep(log2(i), arr.Size());
			for (int j = 0; j < step; j++)
			{
				simple_sort_insert(better_arr_for_sort(arr, step, j));
			}

		}
	}
	void Info() override
	{
		cout << "shell sort \n\t- sorts using insertion sort at different stages with different steps" << mcl::endl;
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



class megaShell : public sort
{
public:
	megaShell() : sort(shell_sort)
	{

	}
	void Sort(arr_for_sort& arr) override
	{
		int step = 0, tmp = 0;
		for (int i = arr.Size(); i > 0; i--)
		{
			tmp = GetStep(log2(i), arr.Size());
			if (tmp == step)
			{
				continue;
			}
			step = tmp;
			if (step < 50)
			{
				
				std::thread* threads = new std::thread[step];
				for (unsigned int j = 0; j < step-1; j++)
				{
					threads[j] = std::thread(simple_sort_insert, better_arr_for_sort(arr, step, j));
				}
				simple_sort_insert(better_arr_for_sort(arr, step, step-1));
				/*for (int threads_ind = 0; threads_ind < step - 1; threads_ind++)
				{
					threads[threads_ind].join();
					//delete threads[threads_ind];
				}*/
				threads[step - 2].join();
				delete[] threads;
				/*
				std::thread* load = nullptr;
				for (unsigned int j = 0; j < step; j++)
				{
					if (j != step - 1)
					std::thread t(simple_sort_insert, better_arr_for_sort(arr, step, j));
					else
						load = new std::thread(simple_sort_insert, better_arr_for_sort(arr, step, j));
				}
				load->join();*/
			}
			else
			{
				for (unsigned int j = 0; j < step; j++)
				{
					simple_sort_insert(better_arr_for_sort(arr, step, j));
				}

			}

		}
	}
	void Info() override
	{
		cout << "shell sort \n\t- sorts using insertion sort at different stages with different steps" << mcl::endl;
	}
private:
	int GetStep(int i, int n)
	{
		unsigned int res;
		if ((i & 1) == 0)
			res = 9 * pow(2, i) - 9 * pow(2, i / 2) + 1;
		else
			res = 8 * pow(2, i) - 6 * pow(2, (i + 1) / 2) + 1;
		if (res * 3 > n)
			return GetStep(i - 1, n);
		return res;
	}
};


void SortCheck(arr_for_sort& some_good_arr, sort* some_sort);

