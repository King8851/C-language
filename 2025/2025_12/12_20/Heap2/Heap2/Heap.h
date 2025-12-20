#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);

void Swap(HPDataType* x, HPDataType* y);

void AdjustUp(HPDataType* a, int child);
void AdjustDown(HPDataType* a, size_t size, int parent);

void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);

HPDataType HPTop(HP* php);
bool HPEmpty(HP* php);

void ArrPrint(HPDataType* a, size_t size);
void HPPrint(HP* php);