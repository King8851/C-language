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

//Topk_1 时间复杂度O(NlogN) 空间复杂度O(N)
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
void TestTopk_1()
{
	int a[] = { 1,7,2,5,6,23,56,77,97,86,33,24,55,17,11 };
	int size = sizeof(a) / sizeof(a[0]);
	ArrPrint(a, size);
	int k = 0;
	printf("Topk: ");
	scanf("%d", &k);

	Topk_1(a, size, k);
}

//Topk_2 时间复杂度O(NlogN) 空间复杂度O(k), k<<N时空间复杂度O(1)
void CreateNData()
{
	int n = 100000;
	srand((unsigned int)time(NULL));
	const char* file = "data.txt";
	FILE* pf = fopen(file, "w");
	if (pf == NULL)
	{
		perror("fopen fail");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 10000000;
		fprintf(pf, "%d\n", x);
	}

	fclose(pf);
}
void Topk_2(FILE* pf, int size, int k)
{
	k = k > size ? size : k;
	int i = 0;
	int x = 0;

	int* topk = (int*)malloc(k * sizeof(int));
	if (topk == NULL)
	{
		perror("malloc fail");
		return;
	}

	for (i = 0; i < k; i++)
	{
		fscanf(pf, "%d", &topk[i]);
	}

	//建堆
	for (i = k / 2 - 1; i > 0; i--)
	{
		AdjustDown(topk, k, i, MIN);
	}

	//遍历数组
	while(fscanf(pf, "%d", &x) != EOF)
	{
		if (x > topk[0])
		{
			topk[0] = x;
			AdjustDown(topk, k, 0, MIN);
		}
	}
	ArrPrint(topk, k);
	printf("\n");

	free(topk);
}

void TestTopk_2()
{
	int n = 100000;
	const char* file = "data.txt";
	FILE* pf = fopen(file, "r");
	if (pf == NULL)
	{
		perror("fopen error");
		return;
	}
	int k = 0;
	printf("Topk: ");
	scanf("%d", &k);
	Topk_2(pf, 100000, k);

	fclose(pf);
}

int main()
{
	//SortTest();
	//TestTopk_1();
	
	//CreateNData();
	TestTopk_2();

	return 0;
}