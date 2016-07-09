#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 得到二叉树的镜像
 * 遍历到每个节点非叶子节点，交换左右两个子节点
 */
void get_mirror(TreeNode *root)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
        return;
    
    //交换左右子节点
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if(root->left != NULL)
    {
        get_mirror(root->left);
    }
    if(root->right != NULL)
    {
        get_mirror(root->right);
    }
}


/*
 * 判断两个二叉树是否是镜像关系
 */
bool is_mirror(TreeNode *root1, TreeNode *root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    
    if(root1->val != root2->val)
        return false;
    return is_mirror(root1->left, root2->right) &&
        is_mirror(root1->right, root2->left);
}

/*
 * 判断二叉树是否是中心对称
 */
bool is_symmetric(TreeNode *root)
{
    if(root == NULL)
        return true;
    return is_mirror(root->left, root->right);
}