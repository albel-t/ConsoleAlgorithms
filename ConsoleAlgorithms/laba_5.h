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

#include "MultiColorLine.h"


extern DWORD last_time;

#define TIME_IT last_time = GetTickCount();
#define COMPARE_TIME (int)(GetTickCount() - last_time)

#define SMALL_ARR_SIZE 30
#define BIG_ARR_SIZE 100000

enum debug_lvl
{
	only_sort_result, 
	sort_process, 
	inheritance_process
};

extern debug_lvl debug;


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
		for(int i = 0; i < size; i++)
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
		if ((data != nullptr)&&(size != len))
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
		for (int i = 0; i < size; i++)
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
				data[i] = data[i-1];
			}
			data[index_to] = tmp;
		}
		else
		{
			int tmp = data[index_from];
			for (int i = index_from; i <= index_to; i++)
			{
				data[i] = data[i+1];
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
		for (int i = 0; i < size-1; i++)
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
	int Size()
	{
		return size;
	}

private:

};


class sort{
public:
	sort(sorts my_type) : my_type(my_type)
	{	}
//protected:
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
	{
		cout << "selection sort \n\t- sorts by moving the minimum element to its place" << mcl::endl;
	}
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
	{ 
		cout << "exchange sort \n\t- sorts by exchange until condition is met for all elements" << mcl::endl;
	}
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
			for (; (j >= 0)&&(arr.Check(j, j + step)); j -= step)
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
	{
		cout << "insert sort \n\t- sorts by bringing each element to its place, at any stage the left part is already sorted" << mcl::endl;
	}
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
			if (debug >= sort_process)
				arr.Print();
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


class merger : public sort
{
public:
	merger() : sort(merger_sort)
	{

	}
	void Sort(arr_for_sort& arr) override
	{
		int size;
		arrs = Fragment(arr, size);
		arrs = Sort(arrs, size);
		Defragment(arrs, arr, size);
	}
	void Info() override
	{
		cout << "merger sort \n\t- splits into arrays and after merging the ones that satisfy the condition, goes into recursion" << mcl::endl;
	}
private:
	array** arrs;

	array** Merge(array** arrays, int& size_new_arr, int size)
	{
		array** new_arrs;
		size_new_arr = (size + 1) / 2;
		new_arrs = new array * [size_new_arr];
		if (debug >= sort_process)
		{
			cout << "before merge " << size << "to" << size_new_arr << mcl::endl;
			PrintFragments(arrays, size);
		}

		for (int i = 0; i < size_new_arr; i++)
		{
			int j_a_max = arrays[i * 2]->size, j_b_max = (size > i * 2 + 1) ?
				arrays[i * 2 + 1]->size : 0;
			if (debug >= sort_process)
			cout << "create arr for " << j_a_max << "+" << j_b_max << " elements:" << mcl::endl;
			int size_ = j_a_max + j_b_max;
			new_arrs[i] = new array(size_);
			int j_a = 0, j_b = 0;

			for (; j_a + j_b < size_;)
			{
				if (j_a == j_a_max) {
					new_arrs[i]->data[j_a + j_b] = arrays[i * 2 + 1]->data[j_b];
					j_b++;
				}
				else if (j_b == j_b_max) {
					new_arrs[i]->data[j_a + j_b] = arrays[i * 2]->data[j_a];
					j_a++;
				}
				else if (arrays[i * 2 + 1]->data[j_b] >= arrays[i * 2]->data[j_a]) {
					new_arrs[i]->data[j_a + j_b] = arrays[i * 2]->data[j_a];
					j_a++;
				}
				else {
					new_arrs[i]->data[j_a + j_b] = arrays[i * 2 + 1]->data[j_b];
					j_b++;
				}
			}
			if (debug >= sort_process)
				PrintFragment(new_arrs[i]);

		}
		if (debug >= sort_process)
		{
			cout << "after merge " << size << " to " << size_new_arr << mcl::endl;
			PrintFragments(new_arrs, size_new_arr);
		}
		return new_arrs;
	}
	array**& Sort(array** arrays, int size)
	{
		int size_new_arr = size;
		while (size_new_arr != 1)
		{
			array** tmp = Merge(arrays, size_new_arr, size);
			for (int i = 0; i < size; i++)
				delete arrays[i];
			delete[] arrays;
			arrays = tmp;
			size = size_new_arr;
			if (debug >= sort_process)
			PrintFragments(arrays, size_new_arr);
		}
		return arrays;
	}
	array** Fragment(arr_for_sort& arr, int& size)
	{
		size = arr.Size();
		array** arrays = new array * [size];
		for (int i = 0; i < size; i++)
		{
			arrays[i] = new array(1);
			arrays[i]->Copy(arr.data + i, 1);
		}
		return arrays;
	}
	void Defragment(array**& arrays, arr_for_sort& arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = arrays[0]->data[i];
		}
	}
	void PrintFragment(array*& fragment)
	{
		fragment->Print();
	}
	void PrintFragments(array** fragments, int len)
	{
		for (int i = 0; i < len; i++)
		{
			cout << "[" << i << "] = " << mcl::nsep;
			PrintFragment(fragments[i]);
		}
	}
};

class fast : public sort
{
public:
	fast() : sort(fast_sort)
	{

	}
	void Sort(arr_for_sort& arr) override
	{

		Swap(arr, arr.Size() / 2, arr.Size(), 0);
	}

	void Info() override
	{
		cout << "fast sort \n\t- sorts relative to the pivot and starts recursion" << mcl::endl;
	}
private:
	void Swap(arr_for_sort& arr, int middle, int size, int start)
	{
		
		middle = start + (size + 1) / 2  - size % 2;
		if (debug >= sort_process)
		{
			cout << "__recursion__" << mcl::endl;
			PrintSegment(arr, middle, size, start);
		}
		int center = middle;
		bool check_1, check_2;
		for (int i = 1; i <= (size-1)/2; i++)
		{

			check_1 = arr.Check(center - i, middle);
			check_2 = arr.Check(middle, center + i);
			if (check_1 && check_2)
			{
				if (debug >= sort_process)
				cout << "Swap" << mcl::endl;

				arr.Swap(center - i, center + i);
			}
			else if (check_1 || check_2)
			{
				if (check_1)
				{
					if (debug >= sort_process)
					cout << "Insert" << mcl::endl;
					arr.Insert(center - i, middle);
					middle--;
				}
				if (check_2)
				{
					if (debug >= sort_process)
					cout << "Insert" << mcl::endl;
					arr.Insert(center + i, middle);
					middle++;
				}
			}
			if (debug >= sort_process)
			PrintSegment(arr, middle, size, start);

		}
		if (size % 2 == 0)
		{
			if (arr.Check(start, middle))
			{
				arr.Insert(start, middle);
				middle--;
			}
		}
		if (debug >= sort_process)
		PrintSegment(arr, middle, size, start);

		int len_1 = middle - start;
		int len_2 = (start + size - 1) - middle;
		if (len_1 > 1)
		{
			Swap(arr, len_1 / 2 + start, len_1, start);
		}
		if (len_2 > 1)
		{
			Swap(arr, (len_2) / 2 + middle+1, len_2, middle+1);
		}
	}
	void PrintSegment(arr_for_sort& arr, int middle, int size, int start)
	{
		cout << " middle: " << middle << " size: " << size << " start: " << start << mcl::endl;

		for (int i = start; i < start + size; i++)
		{
			if (i == middle)
			{
				cout << " > " << arr[i] << mcl::nsep;
			}
			else
			{
				cout << " | " << arr[i] << mcl::nsep;
			}
		}			
		cout << " | " << mcl::endl;

	}
};


class heap : public sort
{
public:
	heap() : sort(heap_sort)
	{

	}
	void Sort(arr_for_sort& arr) override
	{
		for (max_index = arr.Size(); max_index > 0; max_index--)
		{
			Check(arr, 0);
			arr.Swap(0, max_index - 1);
			if (debug >= sort_process)
				arr.Print();
		}
	}
	void Info() override
	{ 
		cout << "heap sort \n\t- sorts using a binary tree folded into an array" << mcl::endl;
	}

private:
	void Check(arr_for_sort& arr, int index)
	{
		int branch_l = index*2 + 1, branch_r = index*2 + 2;
		if (branch_l < max_index)
		{
			Check(arr, branch_l);
			if (arr.Check(branch_l, index))
				arr.Swap(branch_l, index);
		}
		if (branch_r < max_index)
		{
			Check(arr, branch_r);
			if (arr.Check(branch_r, index))
				arr.Swap(branch_r, index);
		}
	}
	int max_index;
};


class radix : public sort
{
public:
	radix() : sort(radix_sort)
	{

	}
	void Sort(arr_for_sort& arr) override
	{
		for (int i = 0; i < MaxRadix(arr); i++)
		{
			Merge(�rushing(arr, i), arr);
		}
	}
	void Info() override
	{
		cout << "radix sort \n\t- sorts by rank" << mcl::endl;
	}

private:
	int MaxRadix(arr_for_sort& arr)
	{
		int max = arr[arr.Max(0)];
		int i = 0;
		for (; max > 0; i++, max = max / 10);
		return i;
	}
	void Merge(arr_for_sort* arrs, arr_for_sort& arr)
	{
		int k = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < arrs[i].Size(); j++)
			{
				arr[k] = arrs[i][j];
				k++;
			}
		}
		delete[] arrs;
	}
	arr_for_sort* �rushing(arr_for_sort& arr, int radix)
	{
		arr_for_sort* arrs = new arr_for_sort[10];
		for (int i = 0; i < arr.Size(); i++)
		{
			arrs[GetRadix(arr[i], radix)].Append(arr[i]);
		}
		return arrs;
	}
	int GetRadix(int num, int radix)
	{
		return ((int)(num / pow(10, radix)) % 10);
	}
};


void SortCheck(arr_for_sort& some_good_arr, sort* some_sort);

void l5task1();