#pragma once

#include <iostream>
#include <cstring>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#define READ_FILE "r"
#define WRITE_FILE "w"
#define READ_BIN_FILE "rb"
#define WRITE_BIN_FILE "wb"

#define BUFF_LEN 64
#define FILE_LEN 16

typedef unsigned int buff_size;
typedef unsigned int file_size;

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
struct data {
	int num[18] = { 0 };
};
struct data_str {
	const char* str[5] = {"мапв", "мвар", "апри", "апис", "апич"};
};
file_data* read(FILE* file);
bool write(FILE* file, file_data* data);

void l1task1();
void l1task2();
void l1task3();
void l1task4();
void l1task5();
void l1task6();

template<typename data_type>
void save(const char* filename, data_type* p);

template<typename data_type>
data_type load(const char* filename);
