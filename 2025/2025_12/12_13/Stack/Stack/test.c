#include "Stack.h"

void Menu_Stack()
{
	printf("****************   栈   ****************\n");
	printf("*****1.栈顶添加数据  2.栈顶删除数据*****\n");
	printf("*****3.查询栈的长度  4.查询栈顶元素*****\n");
	printf("****************************************\n");
}

int main()
{
	pStack st = (pStack)malloc(sizeof(Stack));
	STInit(st);

	int input = 0;
	int x = 0;
	STDataType top = 0;
	size_t size = 0;
	printf("Stack\n");
	do
	{
		STPrint(st);
		Menu_Stack();
		printf("请选择: ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入插入的数据: ");
			scanf("%d", &x);
			STPush(st, x);
			system("cls");
			printf("数据插入成功\n");
			break;
		case 2:
			STPop(st);
			break;
		case 3:
			size = STSize(st);
			system("cls");
			printf("栈长度为: %zu\n", size);
			break;
		case 4:
			top = STTop(st);
			system("cls");
			if (top + 1024)
				printf("栈顶数据: %d\n", top);
			else
				printf("栈为空\n");
			break;
		case 0:
			break;
		default:
			system("cls");
			printf("行为未定义!\n");
		}
	} while (input);

	return 0;
}