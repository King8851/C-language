#include "Queue.h"

void test()
{
	Queue* pq = (Queue*)malloc(sizeof(Queue));
	QInit(pq);
	QPush(pq, 1);
	QPush(pq, 2);
	QPush(pq, 4);
	QPush(pq, 3);
	QPop(pq);
	while (QEmpty(pq) != true)
	{
		printf("%d -> ", QFront(pq));
		QPop(pq);
	}
	printf("\n");
	QDestroy(pq);
	free(pq);
}

int main()
{
	test();
	return 0;
}