#include "Heap.h"

//堆排序 O(N*logN)
void HeapSort(HPDataType* a, int size, HeapType type) //MIN顺序  MAX逆序
{
	assert(a);
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(a, size, i, -type); //时间复杂度O(N)
	}

	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end--, 0, -type);
	}
}
void SortTest()
{
	int a[] = { 23,4,2,5,6,1,56,77,97,86,33,24,55,17,11 };
	int size = sizeof(a) / sizeof(a[0]);
	ArrPrint(a, size);
	HeapSort(a, size, MIN);
	ArrPrint(a, size);
}

void Topk_1(HPDataType* a, int size, int k) //Topk方法1: 空间复杂度 O(N)
{
	HP hp;
	HPInit(&hp);
	int i = 0;
	for (i = 0; i < size; i++)	HPPush(&hp, a[i]);
	for (i = 0; i < k && HPEmpty(&hp) != true; i++)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");
}

void Topk_2(HPDataType* a, int size, int k) //Topk方法2: k远小于N时, 空间复杂度 O(1)
{
	HP hp;
	HPInit(&hp);

	int i = 0;
	for (i = 0; i < k; i++)
	{
		HPPush(&hp, a[i]);
	}
	while (i < size)
	{
		if (HPTop(&hp) < a[i])
		{
			hp.a[0] = a[i];
			AdjustDown(hp.a, k, 0, MIN);
		}
		i++;
	}

	for (i = 0; i < k && HPEmpty(&hp) != true; i++)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");
}

void TopkTest()
{
	int a[] = { 1,4,2,5,6,23,56,77,97,86,33,24,55,17,11 };
	int size = sizeof(a) / sizeof(a[0]);
	ArrPrint(a, size);
	int k = 0;
	printf("Topk: ");
	scanf("%d", &k);

	//Topk_1(a, size, k);
	Topk_2(a, size, k);
}

int main()
{
	//SortTest();
	TopkTest();

	return 0;
}