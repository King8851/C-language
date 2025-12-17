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



	SLDestroy(psl);
	free(psl);
}

int main()
{
	test();
	return 0;
}