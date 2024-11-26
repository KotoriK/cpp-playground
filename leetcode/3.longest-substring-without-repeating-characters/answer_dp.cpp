#include <string>
#include <algorithm>
using namespace std;
/**
 * [刍狗](https://leetcode.cn/u/chu-gou-w/)动态规划解法，Aone Copilot优化
 * @seealso https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/227999/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-by-leetc-2/comments/2428413
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, dp = 0;
        int last[128]; // 初始化数组，所有元素为 -1
        fill(last, last + 128, -1);
        for (size_t i = 0; i < s.size(); ++i) {
            const char ch = s[i];
            
            // 计算当前字符的最新无重复子串长度
            dp = min(dp + 1, static_cast<int>(i) - last[ch]);
            
            // 如果当前子串更长，则更新答案
            if (dp > ans) {
                ans = dp;
            }
            
            // 更新当前字符最后出现的位置
            last[ch] = i;
        }
        
        return ans;
    }
};