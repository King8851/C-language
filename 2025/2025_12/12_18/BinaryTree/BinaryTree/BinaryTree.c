#include "BinaryTree.h"

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (a[parent] > a[child])
		{
			//Value Swap
			HPDataType tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			//Positon Up
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);
	
	//尾插
	if (php->size = php->capacity)
	{
		int NewCapacity = php->capacity ? 2 * php->capacity : 4;
		HPDataType* tmp = (HPDataType*)realloc(php->a, NewCapacity * sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity = NewCapacity;
	}
	php->a[php->size] = x;

	//向上调整
	AdjustUp(php->a, php->size);

	php->size++;
}

void HPPop(HP* php);

void HPPrint(HP* php)
{
	assert(php);
	assert(php->a);
	int i;
	for (int i = 0; i < php->size; i++)
	{

	}
}