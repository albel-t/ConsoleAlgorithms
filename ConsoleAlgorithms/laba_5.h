#pragma once


debug_lvl debug = inheritance_process;


enum debug_lvl
{
	only_sort_result, 
	sort_process, 
	inheritance_process
};



enum sorts
{

	selection_sort

};




class arr_for_sort {
public:
	arr_for_sort()
	{

	}
	void swap(int index_1, int index_2)
	{
		data[index_1] ^= data[index_2] ^= data[index_1] ^= data[index_2];
	}
	bool check(int index_1, int index_2)
	{
		return data[index_1] > data[index_2];
	}
private:
	int* data;

};


class sort{
public:
	sort(sorts my_type) : my_type(my_type)
	{	}
protected:
	virtual void Sort(arr_for_sort& arr);
	virtual void Info();
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

	}
	void Info() override
	{

	}
private:

};




