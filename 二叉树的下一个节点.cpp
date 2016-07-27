#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *nextNode(TreeNode *node)
{
    if(node == NULL)
        return NULL;
    
    if(node->right != NULL)
    {
        //返回右子节点的最左子节点
        TreeNode *tmp = node->right;
        while(tmp->left != NULL)
        {
            tmp = tmp->left;
        }
        return tmp;
    }
    else
    {
        TreeNode *tmp = node;
        TreeNode *parent = tmp->parent;
        while(parent != NULL && parent->left != tmp)
        {//如果是父节点的右子节点
            tmp  = parent;
            parent = parent->parent;
        }
        return parent;
    }
}