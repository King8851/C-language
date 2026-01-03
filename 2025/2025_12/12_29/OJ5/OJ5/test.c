//https://leetcode.cn/problems/binary-tree-postorder-traversal/
//给你二叉树的根节点 root, 返回它节点值的后序遍历。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + TreeSize(root->left) + TreeSize(root->right);
}

int* postorder(struct TreeNode* root, int* a)
{
	if (root == NULL)	return a;
	int* left = postorder(root->left, a);
	int* right = postorder(root->right, left);
	*right = root->val;
	return right + 1;
}

void postorder_2(struct TreeNode* root, int* a, int* pos)
{
	if (root == NULL)	return;
	postorder_2(root->left, a, pos);
	postorder_2(root->right, a, pos);
	a[*pos++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = TreeSize(root);
	int* a = (int*)malloc(*returnSize * sizeof(int));
	//postorder(root, a);
	postorder_2(root, a, 0);
	return a;
}