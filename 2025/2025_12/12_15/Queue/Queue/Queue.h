#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	size_t size;
}Queue;

void QInit(Queue* pq);
void QDestroy(Queue* pq);

void QPush(Queue* pq, QDataType x);
void QPop(Queue* pq);

bool QEmpty(Queue* pq);
size_t QSize(Queue* pq);

QDataType QFront(Queue* pq);
QDataType QBack(Queue* pq);