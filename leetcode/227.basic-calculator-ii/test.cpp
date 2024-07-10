#include "./answer.cpp"
#include <cassert>

int main()
{
    auto solution = new Solution();
/*     assert(solution->calculate("3+2*2") == 3 + 2 * 2);
    assert(solution->calculate("3*2*2") == 12);
    assert(solution->calculate("3*11/11") == 3);
    assert(solution->calculate("2*0") == 0);
    assert(solution->calculate("3/2") == 1);
    assert(solution->calculate("1+1-1") == 1);
    assert(solution->calculate("0-1") == -1);
    assert(solution->calculate("-1-1") == -2);
    assert(solution->calculate("1*2-3/4+5*6-7*8+9/10") == -24); */
    assert(solution->calculate("1+2*5/3+6/4*2") == 6);
    return 0;
}