#include "Heap.h"

void Swap(HPDataType* x, HPDataType* y)
{
	assert(x && y);
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = 0;
	php->capacity = 0;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(HPDataType* a, size_t size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] > a[child + 1])
		{
			child++;
		}
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
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
	AdjustUp(php->a, php->size);
	php->size++;
}

void HPPop(HP* php)
{
	assert(php);
	assert(php->a);
	php->size--;
	Swap(&php->a[0], &php->a[php->size]);
	AdjustDown(php->a, php->size, 0);
}

HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size);
	return php->a[0];
}

bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

void ArrPrint(HPDataType* a, size_t size)
{
	assert(a);
	size_t i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void HPPrint(HP* php)
{
	assert(php);
}