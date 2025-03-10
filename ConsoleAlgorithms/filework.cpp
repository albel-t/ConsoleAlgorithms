

#include"filework.h"

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
	}
	else {
		if (feof(file))
		{
			cout << "End of file." * error_color << mcl::endl;
		}
		else {
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
		delete[] strings[i];
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
			cout << "An error occurred while writing to the file." * error_color << mcl::endl;
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
