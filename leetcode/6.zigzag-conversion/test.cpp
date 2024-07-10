#include "./answer.cpp"
#include <memory>
#include <cassert>
#include <iostream>

void test_case_1(Solution *solution)
{
    std::vector<int> a = {1, 2};
    std::vector<int> b = {3, 4, 5};
    std::cout << solution->convert("abc", 1) << std::endl;
    std::cout << solution->convert("PAYPALISHIRING", 3) << std::endl;

    assert(solution->convert("abc", 1) == "abc");
}

int main()
{
    auto solution = make_unique<Solution>();
    test_case_1(solution.get());
    return 0;
}