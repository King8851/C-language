#include "Heap.h"

void Heap_Test()
{
	//初始化堆
	HP hp;
	HPInit(&hp);

	//数组载入堆中
	int a[] = { 1,4,2,5,6,23,56,77,97,86,33,24,55,17,11 };
	size_t sz = sizeof(a) / sizeof(a[0]);
	ArrPrint(a, sz);

	for (size_t i = 0; i < sz; i++)	HPPush(&hp, a[i]);

	//Topk方法1: 空间复杂度O(N), 数据量大时可能难以承受
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

void HeapSort_0(HPDataType* a, size_t sz, HeapType type) //不够好: 空间复杂度O(N)较大
{
	assert(a);
	HP hp;
	HPInit(&hp);
	hp.type = type;
	for (size_t i = 0; i < sz; i++)	HPPush(&hp, a[i]);
	int j = 0;
	while (HPEmpty(&hp) != true)
	{
		a[j++] = HPTop(&hp);
		HPPop(&hp);
	}
}

//堆排序 O(N*logN)
void HeapSort_1(HPDataType* a, size_t sz, HeapType type) //MIN顺序  MAX逆序
{
	assert(a);
	for (int i = 1; i < sz; i++)
	{
		AdjustUp(a, i, -type); //时间复杂度O(N*logN)
	}

	int end = sz - 1;
	while(end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end--, 0, -type);
	}
}

void HeapSort_2(HPDataType* a, size_t sz, HeapType type) //MIN顺序  MAX逆序
{
	assert(a);
	for (int i = sz / 2 - 1; i >= 0; i--)
	{
		AdjustDown(a, sz, i, -type); //时间复杂度O(N)
	}

	int end = sz - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end--, 0, -type);
	}
}

void HeapSort_Test()
{
	//测试用例
	int a[] = { 23,4,2,5,6,1,56,77,97,86,33,24,55,17,11 };
	size_t sz = sizeof(a) / sizeof(a[0]);
	ArrPrint(a, sz);

	//HeapSort_0(a, sz, MIN);
	//HeapSort_0(a, sz, MAX);
	
	//HeapSort_1(a, sz, MIN);
	//HeapSort_1(a, sz, MAX);

	//HeapSort_2(a, sz, MIN);
	HeapSort_2(a, sz, MAX);

	ArrPrint(a, sz);
}

int main()
{
	//Heap_Test();
	//Bad_HeapSort();
	HeapSort_Test();

	return 0;
}