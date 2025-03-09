#include "laba_1.h"
#include "MultiColorLine.h"


FILE* open(const char* nameFile, const char* arg)
{
	FILE* f;
	;
	if (fopen_s(&f, nameFile, arg) == EINVAL) {
		cout << "Error opening file. The file may be missing." * error_color << mcl::endl;
	}
	else {
		cout << "file \"" * success_color << nameFile << "\" was open." << mcl::endl;
	}
	return f;
}

bool readline(FILE* file, char* buff, buff_size size)
{
	cout << "Reading..." * process_color << mcl::endl;
	if ((!feof(file)) && (fgets(buff, size, file) != NULL)) 
	{
		cout << "Successful reading." * success_color << mcl::endl;
		return true;
	} else {
		if (feof(file))
		{
			cout << "End of file." * error_color << mcl::endl;
		} else {
			cout << "An error occurred while reading from the file." * error_color << mcl::endl;
		}
		return false;
	}
}


file_data::file_data(file_size size, buff_size lens) : size{ size }, lens{ lens }
{
	strings = new char* [size];
	for (int i = 0; i < size; i++)
	{
		strings[i] = new char[lens] {0};
	}
}
file_data::~file_data()
{
	for (int i = 0; i < size; i++)
	{
		delete [] strings[i];
	}
	delete[] strings;
}


file_data* read(FILE* file)
{
	file_data* file_ = new file_data(FILE_LEN, BUFF_LEN);
	for (int i = 0; i < file_->size; i++)
	{
		if (!readline(file, file_->strings[i], file_->lens))
		{
			break;
		}
	}
	cout << "Successful reading all file." * success_color << mcl::endl;
	return file_;
}

bool write(FILE* file, file_data* data)
{
	for (int i = 0; i < data->size; i++)
	{
		if (fputs(data->strings[i], file) == EOF) {
			cout << "An error occurred while writing to the file." * error_color <<mcl::endl;
			return false;
		}
	}
	cout << "Successful writing all file." * success_color << mcl::endl;
	return true;
}

void close(FILE* file)
{
	fclose(file);
	cout << "file was closed." * success_color << mcl::endl;
}
template<typename data_type>
void save(const char* filename, data_type* p)
{
	FILE* fp;
	char* c;
	int size = sizeof(data_type);
	fp = open(filename, WRITE_BIN_FILE);
	c = (char*)p;
	for (int i = 0; i < size; i++)
	{
		putc(*c++, fp);
	}
	close(fp);
}
template<typename data_type>
data_type load(const char* filename)
{
	FILE* fp;
	char* c;
	int i;
	int size = sizeof(data_type);
	data_type* ptr = (data_type*)malloc(size);

	fp = open(filename, READ_BIN_FILE);


	c = (char*)ptr;
	while ((i = getc(fp)) != EOF)
	{
		*c = i;
		c++;
	}

	close(fp);
	data_type tmp = *ptr;
	free(ptr);
	return tmp;
}



void l1task1()
{
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
}
void l1task2()
{
	auto file1 = open("file21.txt", READ_FILE);
	file_data* data = read(file1);
	for (int i = 0; i < data->size; i++)
	{
		char tmp[3] = {data->strings[i][0], data->strings[i][1], '\0'};
		cout << tmp * data_color << mcl::nsep;
	}
	cout << mcl::endl;
	close(file1);
	delete data;

}
void l1task3()
{
	auto file1 = open("file31.txt", READ_FILE);
	auto file2 = open("file32.txt", WRITE_FILE);
	file_data* data = read(file1);
	file_data* data_2 = new file_data(FILE_LEN, BUFF_LEN+1);
	for (int i = 0; i < data->size; i++)
	{
		int k = 0;
		for (int j = 0; j < data_2->lens; j++)
		{
			if (data->strings[i][data->lens - j ] > '\0')
			{
				data_2->strings[i][k] = data->strings[i][data->lens - j ];
				k++;
			}

		}
	}
	for (int i = 0; i < data->size; i++)
	{
		cout << data->strings[i] * data_color << mcl::tab;
		cout << data_2->strings[i] * data_color << mcl::endl;
	}

	write(file2, data_2);
	close(file1);
	close(file2);
	delete data;
	delete data_2;
}
void l1task4()
{

	{
		srand(time(0));
		data nums;
		for (int i = 0; i < 18; i++)
			nums.num[i] = rand() % 1000 - 500;
		save("file41.test", &nums);
	}

	data input = load<data>("file41.test");
	int nums1[18] = { 0 };
	int nums2[18] = { 0 };
	int i1 = 0, i2 = 0;
	for (int i = 0; i < 18; i++)
	{
		if (input.num[i] % 2 == 0)
		{
			nums1[i1] = input.num[i];
			i1++;
		}
		else
		{
			nums2[i2] = input.num[i];
			i2++;
		}
	}

	for (int i = 0; i < 18; i++)
	{
		cout << nums1[i] << "|" << nums2[i] << mcl::endl;
	}
	cout << mcl::endl;
}
void l1task5()
{
	
	data_str nums;
	save<data_str>("file51.test", &nums);
	data_str input = load<data_str>("file51.test");

	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (input.str[i][0] == 'ì')
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

