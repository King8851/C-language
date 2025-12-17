#define _CRT_SECURE_NO_WARNINGS


#define N 4 //给定度
struct TreeNode_1
{
	int val;

	struct TreeNode_1* subs[N];
};


struct TreeNode_2 //没有明确度
{
	int val;

	//C: SeqList subs; //顺序表内部存struct TreeNode_2*
	//C++: vector<struct TreeNode_2*> subs;
};

struct TreeNode //更好的表示方法
{
	int val;

	struct TreeNode* leftChild;
	struct TreeNode* rightBrother;
};

struct TreeNode //二叉树
{
	int val;

	struct TreeNode* left;
	struct TreeNode* right;
};


int main()
{

	return 0;
}

