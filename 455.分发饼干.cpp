/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0, t = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = t; j < g.size(); j++)
            {
                if (s[i] >= g[j])
                {
                    count++;
                    t = j + 1;
                    break;
                }
                else
                    break;
            }
        }
        return count;
    }
};
// @lc code=end
