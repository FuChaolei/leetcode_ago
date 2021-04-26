/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution
{
public:
    bool P(int n)
    {
        if (n == 2)
            return true;
        if (n == 1)
            return false;
        if (n == 0)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int countPrimes(int n)
    {
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            if (P(i))
                s++;
        }
        return s;
    }
};
// @lc code=end
