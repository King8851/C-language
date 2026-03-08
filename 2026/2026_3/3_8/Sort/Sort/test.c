#include "Sort.h"

void TestOP()
{
	srand((unsigned int)time(0));
	const int N = 1000000;
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
	//SelectSort(a3, N);
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

	//TestPrint("InsertSort:", a1);
	TestPrint("ShellSort:", a2);
	//TestPrint("SelectSort:", a3);
	TestPrint("HeapSort:", a4);
	//TestPrint("QuickSort:", a5);
	//TestPrint("MergeSort:", a6);
	//TestPrint("BubbleSort:", a7);
	printf("\n");

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

int main()
{
	TestOP();
	return 0;
}