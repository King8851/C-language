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

void STInit(Stack* pst)
{
	assert(pst);
	pst->arr = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
void STDestroy(Stack* pst)
{
	assert(pst);
	free(pst->arr);
	pst->arr = NULL;
	pst->top = 0;
	pst->capacity = 0;
}
void STPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int NewCapacity = pst->capacity ? 2 * pst->capacity : 1;
		STDataType* tmp = (STDataType*)realloc(pst->arr, NewCapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->arr = tmp;
		pst->capacity = NewCapacity;
	}
	pst->arr[pst->top] = x;
	pst->top++;
}
void STPop(Stack* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}
bool STEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0;
}
void STPrint(Stack* pst)
{
	assert(pst);
	for (int i = 0; i < pst->top; i++)
	{
		printf("%d -> ", pst->arr[i]);
	}
	printf("\n");
}
STDataType STTop(Stack* pst)
{
	assert(pst);
	assert(pst->top);
	return pst->arr[pst->top - 1];
}
int STSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}

typedef struct 
{
	Stack* st;
	Stack* sthelp;
} MyQueue;


MyQueue* myQueueCreate() 
{
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
	pq->st = (Stack*)malloc(sizeof(Stack));
	pq->sthelp = (Stack*)malloc(sizeof(Stack));
	STInit(pq->st);
	STInit(pq->sthelp);
	return pq;
}

void myQueuePush(MyQueue* obj, int x) 
{
	assert(obj);
	STPush(obj->st, x);
}

int myQueuePop(MyQueue* obj) 
{
	assert(obj);
	int count = STSize(obj->st) - 1;
	int i = 0;
	for (i = 0; i < count; i++)
	{
		STPush(obj->sthelp, STTop(obj->st));
		STPop(obj->st);
	}
	int ret = STTop(obj->st);
	STPop(obj->st);
	for (i = 0; i < count; i++)
	{
		STPush(obj->st, STTop(obj->sthelp));
		STPop(obj->sthelp);
	}
	return ret;
}

int myQueuePeek(MyQueue* obj) 
{
	assert(obj);
	int count = STSize(obj->st) - 1;
	int i = 0;
	for (i = 0; i < count; i++)
	{
		STPush(obj->sthelp, STTop(obj->st));
		STPop(obj->st);
	}
	int ret = STTop(obj->st);
	for (i = 0; i < count; i++)
	{
		STPush(obj->st, STTop(obj->sthelp));
		STPop(obj->sthelp);
	}
	return ret;
}

bool myQueueEmpty(MyQueue* obj) 
{
	assert(obj);
	return STEmpty(obj->st);
}

void myQueueFree(MyQueue* obj) 
{
	assert(obj);
	STDestroy(obj->st);
	STDestroy(obj->sthelp);
	free(obj->st);
	free(obj->sthelp);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/