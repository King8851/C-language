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

void SLInit(SL* psl);
void SLDestroy(SL* psl);

void SLPushFront(SL* psl, SLDataType x);
void SLPushBack(SL* psl, SLDataType x);

void SLPopFront(SL* psl);
void SLPopBack(SL* psl);

SLDataType SLFront(SL* psl);
SLDataType SLBack(SL* psl);

bool SLEmpty(SL* psl);
size_t SLSize(SL* psl);
void SLPrint(SL* psl);