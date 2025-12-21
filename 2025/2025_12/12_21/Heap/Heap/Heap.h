#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define HPTYPE MIN

typedef int HPDataType;

typedef enum HeapType
{
	MIN = 1,
	MAX = -1
}HeapType;

typedef struct Heap
{
	HeapType type;
	HPDataType* a;
	int size;
	int capacity;
}HP;

void HPInit(HP* php); //堆初始化
void HPDestroy(HP* php); //堆销毁

void Swap(HPDataType* x, HPDataType* y);//交换
void AdjustUp(HPDataType* a, int child, HeapType type); //向上调整
void AdjustDown(HPDataType* a, int n, int parent, HeapType type); //向下调整

void HPPush(HP* php, HPDataType x);//堆中插入元素
void HPPop(HP* php);//删除堆顶元素

bool HPEmpty(HP* php);//堆判空
HPDataType HPTop(HP* php);//获取堆顶元素

void HPPrint(HP* php);//堆打印
void ArrPrint(HPDataType* a, int sz);//数组打印
