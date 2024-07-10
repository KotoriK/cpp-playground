#include "answer.cpp"
#include <cassert>

int main()
{
    auto solution = make_unique<Solution>();
    TreeNode *case_1 = new TreeNode(2, new TreeNode(3, new TreeNode(8), new TreeNode(13)), new TreeNode(5, new TreeNode(21), new TreeNode(34)));

    TreeNode *case_2 = new TreeNode(1);
    auto result = solution->reverseOddLevels(case_1);
    auto r_2 = solution->reverseOddLevels(case_2);
    return 0;
}