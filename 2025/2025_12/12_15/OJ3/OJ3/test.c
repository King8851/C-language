//https://leetcode.cn/problems/design-circular-queue/
//设计你的循环队列实现。 
//循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则
//并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。
//在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。
//但是使用循环队列，我们能使用这些空间去存储新的值。
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

typedef struct
{
	int* arr;
	int head;
	int tail;
	int len;
	int size;
} MyCircularQueue, MCQ;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MCQ* cq = (MCQ*)malloc(sizeof(MCQ));
	if (cq == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	cq->arr = (int*)malloc(k * sizeof(int));
	cq->head = 0;
	cq->tail = 0;
	cq->len = k;
	cq->size = 0;
	return cq;
}

bool myCircularQueueEnQueue(MyCircularQueue* cq, int value) //Push
{
	assert(cq);
	if (cq->size == cq->len)
	{
		return false;
	}
	cq->arr[cq->tail] = value;
	if (cq->size == 0)
	{
		cq->head = cq->tail;
	}
	cq->tail = (cq->tail + 1) % (cq->len);
	cq->size++;
	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* cq) //Pop
{
	assert(cq);
	if (cq->size == 0)
	{
		return false;
	}
	cq->head = (cq->head + 1) % (cq->len);
	cq->size--;
	return true;
}

int myCircularQueueFront(MyCircularQueue* cq) 
{
	assert(cq);
	if (cq->size)
		return cq->arr[cq->head];
	else
		return -1;
}

int myCircularQueueRear(MyCircularQueue* cq) 
{
	assert(cq);
	int place = (cq->tail + cq->len - 1) % cq->len;
	if(cq->size)
		return cq->arr[place];
	else
		return -1;
}

bool myCircularQueueIsEmpty(MyCircularQueue* cq)
{
	assert(cq);
	return cq->size == 0;
}

bool myCircularQueueIsFull(MyCircularQueue* cq) 
{
	assert(cq);
	return cq->size == cq->len;
}

void myCircularQueueFree(MyCircularQueue* cq) 
{
	assert(cq);
	free(cq->arr);
	free(cq);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/