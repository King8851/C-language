#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr;
	size_t size;
	size_t capacity;
}SL;

void SLInit(SL sl);
void SLDestroy(SL sl);

void SLPushFront(SL sl);
void SLPushBack(SL sl);

void SLPopFront(SL sl);
void SLPopBack(SL sl);

SLDataType SLFront(SL sl);
SLDataType SLBack(SL sl);

bool SLEmpty(SL sl);
size_t SLSize(SL sl);
void SLPrint(SL sl);