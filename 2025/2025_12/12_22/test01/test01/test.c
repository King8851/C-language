#define _CRT_SECURE_NO_WARNINGS 1

struct A
{
	int a;
	double b;
}a1;

int main()
{
	struct A a1;
	struct A* a2 = (struct a*)malloc(sizeof(struct A));
	a2->a == (*a2).a;
	a1.a;
	return 0;
}