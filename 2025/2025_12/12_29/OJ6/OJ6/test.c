//https://leetcode.cn/problems/subtree-of-another-tree/
//给你两棵二叉树 root 和 subRoot 。
//检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。
//如果存在, 返回 true ; 否则, 返回 false 。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p && q && p->val == q->val)
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	else
		return false;
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (root == NULL)
		return false;
	if (root->val == subRoot->val && isSameTree(root, subRoot))
		return true;
	else
		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}