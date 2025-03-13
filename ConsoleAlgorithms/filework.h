#pragma once

#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "MultiColorLine.h"
#include "laba_1.h"
#include "laba_2.h"


#define READ_FILE "r"
#define WRITE_FILE "w"
#define READ_BIN_FILE "rb"
#define WRITE_BIN_FILE "wb"

#define BUFF_LEN 64
#define FILE_LEN 16



typedef unsigned int buff_size;
typedef unsigned int file_size;

//template struct column<int>;
//template struct data<int>;
//template struct data_str<int>;

FILE* open(const char* nameFile, const char* arg);

void close(FILE* file);

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

/*
template<typename data_type>
void save(const char* filename, data_type* p);

template<typename data_type>
data_type load(const char* filename);
*/

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