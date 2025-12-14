#define _CRT_SECURE_NO_WARNINGS 1
//https://leetcode.cn/problems/valid-parentheses/
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//每个右括号都有一个对应的相同类型的左括号。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

typedef char STDatatype;

typedef struct Stack
{
	STDatatype* val;
	int top;
	int capacity;
}ST;

void STInit(ST* pst)
{
	assert(pst);
	pst->val = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->val);
	pst->val = NULL;
	pst->top = 0;
	pst->capacity = 0;
}

void STPush(ST* pst, STDatatype x)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		int newCapacity = pst->capacity ? 2 * pst->capacity : 1;
		STDatatype* tmp = (STDatatype*)realloc(pst->val, newCapacity * sizeof(STDatatype));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		pst->val = tmp;
		pst->capacity = newCapacity;
	}
	pst->val[pst->top++] = x;
}

void STPop(ST* pst)
{
	assert(pst);
	if(pst->top)
	{
		pst->top--;
	}
	return;
}

bool STEmpty(ST* pst)
{
	assert(pst);
	return !(pst->top);
}

STDatatype STTop(ST* pst)
{
	assert(pst);
	if (pst->top)
	{
		return pst->val[pst->top - 1];
	}
	else
	{
		return 'F';
	}
}

bool isValid(char* s)
{
	ST* st = (ST*)malloc(sizeof(ST));
	STInit(st);

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			STPush(st, *s);
		}
		else if (*s == ')')
		{
			if (STTop(st) != '(')
			{
				STDestroy(st);
				return false;
			}
			else
			{
				STPop(st);
			}
		}
		else if (*s == ']')
		{
			if (STTop(st) != '[')
			{
				STDestroy(st);
				return false;
			}
			else
			{
				STPop(st);
			}
		}
		else if (*s == '}')
		{
			if (STTop(st) != '{')
			{
				STDestroy(st);
				return false;
			}
			else
			{
				STPop(st);
			}
		}
		s++;
	}
	bool ret = STEmpty(st);
	STDestroy(st);
	return ret;
}

int main()
{
	char s[100];
	scanf("%s", s);
	printf("%d\n", isValid(s));

	return 0;
}