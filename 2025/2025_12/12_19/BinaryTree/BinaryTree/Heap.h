#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

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
void AdjustDown(HPDataType* a, int n, int parent);

void HPPush(HP* php, HPDataType x);
void HPPop(HP* php);

bool HPEmpty(HP* php);
HPDataType HPTop(HP* php);

void HPPrint(HP* php);