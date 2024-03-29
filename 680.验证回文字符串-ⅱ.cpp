/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (40.06%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    68.9K
 * Total Submissions: 172.1K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool ishuiwen(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s)
    {
        int f = 0, n = 0, m = s.size() - 1;
        while (n <= m)
        {
            if (s[n] == s[m])
            {
                n++;
                m--;
            }
            else if (ishuiwen(s, n, m - 1) || ishuiwen(s, n + 1, m))
                return true;
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
