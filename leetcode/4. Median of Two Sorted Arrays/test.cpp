#include "./answer.cpp"
#include <memory>
#include <cassert>

void test_case_1(Solution *solution)
{
    std::vector<int> a = {1, 2};
    std::vector<int> b = {3, 4, 5};
    assert(solution->findMedianSortedArrays(a, b) == 3);
}

void test_case_2(Solution *solution)
{
    std::vector<int> a = {1};
    std::vector<int> b = {};
    assert(solution->findMedianSortedArrays(a, b) == 1);
}
void test_case_3(Solution *solution)
{
    std::vector<int> a = {1, 2};
    std::vector<int> b = {3, 4};
    assert(solution->findMedianSortedArrays(a, b) == 2.5);
}

int main()
{
    auto solution = make_unique<Solution>();
    test_case_1(solution.get());
    test_case_2(solution.get());
    test_case_3(solution.get());

    return 0;
}