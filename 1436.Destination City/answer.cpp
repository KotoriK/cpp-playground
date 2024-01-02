#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Node
{
    Node *next;
};

class Solution
{
private:
    unordered_map<string, Node> cityMap;
    Node *getCityNode(string cityName)
    {
        auto existed = &cityMap[cityName];
        if (existed == nullptr)
        {
            existed = new Node();
        }
        return existed;
    }

public:
    string destCity(vector<vector<string>> &paths)
    {

        for (auto it = paths.begin(); it != paths.end(); it++)
        {
            auto path = *it;
            auto cityNodeFrom = getCityNode(path[0]);
            auto cityNodeTo = getCityNode(path[1]);
            cityNodeFrom->next = cityNodeTo;
        }
        for (auto it = cityMap.begin(); it != cityMap.end(); it++)
        {
            auto cityNode = it->second;
            if (cityNode.next == nullptr)
            {
                return it->first;
            }
        }
        return "";
    }
};