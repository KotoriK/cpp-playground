#include <string>
#include <vector>

using namespace std;
// zigzag-conversion
class Solution
{
public:
    string convert(string s, int numRows)
    {
        size_t last_index = min(numRows, int(s.size()));
        vector<string> rows(last_index);
        last_index--;
        size_t curr_row = 0;
        bool direction = true;
        for (auto c : s)
        {
            rows[curr_row].push_back(c);

            if (last_index == 0)
            {
                continue;
            }
            if (direction)
            {
                if (curr_row == last_index)
                {
                    direction = false;
                    curr_row--;
                }
                else
                {
                    curr_row++;
                }
            }
            else
            {
                if (curr_row == 0)
                {
                    direction = true;
                    curr_row++;
                }
                else
                {
                    curr_row--;
                }
            }
        }
        auto it = rows.begin();
        
        string final_string = *it;
        final_string.reserve(s.size());
        while (++it < rows.end())
        {
            final_string.append(*it);
            std::cout << *it << std::endl;
        }
        return final_string;
    }
};