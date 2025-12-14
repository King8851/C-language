//未完成，仍有少量错误

//https://leetcode.cn/problems/implement-stack-using-queues/
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，
//并支持普通栈的全部四种操作（push、top、pop 和 empty）。

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

//数据类型
typedef int QDataType;

//队列节点
typedef struct QueneNode
{
	QDataType val;
	struct QueneNode* next;
}QNode;

//队列信息
typedef struct Quene
{
	QNode* phead;
	QNode* ptail;
	size_t size;
}Quene;

//函数声明
void QueneInit(Quene* pq);
void QueneDestroy(Quene* pq);
void QuenePush(Quene* pq, QDataType x);
void QuenePop(Quene* pq);
QDataType QueneFront(Quene* pq);
QDataType QueneBack(Quene* pq);
size_t QueneSize(Quene* pq);
bool QueneEmpty(Quene* pq);

//函数实现
void QueneInit(Quene* pq)
{
	assert(pq);
	pq->phead = NULL;
	pq->ptail = NULL;
	pq->size = 0;
}
void QueneDestroy(Quene* pq)
{
	assert(pq);
	QNode* curr = pq->phead;
	while (curr)
	{
		QNode* del = curr;
		curr = curr->next;
		free(del);
	}
	pq->size = 0;
	pq->phead = NULL;
	pq->ptail = NULL;
}
QNode* QueneBuyNode(QDataType x)
{
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if (NewNode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	NewNode->val = x;
	NewNode->next = NULL;
	return NewNode;
}
void QuenePush(Quene* pq, QDataType x)
{
	assert(pq);
	QNode* NewNode = QueneBuyNode(x);
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = NewNode;
	}
	else
	{
		pq->ptail->next = NewNode;
		pq->ptail = NewNode;
	}
	pq->size++;
}
void QuenePop(Quene* pq)
{
	assert(pq);
	if (pq->size == 1)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	if (pq->size)
	{
		QNode* del = pq->phead;
		pq->phead = pq->phead->next;
		free(del);
		pq->size--;
	}
}
bool QueneEmpty(Quene* pq)
{
	assert(pq);
	return !(pq->size);
}
size_t QueneSize(Quene* pq)
{
	assert(pq);
	return pq->size;
}
QDataType QueneFront(Quene* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
QDataType QueneBack(Quene* pq)
{

	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

//MyStack实现
typedef struct 
{
	Quene q;
	Quene qhelp;
} MyStack;


MyStack* myStackCreate() 
{
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
	QueneInit(&(pst->q));
	QueneInit(&(pst->qhelp));
	return pst;
}

void myStackPush(MyStack* pst, int x) 
{
	QuenePush(&(pst->q), x);
}

int myStackPop(MyStack* pst) 
{
	assert(pst);
	size_t count = (pst->q).size;
	while (--count)
	{
		QuenePush(&(pst->qhelp), QueneFront(&(pst->q)));
		QuenePop(&(pst->q));
	}
	int ret = QueneFront(&pst->q);
	QuenePop(&(pst->q));
	Quene tmp = pst->q;
	pst->q = pst->qhelp;
	pst->qhelp = tmp;
	return ret;
}

int myStackTop(MyStack* pst) 
{
	assert(pst);
	return QueneBack(&(pst->q));
}

bool myStackEmpty(MyStack* pst) 
{
	assert(pst);
	return !QueneSize(&(pst->q));
}

void myStackFree(MyStack* pst)
{
	QueneDestroy(&(pst->q));
	QueneDestroy(&(pst->qhelp));
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