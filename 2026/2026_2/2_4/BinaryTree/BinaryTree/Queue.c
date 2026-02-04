#include "Queue.h"

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