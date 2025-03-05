#pragma once

#include <iostream>
#include <cstring>
#include <windows.h>

#define READ_FILE "r"
#define WRITE_FILE "w"

#define BUFF_LEN 64
#define FILE_LEN 16

typedef unsigned int buff_size;
typedef unsigned int file_size;

FILE* open(const char* nameFile, const char* arg);
bool readline(FILE* file, char* buff, buff_size size);

struct file_data {
	char** strings;
	const file_size size;
	const buff_size lens;
	file_data(file_size size, buff_size lens);
	~file_data();
};

file_data* read(FILE* file);
bool write(FILE* file, file_data* data);
