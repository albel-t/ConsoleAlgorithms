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

#define BIGNUM 1000000

class graph_weighted
{
public:
	graph_weighted(int size) : size(size)
	{
		units = new int* [size];
		for (int i = 0; i < size; i++)
			units[i] = new int[size];
		Init();
	}
	void Init()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				if (rand() % 10 <= 3)
					AddWay(i, j, rand() % 9 + 1);
				else
					AddWay(i, j, BIGNUM);
			}
		}
	}
	void AddWay(int id_from, int id_to, int len = 1)
	{
		units[id_from][id_to] = len;
		units[id_to][id_from] = len;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				cout << (units[i][j]!= BIGNUM? units[i][j]:0) << "|" << mcl::space;
			cout << mcl::endl;
		}
	}
	void Find(int start, int stop)
	{
		auto visited = new bool[size];
		auto min_way = new int[size];
		for (int i = 0; i < size; i++)
		{
			min_way[i] = units[start][i];
			visited[i] = false;
		}
		min_way[start] = 0;
		int index = 0, u = 0;
		for (int i = 0; i < size; i++)
		{
			int min = BIGNUM;
			for (int j = 0; j < size; j++)
			{
				if (!visited[j] && min_way[j] < min)
				{
					min = min_way[j];
					index = j;
				}
			}
			u = index;
			visited[u] = true;
			for (int j = 0; j < size; j++)
			{
				if (!visited[j] && units[u][j] != BIGNUM && min_way[u] != BIGNUM && (min_way[u] + units[u][j] < min_way[j]))
				{
					min_way[j] = min_way[u] + units[u][j];
				}
			}
		}

		for (int i = 0; i < size; i++)
		{
			//cout << start << " - " << i << "| " << min_way[i] << mcl::endl;
		}
		cout << " Len  =  " << min_way[stop] << mcl::endl;
	}
private:
	int** units;
	int size;
};





class graph_unweighted
{
public:
	graph_unweighted(int size) : size(size)
	{
		units = new bool*[size];
		for(int i = 0; i < size; i++)
			units[i] = new bool[size];
		Init();
	}
	void Init()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < i+1; j++)
			{
				if(rand() % 10 <= 3)
					AddWay(i, j);
				else
					AddWay(i, j, false);
			}
		}
	}
	void AddWay(int id_from, int id_to, bool val = true)
	{
		units[id_from][id_to] = val;
		units[id_to][id_from] = val;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				cout << units[i][j] << "|" << mcl::space;
			cout << mcl::endl;
		}
	}
	typedef std::vector<std::pair<int,int>> ways_type;
	void Find(int start, int stop)
	{
		bool end = false;
		int prew = -1;
		ways_type ways;
		ways_type last;
		std::vector<int> answer;
		ways.push_back(std::make_pair(start, -1));
		visit.push_back(start);
		last.push_back(std::make_pair(start, -1));
		while (!end)
		{
			ways_type new_last;
			for (auto it : last)
			{
				auto tmp = search(it.first);
				new_last.insert(new_last.end(), tmp.begin(), tmp.end());
			}
			ways.insert(ways.end(), last.begin(), last.end());
			last = new_last;
			for (auto it : last)
				if (it.first == stop)
				{
					end = true;
					prew = it.second;
				}
			if (last.empty())
				end = true;
		}
		answer.push_back(stop);
		ways.insert(ways.end(), last.begin(), last.end());
		while (prew != -1)
		{
			answer.push_back(prew);
			for (auto it : ways)
			{
				if (it.first == prew)
				{
					prew = it.second;
					break;
				}
			}
		}
		cout << "answer:\n Way  =  " << mcl::nsep;
		for (auto it : answer)
			cout << it << "," << mcl::nsep;
		cout << " Len  =  " << mcl::nsep;
		cout << int(answer.size()-1) << mcl::endl;


	}
	ways_type search(int id_current)
	{
		ways_type last_row;
		for (int i = 0; i < size; i++)
		{
			bool flag = true;
			for (auto it : visit)
				if (it == i)
					flag = false;
			if ((units[id_current][i]) && (i != id_current) && (flag))
			{
				last_row.push_back(std::make_pair(i, id_current));
				visit.push_back(i);
			}

		}
		return last_row;
	}

private:
	std::vector<int> visit;
	bool** units;
	int size;
};











void l7task1();
























