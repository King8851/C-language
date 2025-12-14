#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

/*给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
*/

typedef int STDataType;

typedef struct Stack
{
	STDataType* arr;
	int size;
	int capacity;
}Stack, * pStack;








//typedef struct Stack
//{
//	char* str;
//	int top;
//	int capacity;
//}ST;
//
//void STPush(ST* pst, char c)
//{
//	assert(pst);
//	if (pst->top == pst->capacity)
//	{
//		ST* tmp = (ST*)realloc(pst, pst->capacity * 2 * sizeof(ST));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		pst->capacity *= 2;
//	}
//	pst->str[pst->top++] = c;
//}
//
//void STPop(ST* pst)
//{
//	assert(pst);
//	if (pst->top)
//	{
//		pst->top--;
//	}
//}
//
//char STTop(ST* pst)
//{
//	assert(pst);
//	if (pst->top == 0)
//	{
//		return 'F';
//	}
//	return pst->str[pst->top - 1];
//}
//
//bool isValid(char* s)
//{
//	bool valid = true;
//	ST* st = (ST*)malloc(sizeof(ST));
//	st->str = NULL;
//	st->top == 0;
//	st->capacity = 1;
//	while (s++)
//	{
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			STPush(st, *s);
//		}
//		else if (*s == ')')
//		{
//			if (STTop == '(')	STPop(st);
//			else
//			{
//				valid = false;
//				break;
//			}
//		}
//		else if (*s == ']')
//		{
//			if (STTop == '[')	STPop(st);
//			else
//			{
//				valid = false;
//				break;
//			}
//		}
//		else if (*s == '}')
//		{
//			if (STTop == '{')	STPop(st);
//			else
//			{
//				valid = false;
//				break;
//			}
//		}
//	}
//	return valid;
//}