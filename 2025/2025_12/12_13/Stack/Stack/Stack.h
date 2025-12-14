#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <windows.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int size;
	int capacity;
}Stack, *pStack;

void STInit(pStack pst);
void STDestroy(pStack pst);
void STPush(pStack pst, STDataType x);
void STPop(pStack pst);
bool STEmpty(pStack pst);
STDataType STTop(pStack pst);
size_t STSize(pStack pst);
void STPrint(pStack pst);