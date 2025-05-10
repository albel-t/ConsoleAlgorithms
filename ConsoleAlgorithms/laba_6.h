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

class ElementTree
{
public:
	ElementTree(int& data) : data(data)
	{

	}
	bool Compare(ElementTree someone)
	{
		return someone.data > data;
	}
	int& data;

};
class Num : public ElementTree
{
public:
	Num(int new_num) : num(new_num), ElementTree(num)
	{

	}

	int Get()
	{
		return num;
	}

	void Set(int new_num)
	{
		num = new_num;
	}

	int num;

};






class Tree
{
public:
	Tree(Num* new_element) : KidL(nullptr), KidR(nullptr), this_element(new_element)
	{
	
	}
	Tree(int new_element) : KidL(nullptr), KidR(nullptr)
	{
		this_element = new Num(new_element);
	}
	void Add(int new_element)
	{
		Add(new Num(new_element));
	}
	void Add(Num* new_element)
	{
		if (this_element != nullptr)
		{
			if (new_element->Compare(*this_element))
			{
				if (!KidL)
					KidL = new Tree(new_element);
				else
					KidL->Add(new_element);
			}
			else
			{
				if (!KidR)
					KidR = new Tree(new_element);
				else
					KidR->Add(new_element);

			}
		}
		else
		{
			this_element = new_element;
		}
	}
	int Print(int count, int lvl, int per_one_part = 1)
	{
		int lenR = 0, lenL = 0;
		if (KidL)
			lenL = KidL->Print(count, lvl+1, per_one_part);
		if (KidR)
			lenR = KidR->Print(count, lvl+1, per_one_part);
		int step = max(lenL, lenR)*2 + 4;
		if (lvl == count)
		{
			cout((step+4)*lenx + step/2, count) << this_element->data << " " << mcl::endl;
			lenx+= 1;
		}
		lvl++;
		//cout/*(count * (lenx * 2 + 1) + 1, count)*/ << this_element->data << mcl::endl;

		return step;
	}

	~Tree()
	{
		//KidL->~Tree();
		//KidR->~Tree();
	}
	static int lenx;
private:
	Num* this_element;
	Tree* KidL;
	Tree* KidR;
};

int Tree::lenx = 0;








