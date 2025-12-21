#include "Heap.h"

//堆初始化
void HPInit(HP* php)
{
	assert(php);
	php->type = HPTYPE;
	php->a = NULL;
	php->size = php->capacity = 0;
}

//堆销毁
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}

//交换元素
void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child, HeapType type)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (type * (a[parent] - a[child]) > 0)
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

//堆中插入元素
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
	AdjustUp(php->a, php->size, php->type);

	php->size++;
}

//向下调整
void AdjustDown(HPDataType* a, int size, int parent, HeapType type)
{
	assert(a);

	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && type * (a[child + 1] - a[child]) < 0)
		{
			child++;
		}

		if (type * (a[child] - a[parent]) < 0)
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else 
		{
			break;
		}
	}

}

//删除堆顶元素
void HPPop(HP* php)
{
	assert(php);
	assert(php->size);

	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;

	//向下调整
	AdjustDown(php->a, php->size, 0, php->type);
}

//堆判空
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}

//获取堆顶元素
HPDataType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}

//堆打印
void HPPrint(HP* php)
{
	assert(php);
	assert(php->a);
	int i;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

//数组打印
void ArrPrint(HPDataType* a, int sz)
{
	size_t i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


