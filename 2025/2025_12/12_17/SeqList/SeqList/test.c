#include "SeqList.h"

//error

void test()
{
	SL* psl = (SL*)malloc(sizeof(SL));
	SLInit(psl);
	SLPushFront(psl, 2);
	SLPushFront(psl, 1);
	SLPushBack(psl, 3);
	SLPushBack(psl, 4);
	SLPrint(psl);

	SLPopBack(psl);
	SLPopFront(psl);

	printf("Front = %d\n", SLFront(psl));
	printf("Back = %d\n", SLBack(psl));

	SLDestroy(psl);
}

int main()
{
	test();
	return 0;
}