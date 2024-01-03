#include "../TreeNode.cpp"
#include <memory>
using namespace std;

class Solution
{
public:
    // Method to reverse the odd levels of a binary tree using dfs only - O(N) & O(LogN)
    TreeNode *reverseOddLevels(TreeNode *rootNode)
    {
        preOrder(rootNode->left, rootNode->right, true);
        return rootNode;
    }

private:
    // Method helper
    void preOrder(TreeNode *rootLeft, TreeNode *rootRight, bool isOdd)
    {
        // Check one side only because it is a PERFECT tree
        if (rootLeft)
        {
            // When current is the odd level
            if (isOdd)
            {
                // Swap the node values of both the childrens
                swap(rootLeft->val, rootRight->val);
            }
            auto nextIsOdd = !isOdd;
            // Recurse to all the childrens simultaneously in both the subtrees
            preOrder(rootLeft->left, rootRight->right, nextIsOdd);
            preOrder(rootLeft->right, rootRight->left, nextIsOdd);
        }
    }
};