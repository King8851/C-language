#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    char str[80], substr[80];
    gets(str);
    gets(substr);
    int i, j, k, num = 0;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = i, k = 0; str[j] == substr[k]; j++, k++)
            if (substr[k + 1] == '\0')
                num++;
    }
    printf("%d\n", num);
    return 0;
}