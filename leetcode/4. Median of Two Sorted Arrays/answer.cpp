#include <vector>
#include <cmath>

using namespace std;

class Solution
{
public:
    /**
     * 两个vector是顺序排的，也就是说，插入新数组时，只需要考虑当前两个数组的头部的大小谁大谁小
     */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        auto half_total_len = (double)(nums1.size() + nums2.size()) / 2;
        auto median_pos = ceil(half_total_len);
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();

        unsigned int new_array_index = 0;
        bool pick_two = half_total_len == median_pos;

        median_pos--;
        
        bool is_temp_inited = false;
        int temp;

        while (new_array_index <= median_pos)
        {
            std::vector<int>::iterator *p_it_curr;
            if (it1 == nums1.end())
            {
                p_it_curr = &it2;
            }
            else if (it2 == nums2.end())
            {
                p_it_curr = &it1;
            }
            else
            {
                p_it_curr = *it1 < *it2 ? &it1 : &it2;
            }
            if (new_array_index == median_pos)
            {
                if (pick_two == true)
                {
                    if (is_temp_inited == true)
                    {
                        return (double)((**p_it_curr) + temp) / 2;
                    }
                    else
                    {
                        temp = **p_it_curr;
                        is_temp_inited = true;
                    }
                }
                else
                {
                    return **p_it_curr;
                }
            }
            else
            {
                new_array_index++;
            }
            (*p_it_curr)++;
        }
        return 0;
    }
};