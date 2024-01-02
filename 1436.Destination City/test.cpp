#include "answer_count.cpp"
#include <memory>
#include <cassert>

int main()
{
    auto solution = make_unique<Solution>();
    auto case1 = vector<vector<string>>{{"A", "B"}, {"B", "C"}, {"C", "D"}};
    auto result = std::move(solution->destCity(case1));
    auto expect = string("D");
    auto r = result == expect;
    assert(r);
    return 0;
}