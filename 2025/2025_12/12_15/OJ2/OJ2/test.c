//https://leetcode.cn/problems/implement-stack-using-queues/
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，
//并支持普通栈的全部四种操作（push、top、pop 和 empty）。

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

//函数实现
void QInit(Queue* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
	}
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QPush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;
	if (pq->phead == NULL)
	{
		pq->phead = newnode;
		pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
void QPop(Queue* pq)
{
	assert(pq);
	assert(pq->size);
	if (pq->phead->next == NULL)
	{
		free(pq->phead);
		pq->phead = NULL;
		pq->ptail = NULL;
	}
	else
	{
		QNode* del = pq->phead;
		pq->phead = pq->phead->next;
		free(del);
	}
	pq->size--;
}
bool QEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}
size_t QSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
QDataType QFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
QDataType QBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

//MyStack实现
typedef struct 
{
	Queue* q;
	Queue* qhelp;
} MyStack;


MyStack* myStackCreate() 
{
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	pst->q = (Queue*)malloc(sizeof(Queue));
	pst->qhelp = (Queue*)malloc(sizeof(Queue));
	QInit(pst->q);
	QInit(pst->qhelp);
	return pst;
}

void myStackPush(MyStack* pst, int x) 
{
	assert(pst);
	QPush(pst->q, x);
}

int myStackPop(MyStack* pst) 
{
	assert(pst);
	assert(pst->q->size);
	size_t count = pst->q->size - 1;
	while (count--)
	{
		QPush(pst->qhelp, QFront(pst->q));
		QPop(pst->q);
	}
	int val = QFront(pst->q);
	QPop(pst->q);

	//swap
	Queue* tmp = pst->q;
	pst->q = pst->qhelp;
	pst->qhelp = tmp;
	return val;
}

int myStackTop(MyStack* pst)
{
	assert(pst);
	return QBack(pst->q);
}

bool myStackEmpty(MyStack* pst) 
{
	assert(pst);
	return QEmpty(pst->q);
}

void myStackFree(MyStack* pst)
{
	assert(pst);
	QDestroy(pst->q);
	QDestroy(pst->qhelp);
	free(pst->q);
	free(pst->qhelp);
	free(pst);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/