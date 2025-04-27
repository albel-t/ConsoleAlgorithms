/****
    Связный список состоит из класса контейнера и классов элементов. каждый имеет полое с данными и указатели на прошлый и следующий элемент, нулевой явзяется экземпляром класса, без него работа невозможна. имеются функции добавления и удаленияб показа зависимости двух параметров
****/
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include <windows.h>
#include <cstdlib>


#include "laba_5.h"

#define LABSCOUNT 5

//#define TEST_MODE

DWORD last_time;

#define TIME_IT last_time = GetTickCount();
#define COMPARE_TIME (int)(GetTickCount() - last_time)


#define SMALL_ARR_SIZE 30
#define BIG_ARR_SIZE 1000000


void SortCheck(arr_for_sort& some_good_arr, sort* some_sort)
{
	cout << "before: " << mcl::nsep;
	//some_good_arr.Print();
	TIME_IT
		some_sort->Sort(some_good_arr);
	int time_is = COMPARE_TIME;
	cout << "after: " << mcl::nsep;
	//some_good_arr.Print();
	if (time_is < 1)
		cout << "time: <1ms." << mcl::endl;
	else
		cout << "time: " << time_is << "ms." << mcl::endl;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);




	shell Shell;
	megaShell MegaShell;



	arr_for_sort random_arr_30(SMALL_ARR_SIZE);
	arr_for_sort good_arr_30(SMALL_ARR_SIZE);
	arr_for_sort bad_arr_30(SMALL_ARR_SIZE);
	for (int i = 0; i < SMALL_ARR_SIZE; i++)
	{
		good_arr_30[i] = i;
		bad_arr_30[i] = SMALL_ARR_SIZE - i;
	}

	arr_for_sort random_arr_100000(BIG_ARR_SIZE);
	arr_for_sort good_arr_100000(BIG_ARR_SIZE);
	arr_for_sort bad_arr_100000(BIG_ARR_SIZE);
	for (int i = 0; i < BIG_ARR_SIZE; i++)
	{
		good_arr_100000[i] = i;
		bad_arr_100000[i] = BIG_ARR_SIZE - i;
	}

	{
		arr_for_sort _random_arr_100000 = random_arr_100000;
		arr_for_sort _good_arr_100000 = good_arr_100000;
		arr_for_sort _bad_arr_100000 = bad_arr_100000;
		SortCheck(_random_arr_100000, &MegaShell);
		SortCheck(_good_arr_100000, &MegaShell);
		SortCheck(_bad_arr_100000, &MegaShell);
	}
	{

		arr_for_sort _random_arr_100000 = random_arr_100000;
		arr_for_sort _good_arr_100000 = good_arr_100000;
		arr_for_sort _bad_arr_100000 = bad_arr_100000;
		SortCheck(_random_arr_100000, &Shell);
		SortCheck(_good_arr_100000, &Shell);
		SortCheck(_bad_arr_100000, &Shell);
	} 



}
