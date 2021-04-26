/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution
{
public:
    bool Pishuiwen(string s, int b, int e)
    {
        while (b <= e)
        {
            if (s[b] != s[e])
                return false;
            b++;
            e--;
        }
        return true;
    }
    int countSubstrings(string s)
    {
        int count = s.size(), c = 0;
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j + i < count; j++)
            {
                if (Pishuiwen(s, i, i + j))
                {
                    c++;
                }
            }
        }
        return c;
    }
};
// @lc code=end
