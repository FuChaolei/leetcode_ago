/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() == 0)
            return 0;
        sort(points.begin(), points.end(), cmp);
        int c = 1, j;
        int k = points[0][1];
        for (int i = 0; i < points.size(); i++)
        {

            for (j = 1; j < points.size(); j++)
            {
                if (k < points[j][0])
                {
                    c++;
                    k = points[j][1];

                    break;
                }
            }
            i = j;
        }
        return c;
    }
};
// @lc code=end
