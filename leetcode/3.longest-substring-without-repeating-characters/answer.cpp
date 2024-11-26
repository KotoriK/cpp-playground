#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;
/**
 * 使用 unordered_set 实现的滑动窗口
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        size_t longest = 0;
        size_t substart = 0;
        size_t subend = 0;  
        for(;subend<s.size();subend++){
            auto c = s[subend];
            if(set.contains(c)){
                longest = max(longest,subend - substart);
                for(;;){
                    char front = s[substart];
                    substart++;
                    if(front == c){
                        break;
                    }else{
                        set.erase(front);
                    }
                }  
            }
                set.insert(c);
        }
        return max(longest,subend - substart);
    }
};