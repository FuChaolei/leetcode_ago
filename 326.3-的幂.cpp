/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
        {
            return false;
        }
        else if (n == 1)
            return true;
        else if (n < 0)
            return false;
        else
        {
            while (n % 3 == 0 && n != 1)
                n /= 3;

            if (n == 1)
                return true;
            return false;
        }
    }
};
// @lc code=end
