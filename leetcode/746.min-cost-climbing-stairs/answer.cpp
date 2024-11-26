#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev = 0;
        int curr = 0;
        for(int i = 2;i <= cost.size();i++){
            int next = min(prev + cost[i-2],curr + cost[i-1]);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};