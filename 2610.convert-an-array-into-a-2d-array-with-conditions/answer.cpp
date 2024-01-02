#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findMatrix(vector<int> &nums)
    {

        // 1 <= nums.length <= 200
        // 1 <= nums[i] <= nums.length
        int map[201] = {0};
        vector<vector<int>> result;
        for (size_t i = 0; i < nums.size(); i++)
        {
            auto v = nums[i];
            auto appearTime = map[v]++;
            if (appearTime >= result.size())
            {
                result.resize(appearTime + 1);
            }

            result[appearTime].push_back(v);
        }

        // result.shrink_to_fit();
        return result;
    }
};