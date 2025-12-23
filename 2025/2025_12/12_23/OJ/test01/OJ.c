//https://leetcode.cn/problems/univalued-binary-tree/
//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

bool isUnivalTree(struct TreeNode* root)
{
    //空节点: 
    if (root == NULL)
        return true;
    //判断
    bool judge = true;
    if (root->left && root->left->val != root->val)
        judge = false;
    if (root->right && root->right->val != root->val)
        judge = false;
    //返回
    if (judge == true)
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    else
        return false;
}

int main()
{
	return 0;
}