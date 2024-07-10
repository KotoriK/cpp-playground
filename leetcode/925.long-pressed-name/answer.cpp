#include <string>

using namespace std;
class Solution
{
public:
    // stop at the last character of a repeated string
    ushort to_next_continuous_span(string::iterator &it, string::iterator end)
    {
        ushort repeat_times = 1;
        auto next = it + 1;
        while (next != end)
        {
            if (*it == *next)
            {
                it = next;
                next++;
                repeat_times++;
            }
            else
            {
                return repeat_times;
            }
        }
        return repeat_times;
    }
    bool isLongPressedName(string name, string typed)
    {
        auto name_it = name.begin();
        auto typed_it = typed.begin();

        while (name_it != name.end() && typed_it != typed.end())
        {
            auto name_repeat_times = to_next_continuous_span(name_it, name.end());
            auto typed_repeat_times = to_next_continuous_span(typed_it, typed.end());
            if (typed_repeat_times < name_repeat_times || *name_it != *typed_it)
            {
                return false;
            }
            else
            {
                name_it++;
                typed_it++;
            }
        }

        return typed_it == typed.end() && name_it == name.end();
    }
};