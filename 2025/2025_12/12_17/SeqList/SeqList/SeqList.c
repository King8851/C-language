#include "SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);
	psl->arr = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

void SLDestroy(SL* psl)
{
	assert(psl);
	free(psl->arr);
	free(psl);
}

void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);
	if (psl->size == psl->capacity)
	{
		size_t NewCapacity = psl->capacity ? 2 * psl->capacity : 1;
		SLDataType* tmp = (SLDataType*)malloc(NewCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		psl->arr = tmp;
		psl->capacity = NewCapacity;
	}
	int i = psl->size - 1;
	for (; i > 0; i--)
	{
		psl->arr[i] = psl->arr[i - 1];
	}
	psl->arr[0] = x;
	psl->size++;
}

void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);
	if (psl->size = psl->capacity)
	{
		size_t NewCapacity = psl->capacity ? 2 * psl->capacity : 1;
		SLDataType* tmp = (SLDataType*)malloc(sizeof(NewCapacity * sizeof(SLDataType)));
		if (tmp == NULL)
		{
			perror("malloc fail");
			return;
		}
		psl->arr = tmp;
		psl->capacity = NewCapacity;
	}
	psl->arr[psl->size] = x;
	psl->size++;
}

bool SLPopFront(SL* psl)
{
	assert(psl);
	if (SLEmpty == true)	return false;
	int i = 1;
	for (i = 1; i < psl->size; i++)
	{
		psl->arr[i - 1] = psl->arr[i];
	}
	psl->size--;
	return true;
}

void SLPopBack(SL* psl)
{
	assert(psl);
	if (SLEmpty == true)	return false;
	psl->size--;
	return true;
}

SLDataType SLFront(SL* psl)
{
	assert(psl);
	assert(psl->size);
	return psl->arr[0];
}

SLDataType SLBack(SL* psl)
{
	assert(psl);
	assert(psl->size);
	return psl->arr[psl->size - 1];
}

bool SLEmpty(SL* psl)
{
	assert(psl);
	return psl->size == 0;
}

size_t SLSize(SL* psl)
{
	assert(psl);
	return psl->size;
}

void SLPrint(SL* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d -> ", psl->arr[i]);
	}
	printf("\n");
}