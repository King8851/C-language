//https://leetcode.cn/problems/symmetric-tree/
//给你一个二叉树的根节点 root, 检查它是否轴对称。
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isMirrorTree(struct TreeNode* p, struct TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p && q && p->val == q->val)
        return isMirrorTree(p->left, q->right) && isMirrorTree(p->right, q->left);
    else
        return false;
}

bool isSymmetric(struct TreeNode* root) 
{
    if (root == NULL)
        return true;
    else
        return isMirrorTree(root->left, root->right);
}