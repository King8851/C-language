#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

int main()
{
	int a[10] = { 4,3,6,2,12,8,5,9,1,10 };
	InsertSort(a, 10);
	for (int i = 0; i < 10; i++)	printf("%d ", a[i]);
	return 0;
}