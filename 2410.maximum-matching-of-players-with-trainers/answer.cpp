#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());

        sort(trainers.begin(), trainers.end());

        auto it_p = players.begin();
        auto it_t = trainers.begin();
        auto matched_count = 0;

        while (it_t != trainers.end() && it_p != players.end())
        {
            if (*it_t >= *it_p)
            {
                matched_count++;
                it_p++;
            }
            it_t++;
        }
        return matched_count;
    }
};