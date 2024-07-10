#include <vector>

using namespace std;

int calcArea(const vector<int> rect)
{
    return (rect[2] - rect[0]) * (rect[3] - rect[1]);
};

bool hasIntersectArea(const vector<int> extent1, const vector<int> extent2)
{
    /*   b_minX < a_maxX && b_minX > a_minX && b_minY < a_maxY && b_minY > a_minY
  ||
  b_maxX < a_maxX && b_maxX > a_minX && b_minY < a_maxY && b_minY > a_minY
  ||
  b_minX < a_maxX && b_minX > a_minX && b_maxY < a_maxY && b_maxY > a_minY
  ||
  b_maxX < a_maxX && b_maxX > a_minX && b_maxY < a_maxY && b_maxY > a_minY

  == (b_minX < a_maxX && b_minX > a_minX) || b_maxX < a_maxX && b_maxX> a_minX
  && (b_minY < a_maxY && b_minY > a_minY) || b_maxY < a_maxY && b_maxY > a_minY */
    return ((extent2[0] < extent1[2] && extent2[0] > extent1[0]) || (extent2[2] < extent1[2] && extent2[2] > extent1[0])) &&
           ((extent2[1] < extent1[3] && extent2[1] > extent1[1]) || (extent2[3] < extent1[3] && extent2[3] > extent1[1]));
}
class Solution
{
public:
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int sum_area = 0;
        int minX, maxX, minY, maxY;
        auto it = rectangles.begin();

        bool first = true;

        while (it != rectangles.end())
        {
            auto rect = *it;
            if (first == true)
            {
                minX = rect[0];
                minY = rect[1];
                maxX = rect[2];
                maxY = rect[3];
                first = false;
            }
            else
            {
                for (auto i = rectangles.begin(); i != it; i++)
                {
                    if (hasIntersectArea(rect, *i))
                    {
                        return false;
                    }
                }
                minX = min(minX, rect[0]);
                minY = min(minY, rect[1]);
                maxX = max(maxX, rect[2]);
                maxY = max(maxY, rect[3]);
            }
            int area = calcArea(rect);
            sum_area += area;
            it++;
        }

        int bbox_area = (maxX - minX) * (maxY - minY);
        return sum_area == bbox_area;
    }
};
