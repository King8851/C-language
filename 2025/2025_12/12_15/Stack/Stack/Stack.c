#include "Stack.h"

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