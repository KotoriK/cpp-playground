#include <vector>
#include <algorithm>
using namespace std;
// performance identical with iterator version
class Solution
{
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        size_t i_p = 0;
        size_t i_t = 0;
        size_t matched_count = 0;

        size_t t_size = trainers.size();
        size_t p_size = players.size();

        while (i_t < t_size && i_p < p_size)
        {
            if (trainers[i_t++] >= players[i_p])
            {
                matched_count++;
                i_p++;
            }
        }
        return matched_count;
    }
};