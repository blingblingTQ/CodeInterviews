#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        if(root == NULL)
            return node;
        if(node == NULL)
            return root;
        if(root->val > node->val)
        {
            if(root->left == NULL)
                root->left = node;
            else
                root->left = insertNode(root->left, node);
        }
        else
        {
            if(root->right == NULL)
                root->right = node;
            else
                root->right = insertNode(root->right, node);
        }
        return root;
    }
};