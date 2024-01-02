#include "./answer.cpp"
#include <memory>
#include <cassert>
int main()
{
    auto solution = make_unique<Solution>();
    auto test_case = vector<vector<int>>{
        vector<int>{1, 1, 3, 3},
        vector<int>{3, 1, 4, 2},
        vector<int>{3, 2, 4, 4},
        vector<int>{1, 3, 2, 4},
        vector<int>{2, 3, 3, 4}};

    assert(solution->isRectangleCover(
               (test_case)) == true);

    test_case = vector<vector<int>>{
        vector<int>{0, 0, 1, 1},
        vector<int>{0, 1, 3, 2},
        vector<int>{1, 0, 2, 2},
    };
    return 0;
}