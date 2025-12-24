#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void Test_1()
{
	char str[80] = { 0 };
	char substr[80] = { 0 };
	fgets(str, 80, stdin);
	fgets(substr, 80, stdin);
	int len = strlen(substr) - 1;
	char* prev, * curr;
	prev = curr = str;
	while (*curr)
	{
		if (strncmp(curr, substr, len) == 0)
			curr += len;
		else
			*(prev++) = *(curr++);
	}
	*prev = '\0';
	printf("%s\n", str);
}
void Test_2()
{
	char str[80] = { 0 };
	char substr[80] = { 0 };
	fgets(str, 80, stdin);
	fgets(substr, 80, stdin);
	int len = strlen(substr) - 1;
	char* prev, * curr;
	prev = curr = str;
	while (*curr)
	{
		char* str1 = curr;
		char* str2 = substr;
		int cmp = 1;
		for (int i = 0; i < len; i++)
		{
			if (str1[i] != str2[i])
				cmp = 0;
		}
		if (cmp)
		{
			curr += len;
		}
		else
		{
			*prev = *curr;
			prev++;
			curr++;
		}
	}
	*prev = '\0';
	printf("%s\n", str);
}
void Test_3()
{
	char str[80] = { 0 };
	char substr[80] = { 0 };
	fgets(str, 80, stdin);
	fgets(substr, 80, stdin);
	str[strcspn(str, "\n")] = '\0';
	substr[strcspn(substr, "\n")] = '\0';

	char* pos = NULL;
	while (pos = strstr(str, substr))
	{
		memmove(pos, pos + strlen(substr), str + strlen(str) - pos);
	}
	
	printf("%s\n", str);
}

void Test_4()
{
	char str[80] = { 0 };
	char substr[80] = { 0 };
	gets(str, 80, stdin);
	gets(substr, 80, stdin);

	char* pos = NULL;
	while (pos = strstr(str, substr))
	{
		memmove(pos, pos + strlen(substr), str + strlen(str) - pos);
	}

	printf("%s\n", str);
}

int main()
{
	Test_4();

	return 0;
}