#include "Stack.h"

void test()
{
	Stack* pst = (Stack*)malloc(sizeof(Stack));
	if (pst == NULL)
	{
		perror("malloc fail");
		return;
	}
	STInit(pst);
	STPush(pst, 1);
	STPush(pst, 2);
	printf("top = %d\n", STTop(pst));
	STPush(pst, 3);
	STPop(pst);
	STPush(pst, 4);
	STPrint(pst);
	STPop(pst);
	STPop(pst);
	STPop(pst);

	STPrint(pst);
}

int main()
{
	test();
	return 0;
}