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
#include "laba_5.h"

enum finds
{

	consistent_find,
	binary_find,
	interpolation_find,
	shell_find,

};


class arr_for_find : public arr_for_sort
{
public:
	arr_for_find(int len = 0) : arr_for_sort(len)
	{

	}
};



class find {
public:
	find(finds my_type) : my_type(my_type)
	{	}
	//protected:
	virtual int Find(arr_for_find& arr, int element) { return -1; }
	virtual void Info() {  };
private:
	finds my_type;

};




class consistent : public find {
public:
	consistent() : find(consistent_find)
	{	}
	//protected:
	int Find(arr_for_find& arr, int element) override
	{  
		for (int i = 0; i < arr.Size(); i++)
		{
			if (element == arr[i])
				return i;
		}
		return -1;

	};
	void Info() override
	{  
	

	};
private:
	finds my_type;

};

class binary : public find, private shell {
public:
	binary() : find(binary_find), shell()
	{	}
	int Find(arr_for_find& arr, int element) override
	{
		shell::Sort(arr);
		arr.Print();
		return BinaryFind(arr, 0, arr.Size(), element);
	};
	int BinaryFind(arr_for_find& arr, int start, int stop, int element)
	{
		arr.Print(start, stop);
		int mid = (start + stop) / 2;
		if (stop - start >= 1)
		{
			if (arr[mid] == element)
			{
				return mid;
			}
			else if (arr[mid] < element)
			{
				return BinaryFind(arr, mid + 1, stop, element);
			}
			else// if (arr[mid] < element)
			{
				return BinaryFind(arr, start, mid, element);
			}
		} else {
			return -1;
		}
	}
	void Info() override
	{
		
	};
private:
	finds my_type;

};




class interpolation : public find, private shell {
public:
	interpolation() : find(interpolation_find), shell()
	{	}
	int Find(arr_for_find& arr, int element) override
	{
		shell::Sort(arr);
		arr.Print();
		return InterpolationFind(arr, 0, arr.Size(), element);
	};
	int InterpolationFind(arr_for_find& arr, int start, int stop, int element)
	{
		arr.Print(start, stop);
		int d = ((stop - start) * (element - arr[start])) / (arr[stop-1] - arr[start]) + start;
		if (stop - start >= 1)
		{
			if (arr[d] == element)
			{
				return d;
			}
			else if (arr[d] < element)
			{
				return InterpolationFind(arr, d + 1, stop, element);
			}
			else// if (arr[mid] < element)
			{
				return InterpolationFind(arr, start, d, element);
			}
		}
		else {
			return -1;
		}
	}
	void Info() override
	{

	};
private:
	finds my_type;

};






