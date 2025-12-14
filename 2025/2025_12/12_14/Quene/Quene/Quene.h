#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef int QDataType;

typedef struct QueneNode
{
	QDataType val;
	struct QueneNode* next;
}QNode;

typedef struct Quene
{
	QNode* phead;
	QNode* ptail;
	size_t size;
}Quene;

void QueneInit(Quene* pq);
void QueneDestroy(Quene* pq);

void QuenePush(Quene* pq, QDataType x);
void QuenePop(Quene* pq);

QDataType QueneFront(Quene* pq);
QDataType QueneBack(Quene* pq);

size_t QueneSize(Quene* pq);
bool QueneEmpty(Quene* pq);

void QuenePrint(Quene* pq);
