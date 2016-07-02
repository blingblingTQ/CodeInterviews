#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/***********************************************************************/
/*                              前序遍历                                */
/***********************************************************************/
/* 1. 前序遍历 递归 */
void preorder_traversal_recursively(TreeNode *root)
{
    if(root == NULL)
        return;
    /* 先访问根节点 */
    cout << root->val << endl;
    /* 再访问左右子节点 */
    preorder_traversal_recursively(root->left);
    preorder_traversal_recursively(root->right);
}

/* 2. 前序遍历 迭代 */
void preorder_traversal_iteratively(TreeNode *root)
{
    if(root == NULL)
        return;

    stack<TreeNode *> nodes;
    TreeNode *p = root;

    /* 边遍历边打印，把左孩子入栈 */
    while(p || !nodes.empty())
    {
        while(p)
        {
            /* 先序，所以第一次访问到就打印 */
            cout << p->val << endl;
            nodes.push(p);
            p = p->left;
        }
        if(!nodes.empty())
        {
            p = nodes.top();
            nodes.pop();
            p = p->right;
        }
    }
}


/***********************************************************************/
/*                              中序遍历                                */
/***********************************************************************/
/* 3. 中序遍历 递归 */
void inorder_traversal_recursively(TreeNode *root)
{
    if(root == NULL)
        return;

    /* 先访问左孩子 */
    inorder_traversal_recursively(root->left);
    /* 再访问根节点 */
    cout << root->val << endl;
    /* 最后访问右孩子 */
    inorder_traversal_recursively(root->right);
}

/* 4. 中序遍历 迭代 */
void inorder_traversal_iteratively(TreeNode *root)
{
    if(root == NULL)
        return;

    stack<TreeNode *> nodes;
    TreeNode *p = root;

    /* 边遍历边打印，把左孩子入栈 */
    while(p || !nodes.empty())
    {
        while(p)
        {
            nodes.push(p);
            p = p->left;
        }
        if(!nodes.empty())
        {
            p = nodes.top();
            nodes.pop();
            /* 中序，左边都打印完了再打印根节点，再把右孩子入栈 */
            cout << p->val << endl;
            p = p->right;
        }
    }
}


/***********************************************************************/
/*                              后序遍历                                */
/***********************************************************************/
/* 5. 后序遍历 递归 */
void postorder_traversal_recursively(TreeNode *root)
{
    if(root == NULL)
        return;

    /* 先访问左孩子 */
    postorder_traversal_recursively(root->left);
    /* 再问右孩子 */
    postorder_traversal_recursively(root->right);
    /* 最后访问根节点 */
    cout << root->val << endl;
}

/* 6. 后序遍历 迭代 */
void postorder_traversal_iteratively(TreeNode *root)
{
    if(root == NULL)
        return;

    stack<TreeNode *> nodes;
    TreeNode *p = root;
    TreeNode *last_vistied = NULL;
    
    while(p || !nodes.empty())
    {
        while(p)
        {
            nodes.push(p);
            p = p->left;
        }
        
        p = nodes.top();
        if(p->right == NULL || p->right == last_vistied)
        {
            cout << p->val << endl;
            last_vistied = p;
            nodes.pop();
            p = NULL;
        }
        else
        {
            p = p->right;
        }
    }
}

