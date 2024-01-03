#include <vector>
#include <limits.h>
constexpr char TEND_EQUAL = 2;
constexpr char TEND_INCREASE = 1;
constexpr char TEND_DECREASE = -1;
class Solution
{
private:
    constexpr char tend(int a, int b)
    {
        if (a == b)
        {
            return TEND_EQUAL;
        }
        else if (a > b)
        {
            return TEND_DECREASE;
        }
        else
        {
            return TEND_INCREASE;
        }
    }

public:
    int findPeakElement(std::vector<int> &nums)
    {
        char last = TEND_INCREASE;
        for (std::size_t i = 1; i < nums.size(); i++)
        {
            auto next = tend(nums[i - 1], nums[i]);
            if (last + next == 0)
            {
                return i - 1;
            }
            else
            {
                last = next;
            }
        }
        if (last == TEND_INCREASE)
        {
            return nums.size() - 1;
        }
        return 0;
    }
};