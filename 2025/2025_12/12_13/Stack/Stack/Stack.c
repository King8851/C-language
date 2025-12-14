#include "Stack.h"

void STInit(pStack pst)
{
	assert(pst);
	pst->arr = NULL;
	pst->size = pst->capacity = 0;
}

void STDestroy(pStack pst)
{
	assert(pst);
	free(pst->arr);
	pst->arr = NULL;
	pst->size = pst->capacity = 0;
}

void STPush(pStack pst, STDataType x)
{
	assert(pst);
	if (pst->size == pst->capacity)
	{
		int newCapacity = pst->capacity ? 2 * pst->capacity : 1;
		STDataType* ptr = (STDataType*)realloc(pst->arr, newCapacity * sizeof(Stack));
		if (ptr == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->arr = ptr;
		pst->capacity = newCapacity;
	}
	pst->arr[pst->size ++] = x;
}

void STPop(pStack pst)
{
	assert(pst);
	if (STEmpty(pst))
	{
		system("cls");
		printf("栈为空\n");
		return;
	}
	pst->size--;
	system("cls");
	printf("数据删除成功\n");
}

bool STEmpty(pStack pst)
{
	assert(pst);
	return pst->size == 0;
}

STDataType STTop(pStack pst)
{
	assert(pst);
	if (STEmpty(pst))
	{
		return -1024;
	}
	return pst->arr[pst->size - 1];
}

size_t STSize(pStack pst)
{
	assert(pst);
	return pst->size;
}

void STPrint(pStack pst)
{
	assert(pst);
	for (int i = 0; i < pst->size; i++)
	{
		printf("%d->", pst->arr[i]);
	}
	printf("\n");
}
