/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (49.19%)
 * Likes:    309
 * Dislikes: 0
 * Total Accepted:    108.8K
 * Total Submissions: 221.2K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;
        while (n % 2 == 0)
            n /= 2;
        if (n == 1)
            return true;
        return false;
    }
};
// @lc code=end
