#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
 * 如果是二叉查找树
 */
TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == NULL)
        return NULL;
    if(p == NULL || q == NULL)
        return NULL;

    if(p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if(p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    else
    {
        return root;
    }
}


/*
 * 如果不是二叉查找树，并且没有指向父节点的指针
 */
TreeNode * lowestCommonAncestor_2(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(root == NULL || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor_2(root->left, p, q); //向左边找最低公共祖先
    TreeNode *right = lowestCommonAncestor_2(root->right, p, q);//向右边找最低公共祖先

    //如果左边没找到，就返回右边
    //如果左边找到， 右边没找到，返回左边
    //              右边找到，返回root
    return left == NULL ? right : (right == NULL ? left : root);

}