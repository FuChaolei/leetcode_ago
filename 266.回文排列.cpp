/*
 * @lc app=leetcode.cn id=266 lang=cpp
 *
 * [266] 回文排列
 *
 * https://leetcode-cn.com/problems/palindrome-permutation/description/
 *
 * algorithms
 * Easy (66.85%)
 * Likes:    46
 * Dislikes: 0
 * Total Accepted:    6.2K
 * Total Submissions: 9.3K
 * Testcase Example:  '"code"'
 *
 * 给定一个字符串，判断该字符串中是否可以通过重新排列组合，形成一个回文字符串。
 * 
 * 示例 1：
 * 
 * 输入: "code"
 * 输出: false
 * 
 * 示例 2：
 * 
 * 输入: "aab"
 * 输出: true
 * 
 * 示例 3：
 * 
 * 输入: "carerac"
 * 输出: true
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canPermutePalindrome(string s)
    {
        sort(s.begin(), s.end());
        int f = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            int num = 1;
            for (int j = i + 1; j < s.size(); j++)
            {
                if (s[j] == c)
                {
                    num++;
                }
                else
                {
                    i = j - 1;
                    break;
                }
            }
            if (num % 2 == 1)
                f++;
            if (f > 1)
                return false;
        }
        return true;
    }
};
// @lc code=end
