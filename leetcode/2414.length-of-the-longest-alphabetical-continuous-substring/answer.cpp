#include <string>
using namespace std;
class Solution
{
public:
    int longestContinuousSubstring(string s)
    {
        int max_len = 0;
        int curr_len = 1;

        auto end = s.end();
        for (auto it = s.begin() + 1; it < end; it++)
        {
            if ((*it - *(it - 1)) == 1)
            {
                curr_len++;
            }
            else
            {
                if (curr_len > max_len)
                {
                    max_len = curr_len;
                }
                curr_len = 1;
            }
        }
        return max(curr_len, max_len);
    }
};