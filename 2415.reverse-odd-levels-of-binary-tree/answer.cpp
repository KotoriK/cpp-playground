#include <vector>
#include <memory>
#include "../TreeNode.cpp"
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
private:
    void _reverseNodeVal(vector<TreeNode *> level)
    {
        size_t i = 0, j = level.size() - 1;

        do
        {
            auto temp = level[i]->val;
            level[i]->val = level[j]->val;
            level[j]->val = temp;
        } while (j-- - i++ > 1);
    }

    unique_ptr<vector<TreeNode *>> _listChildLevel(vector<TreeNode *> parentLevel)
    {
        if (parentLevel[0]->left == nullptr)
        {
            return nullptr;
        }
        auto new_level = make_unique<vector<TreeNode *>>();
        new_level->reserve(parentLevel.size() * 2);
        for (auto node : parentLevel)
        {
            new_level->push_back(node->left);
            new_level->push_back(node->right);
        }
        return new_level;
    }
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        bool is_odd = true;
        if (root->left == nullptr)
        {
            return root;
        }
        auto list = {root->left, root->right};
        unique_ptr<vector<TreeNode *>> curr_level = make_unique<vector<TreeNode *>>(list);
        while (curr_level != nullptr)
        {
            auto pointer = *curr_level.get();
            if (is_odd)
            {
                _reverseNodeVal(pointer);
            }
            is_odd = !is_odd;
            auto next_level = _listChildLevel(pointer);
            // curr_level.reset();
            curr_level = move(next_level);
        }
        return root;
    }
};