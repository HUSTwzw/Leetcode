#ifndef HEAD_H
#define HEAD_H
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define len 30
struct num_1
{
	int number_1;
	struct num_1* pNext_1;
};
extern int count_1;
struct num_1* line_1(void);


struct num_2
{
	int number_2;
	struct num_2* pNext_2;
};
extern int count_2;
struct num_2* line_2(void);


struct num_fi
{
	int number_fi;
	struct num_fi* pNext_fi;
};
struct num_fi* line_final(int* p);

int* sequence(int* p);

#endif
