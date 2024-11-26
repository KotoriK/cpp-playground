#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        auto len = nums.size();
        switch (len)
        {
        case 1:
            return nums[0];
        case 2:
            return max(nums[1], nums[0]);
        default:
            int lastMaxD = nums[0];
            int maxD = max(nums[0], nums[1]);
            for (int i = 2; i < nums.size(); i++)
            {
                lastMaxD = maxD;
                maxD = max(maxD, nums[i] + lastMaxD);
            }
            return max(lastMaxD, maxD);
        }
    }
};
// d[i] = max(d[0, i - 2]) + a[i] 规定有i < 0时, d[i] = 0