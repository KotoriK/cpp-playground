#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{

public:
    string DEFAULT_ANSWER = "";
    string destCity(vector<vector<string>> &paths)
    {
        unordered_map<string, unsigned> cityMap;
        for (auto it = paths.begin(); it != paths.end(); it++)
        {
            cityMap[it->operator[](0)]++;
        }
        for (auto it = paths.begin(); it != paths.end(); it++)
        {
            if (cityMap[it->operator[](1)] == 0u)
            {
                return it->operator[](1);
            }
        }
        return DEFAULT_ANSWER;
    }
};

// 注意stack上的分配会有些微的性能影响 