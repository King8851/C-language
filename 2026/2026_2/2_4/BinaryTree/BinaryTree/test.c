#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	newnode->val = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void LevelOrder(BTNode* root)
{
	if (root == NULL)	return;
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QInit(q);
	QPush(q, root);
	BTNode* front;
	while (!QEmpty(q))
	{
		front = QFront(q);
		if (front->left)	QPush(q, front->left);
		if (front->right)	QPush(q, front->right);
		printf("%d ", QFront(q)->val);
		QPop(q);
	}
	QDestroy(q);
}

void test()
{
	BTNode* n1 = BuyNode(1);
	BTNode* n2 = BuyNode(2);
	BTNode* n3 = BuyNode(4);
	BTNode* n4 = BuyNode(3);
	BTNode* n5 = BuyNode(5);
	BTNode* n6 = BuyNode(6);
	BTNode* n7 = BuyNode(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n3->left = n5;
	n3->right = n6;
	n5->right = n7;

	LevelOrder(n1);
}

int main()
{
	test();
	return 0;
}