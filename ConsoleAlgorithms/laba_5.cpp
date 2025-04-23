


#include"laba_5.h"



void SortCheck(arr_for_sort& some_good_arr, sort* some_sort)
{
	cout << "before: " << mcl::nsep;
	some_good_arr.Print();
	TIME_IT
		some_sort->Sort(some_good_arr);
	int time_is = COMPARE_TIME;
	cout << "after: " << mcl::nsep;
	some_good_arr.Print();
	if (time_is < 1)
		cout << "time: <1ms." << mcl::endl;
	else
		cout << "time: " << time_is << "ms." << mcl::endl;
}

void l5task1()
{


	selection Selection;
	exchange Exchange;
	insert Insert;
	shell Shell;
	merger Merger;
	fast Fast;
	heap Heap;
	radix Radix;


	sort* sorts[8] = { &Selection , &Exchange , &Insert
		, &Shell , &Merger , &Fast , &Heap , &Radix };


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


	for (int i = 0; i < 8; i++)
	{
		cout << "\n=====================================================\t\t" * data_color << mcl::nsep;
		sorts[i]->Info();
		arr_for_sort _random_arr_30 = random_arr_30;
		arr_for_sort _good_arr_30 = good_arr_30;
		arr_for_sort _bad_arr_30 = bad_arr_30;
		SortCheck(_random_arr_30, sorts[i]);
		SortCheck(_good_arr_30, sorts[i]);
		SortCheck(_bad_arr_30, sorts[i]);
	}

	SortCheck(random_arr_100000, &Heap);
	SortCheck(good_arr_100000, &Heap);
	SortCheck(bad_arr_100000, &Heap);
}