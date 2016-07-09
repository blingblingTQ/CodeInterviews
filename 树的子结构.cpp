#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool same(TreeNode *root1, TreeNode *root2)
{
    if(root2 == NULL)
        return true;
    if(root1 == NULL)
        return false;
    if(root1->val != root2->val)
        return false;
    return same(root1->left, root2->left) &&
        same(root1->right, root2->right);
}

bool has_subtree(TreeNode *root1, TreeNode *root2)
{
    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if(same(root1, root2))
    {
        return true;
    }
    return has_subtree(root1->left, root2) || has_subtree(root1->right, root2);
}

