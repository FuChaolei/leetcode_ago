/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int k = 0;
        for (int i = 1; i <= n; i++)
        {
            int t = i;
            while (t != 0)
            {
                if (t % 5 == 0)
                {
                    t /= 5;
                    k++;
                }
                else
                    break;
            }
        }
        return k;
    }
};
// @lc code=end
