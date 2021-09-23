/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode-cn.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (57.74%)
 * Likes:    130
 * Dislikes: 0
 * Total Accepted:    39K
 * Total Submissions: 67.5K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: s = "abcdefg", k = 2
 * 输出: "bacdfeg"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 该字符串只包含小写英文字母。
 * 给定字符串的长度和 k 在 [1, 10000] 范围内。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        int j = 0, t = 0, i = 0;
        while (i < s.size())
        {
            if (s.size() - j >= k)
            {
                reverse(s.begin() + j, s.begin() + j + k);
                j += k;
                i = j;
            }
            else
            {
                reverse(s.begin() + j, s.end());
                break;
            }
            j += k;
            i = j;
        }
        return s;
    }
};
// @lc code=end
