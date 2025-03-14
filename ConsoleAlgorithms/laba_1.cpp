#include "laba_1.h"



void l1task1()
{
	cout << "#1. Дан текстовый файл. Удалить из него третью строку. Результат записать в другой файл." * process_color << mcl::endl;
	auto file1 = open("file11.txt", READ_FILE);
	auto file2 = open("file12.txt", WRITE_FILE);
	file_data* data = read(file1);
	for (int i = 0; i < data->size; i++)
	{
		if (i != 2)
		{ 
			fputs(data->strings[i], file2);
		}
	}
	close(file1);
	close(file2);
	delete data;
	cout << "#1" * process_color << mcl::endl;
}
void l1task2()
{
	cout << "#2. Имеется текстовый файл, в каждой строке которого первые два символа являются буквами. \r\nПолучить слово, образованное первыми буквами каждой строки." * process_color << mcl::endl;
	auto file1 = open("file21.txt", READ_FILE);
	file_data* data = read(file1);
	cout << "Answer:" * data_color << mcl::tab;
	for (int i = 0; i < data->size; i++)
	{
		char tmp[3] = {data->strings[i][0], data->strings[i][1], '\0'};
		cout << tmp * data_color << mcl::nsep;
	}
	cout << mcl::endl;
	close(file1);
	delete data;
	cout << "#2" * process_color << mcl::endl;
}
void l1task3()
{
	cout << "#3. Дан текстовый файл. Переписать его строки в обратном порядке (справа налево) в другой файл. \r\nПорядок строк во втором файле должен совпадать с порядком строк в заданном файле." * process_color << mcl::endl;
	auto file1 = open("file31.txt", READ_FILE);
	auto file2 = open("file32.txt", WRITE_FILE);
	file_data* data = read(file1);
	file_data* data_2 = new file_data(FILE_LEN, BUFF_LEN+1);
	for (int i = 0; i < data->size; i++)
	{
		int k = 0;
		for (int j = 0; j < data_2->lens; j++)
		{
			if ((data->strings[i][data->lens - j] > '\0') && (data->strings[i][data->lens - j] != '\n'))
			{
				data_2->strings[i][k] = data->strings[i][data->lens - j];
				k++;
			}
		}
		data_2->strings[i][k] = '\n';
	}
	for (int i = 0; i < data->size; i++)
	{
		cout << data->strings[i] * data_color << mcl::nsep;
		cout << data_2->strings[i] * data_color << mcl::endl;
	}

	write(file2, data_2);
	close(file1);
	close(file2);
	delete data;
	delete data_2;
	cout << "#3" * process_color << mcl::endl;
}
void l1task4()
{
	cout << "#4. Имеется типизированный файл, в котором записаны восемнадцать целых чисел. \r\nПереписать все положительные числа файла в массив в том же порядке." * process_color << mcl::endl;
	{
		srand(time(0));
		data nums;
		for (int i = 0; i < 18; i++)
			nums.num[i] = rand() % 1000 - 500;
		save<data>("file41.test", &nums);
	}

	data input = load<data>("file41.test");
	int nums1[18] = { 0 };
	int i1 = 0;
	cout << "Arr: " * data_color << mcl::endl;
	for (int i = 0; i < 18; i++)
	{
		cout << input.num[i] * data_color << "," << mcl::space;
		if (input.num[i] >= 0)
		{
			nums1[i1] = input.num[i];
			i1++;
		}
	}
	cout << "\nAnswer: " * data_color << mcl::endl;
	for (int i = 0; i < 18; i++)
	{
		if(nums1[i] != 0)
			cout << nums1[i] * data_color << "," << mcl::space;
	}
	cout << "\n#4" * process_color << mcl::endl;
}
void l1task5()
{
	
	data_str nums;
	save<data_str>("file51.test", &nums);
	data_str input = load<data_str>("file51.test");

	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (input.str[i][0] == 'м')
		{
			count++;
		}
	}
	cout << count << mcl::endl;
}
void l1task6()
{
	{
		srand(time(0));
		data nums;
		for (int i = 0; i < 18; i++)
			nums.num[i] = rand() % 1000;
		save("file61.test", &nums);
	}

	data input = load<data>("file61.test");
	data file_1;
	data file_2;
	int i1 = 0, i2 = 0;
	for (int i = 0; i < 18; i++)
	{
		if (input.num[i] % 2 == 0)
		{
			file_1.num[i1] = input.num[i];
			i1++;
		}
		else
		{
			file_2.num[i2] = input.num[i];
			i2++;
		}
	}
	save("file62.test", &file_1);
	save("file63.test", &file_2);

	data input1 = load<data>("file62.test");
	data input2 = load<data>("file63.test");

	for (int i = 0; i < 18; i++)
	{
		cout << input1.num[i] << "|" << input2.num[i] << mcl::endl;
	}
	cout << mcl::endl;
}

