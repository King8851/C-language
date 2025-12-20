#include "Heap.h"

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

void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			//Value Swap
			Swap(&a[parent], &a[child]);

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
	if (php->size == php->capacity)
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

void AdjustDown(HPDataType* a, int n, int parent)
{
	assert(a);
	parent++;

}

void HPPop(HP* php)
{
	assert(php);
	assert(php->size);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//向下调整
	AdjustDown(php->a, 0);
}

bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[php->size - 1];
}

void HPPrint(HP* php)
{
	assert(php);
	assert(php->a);
	int i;
	for (int i = 0; i < php->size; i++)
	{
		printf("%d -> ", php->a[i]);
	}
	printf("\n");
}