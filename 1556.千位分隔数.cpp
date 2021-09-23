/*
 * @lc app=leetcode.cn id=1556 lang=cpp
 *
 * [1556] 千位分隔数
 *
 * https://leetcode-cn.com/problems/thousand-separator/description/
 *
 * algorithms
 * Easy (58.43%)
 * Likes:    10
 * Dislikes: 0
 * Total Accepted:    9.3K
 * Total Submissions: 16K
 * Testcase Example:  '987'
 *
 * 给你一个整数 n，请你每隔三位添加点（即 "." 符号）作为千位分隔符，并将结果以字符串格式返回。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 987
 * 输出："987"
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 1234
 * 输出："1.234"
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 123456789
 * 输出："123.456.789"
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 0
 * 输出："0"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n < 2^31
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string thousandSeparator(int n)
    {
        string temp = to_string(n);
        reverse(temp.begin(), temp.end());
        string res;
        for (int i = 0; i < temp.size(); i++)
        {
            if (i != 0 && i % 3 == 0)
            {
                res += ".";
                res += temp[i];
            }
            else
            {
                res += temp[i];
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
