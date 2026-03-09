#include "Sort.h"

void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int) * N);
	int* a2 = (int*)malloc(sizeof(int) * N);
	int* a3 = (int*)malloc(sizeof(int) * N);
	int* a4 = (int*)malloc(sizeof(int) * N);
	int* a5 = (int*)malloc(sizeof(int) * N);
	int* a6 = (int*)malloc(sizeof(int) * N);
	int* a7 = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
	}

	int begin1 = clock();//²åÈëÅÅÐò
	//InsertSort(a1, N);
	int end1 = clock();
	
	int begin2 = clock();//Ï£¶ûÅÅÐò
	ShellSort(a2, N);
	int end2 = clock();
	
	int begin3 = clock();//Ñ¡ÔñÅÅÐò
	SelectSort(a3, N);
	int end3 = clock();
	
	int begin4 = clock();//¶ÑÅÅÐò
	HeapSort(a4, N);
	int end4 = clock();
	
	int begin5 = clock();//¿ìËÙÅÅÐò
	//QuickSort(a5, 0, N-1);
	int end5 = clock();
	
	int begin6 = clock();//¹é²¢ÅÅÐò
	//MergeSort(a6, N);
	int end6 = clock();
	
	int begin7 = clock();//Ã°ÅÝÅÅÐò
	//BubbleSort(a7, N);
	int end7 = clock();

	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	printf("BubbleSort:%d\n", end7 - begin7);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
}

void SortTest()
{
	int a[10] = { 9,7,8,2,3,2,5,6,3,1 };
	//InsertSort(a, 10);
	//ShellSort(a, 10);
	//SelectSort(a, 10);
	//HeapSort(a, 10);
	//QuickSort(a, 0, 9);
	//MergeSort(a, 10);
	//BubbleSort(a, 10);
	
	for (int i = 0; i < 10; i++)	printf("%d ", a[i]);
}

int main()
{
	TestOP();
	//SortTest();
	return 0;
}