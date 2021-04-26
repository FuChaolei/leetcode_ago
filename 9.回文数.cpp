/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string a = "";
        for (int i = 0; x != 0; i++)
        {
            int t;
            t = x % 10;
            a += t + '0';
            x /= 10;
        }
        string s = a;
        reverse(s.begin(), s.end());
        if (s == a)
            return true;
        return false;
    }
};
// @lc code=end
