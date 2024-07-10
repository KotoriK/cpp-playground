#include "../TreeNode.cpp"
#include <memory>

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
/* #include "../TreeNode.cpp"
#include <memory>

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        _invert(root->left, root->right);
        return root;
    }

private:
    void _invert(TreeNode *left, TreeNode *right)
    {
        std::swap(left->val, right->val);
        // std::swap(left->right->val, right->left->val);
        if (left->left == nullptr || right->right == nullptr)
            return;
        _invert(left->left, right->right);
        if (left->right == nullptr || right->left == nullptr)
            return;
        _invert(left->right, right->left);
    }
}; */