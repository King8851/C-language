#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType val;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->val = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}
BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}
void TreeLevelOrder(BTNode* root)
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	QInit(q);
	if(root)	QPush(q, root);
	while (!QEmpty(q))
	{
		BTNode* front = QFront(q);
		QPop(q);
		if (front->left)	QPush(q, front->left);
		if (front->right)	QPush(q, front->right);
		printf("%d", front->val);
	}
	QDestroy(q);
}
void OrderTest(BTNode* root)
{
	printf(" PreOrder: ");
	PreOrder(root);
	printf("\n");

	printf("  InOrder: ");
	InOrder(root);
	printf("\n");

	printf("PostOrder: ");
	PostOrder(root);
	printf("\n");

	printf("TreeLevelOrder: ");
	TreeLevelOrder(root);
	printf("\n");
}

int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		int left = TreeHeight(root->left) + 1;
		int right = TreeHeight(root->right) + 1;
		return left > right ? left : right;
	}
}
int LevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	else if (k == 1)
		return 1;
	else
		return LevelSize(root->left, k - 1) + LevelSize(root->right, k - 1);
}
void TreeTest(BTNode* root)
{
	printf("节点数: %d\n", TreeSize(root));
	printf("叶子数: %d\n", TreeLeafSize(root));
	printf("树高度: %d\n", TreeHeight(root));
	printf("第一层: %d\n", LevelSize(root, 1));
	printf("第二层: %d\n", LevelSize(root, 2));
	printf("第三层: %d\n", LevelSize(root, 3));
	printf("第四层: %d\n", LevelSize(root, 4));
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;
	if (root->val != x)
	{
		BTNode* left = BinaryTreeFind(root->left, x);
		if (left)	return left;
		BTNode* right = BinaryTreeFind(root->right, x);
		if (right)	return right;
		return NULL;
	}
}
void FindTest(BTNode* root)
{
	for (int i = 0; i < 8; i++)
	{
		BTNode* ret = BinaryTreeFind(root, i);
		if (ret)
			printf("%d: %d\n", i, ret->val);
		else
			printf("%d: NULL\n", i);
	}
}

int main()
{
	BTNode* root = CreatBinaryTree();
	OrderTest(root);
	//TreeTest(root);
	//FindTest(root);

	return 0;
}