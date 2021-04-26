/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        vector<int> a;
        int p = 0;
        while (p < s.size())
        {
            int j = 0;
            char c = s[p];
            while (s[p] == c && p < s.size())
            {
                p++;
                j++;
            }
            a.push_back(j);
        }
        int n = 0;
        for (int i = 0; i < a.size() - 1; i++)
        {
            n += min(a[i], a[i + 1]);
        }
        return n;
    }
};
// @lc code=end
