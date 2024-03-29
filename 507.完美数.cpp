/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 *
 * https://leetcode-cn.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (40.33%)
 * Likes:    87
 * Dislikes: 0
 * Total Accepted:    26.5K
 * Total Submissions: 65.7K
 * Testcase Example:  '28'
 *
 * 对于一个 正整数，如果它和除了它自身以外的所有 正因子 之和相等，我们称它为 「完美数」。
 * 
 * 给定一个 整数 n， 如果是完美数，返回 true，否则返回 false
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：28
 * 输出：True
 * 解释：28 = 1 + 2 + 4 + 7 + 14
 * 1, 2, 4, 7, 和 14 是 28 的所有正因子。
 * 
 * 示例 2：
 * 
 * 输入：num = 6
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 输入：num = 496
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：num = 8128
 * 输出：true
 * 
 * 
 * 示例 5：
 * 
 * 输入：num = 2
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= num <= 10^8
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        if (num == 1)
            return false;
        int res = 0;
        for (int i = 2; i < sqrt(num); i++)
            if (num % i == 0)
                res = res + i + num / i;
        return res == num - 1;
    }
};
// @lc code=end
