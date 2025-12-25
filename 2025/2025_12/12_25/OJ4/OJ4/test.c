//https://leetcode.cn/problems/binary-tree-preorder-traversal/
//给你二叉树的根节点 root, 返回它节点值的前序遍历。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//Wrong Example
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	if (root == NULL)	
		return returnSize;

	*returnSize = root->val;
	int* left = preorderTraversal(root->left, returnSize + 1);
	int* right = preorderTraversal(root->right, left);
	return right;
}