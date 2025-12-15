#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}Stack;

void STInit(Stack* pst);
void STDestroy(Stack* pst);

void STPush(Stack* pst, STDataType x);
void STPop(Stack* pst);

bool STEmpty(Stack* pst);
void STPrint(Stack* pst);

STDataType STTop(Stack* pst);
int STSize(Stack* pst);