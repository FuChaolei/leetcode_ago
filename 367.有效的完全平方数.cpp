/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        double a = sqrt(num);
        int b = a;
        if (b * 1.0 == a)
            return true;
        return false;
    }
};
// @lc code=end
