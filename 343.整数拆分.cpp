/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (59.87%)
 * Likes:    527
 * Dislikes: 0
 * Total Accepted:    89.6K
 * Total Submissions: 149.7K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 */

// @lc code=start
class Solution
{
public:
    int integerBreak(int n)
    {
        //动态规划
        // vector<int> dp(n + 1);
        // dp[2] = 1;
        // for (int i = 3; i <= n; i++)
        // {
        //     for (int j = 1; j < i - 1; j++)
        //     {
        //         //dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
        //         dp[i] = max(dp[i], max((i - j) * j, j * dp[i - j]));
        //     }
        // }
        // return dp[n];
        //贪心
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        if (n == 4)
        {
            return 4;
        }
        int res = 1;
        while (n > 4)
        {
            res *= 3; /* code */
            n -= 3;
        }
        res *= n;
        return res;
    }
};
// @lc code=end
