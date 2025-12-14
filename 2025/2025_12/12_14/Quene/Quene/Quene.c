#include "Quene.h"

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

void QuenePrint(Quene* pq)
{
	assert(pq);
	QNode* curr = pq->phead;
	while (curr)
	{
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	printf("\n");
}