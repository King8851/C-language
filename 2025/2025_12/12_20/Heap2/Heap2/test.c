#include "Heap.h"

void test()
{
	HP hp;
	HPInit(&hp);

	//数组载入堆中
	int a[] = { 1,4,2,5,6,23,56,77,97,86,33,24,55,17,11 };
	size_t size = sizeof(a) / sizeof(a[0]);
	ArrPrint(a, size);

	for (size_t i = 0; i < size; i++)	HPPush(&hp, a[i]);

	//打印Topk
	printf("Topk: ");
	int k = 0;
	scanf("%d", &k);
	while (k-- && HPEmpty(&hp) != true)
	{
		printf("%d ", HPTop(&hp));
		HPPop(&hp);
	}
	printf("\n");
}

void HeapSort(HPDataType* a, size_t size) //实现逆序排列
{
	assert(a);
	int i = 0;
	for (i = size / 2 - 1; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}

	int end = size - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void SortTest()
{
	//int a[] = { 23,4,2,5,6,1,56,77,97,86,33,24,55,17,11 };
	int a[30] = { 0 };
	int i = 0;
	while (scanf("%d", &a[i]) != EOF)	i++;

	ArrPrint(a, i);

	HeapSort(a, i);

	ArrPrint(a, i);
}

int main()
{
	//test();
	SortTest();

	return 0;
}