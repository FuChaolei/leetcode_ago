/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] 交替位二进制数
 *
 * https://leetcode-cn.com/problems/binary-number-with-alternating-bits/description/
 *
 * algorithms
 * Easy (60.95%)
 * Likes:    101
 * Dislikes: 0
 * Total Accepted:    23.8K
 * Total Submissions: 39K
 * Testcase Example:  '5'
 *
 * 给定一个正整数，检查它的二进制表示是否总是 0、1 交替出现：换句话说，就是二进制表示中相邻两位的数字永不相同。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 5
 * 输出：true
 * 解释：5 的二进制表示是：101
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 7
 * 输出：false
 * 解释：7 的二进制表示是：111.
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 11
 * 输出：false
 * 解释：11 的二进制表示是：1011.
 * 
 * 示例 4：
 * 
 * 
 * 输入：n = 10
 * 输出：true
 * 解释：10 的二进制表示是：1010.
 * 
 * 示例 5：
 * 
 * 
 * 输入：n = 3
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        int t = 3;
        while (n)
        {
            if (t == n % 2)
                return false;
            t = n % 2;
            n /= 2;
        }
        return true;
    }
};
// @lc code=end
