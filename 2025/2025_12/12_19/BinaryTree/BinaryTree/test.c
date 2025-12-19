#include "BinaryTree.h"

void test()
{
	int a[] = { 1,4,2,5,6,4,2,77,5,4,33,4,5,5,11 };
	HP hp;
	HPInit(&hp);
	size_t sz = sizeof(a) / sizeof(a[0]);
	for (size_t i = 0; i < sz; i++)
	{
		HPPush(&hp, a[i]);
	}
	HPPrint(&hp);
}

int main()
{
	test();
	return 0;
}