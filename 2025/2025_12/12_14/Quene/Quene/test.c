#include "Quene.h"

//#define __DEBUG__

#ifdef __DEBUG__
#define PUSH(x) QuenePush(&q, x);
#define POP QuenePop(&q);
#define PRINT QuenePrint(&q);
#define SIZE printf("size = %zu\n", QueneSize(&q))
#endif

int main()
{
	Quene q;
	QueneInit(&q);
	QuenePush(&q, 1);
	QuenePush(&q, 2);
	QuenePush(&q, 3);
	QuenePush(&q, 4);

	while (QueneEmpty(&q))
	{
		printf("%d -> ", QueneFront(&q));
		QuenePop(&q);
	}
	printf("\n");

	QueneDestroy(&q);

	return 0;
}