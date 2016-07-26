#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int check_and_get_height(TreeNode *root)
{
    if(root == NULL)
    {
        return 0; //高度为0
    }

    int left_height = check_and_get_height(root->left);
    if(left_height == -1)
    {
        //不平衡
        return -1;
    }

    int right_height = check_and_get_height(root->right);
    if(right_height == -1)
    {
        //不平衡
        return -1;
    }

    int height_diff = right_height - left_height;
    if(height_diff > 1 || height_diff < -1)
    {
        return -1;//不平衡
    }
    else
    {
        return max(left_height, right_height) + 1;
    }
}

bool is_balanced(TreeNode *root)
{
    if(check_and_get_height(root) == -1)
    {
        return false;
    }
    return true;
}
