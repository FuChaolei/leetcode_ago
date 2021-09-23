/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.29%)
 * Likes:    5614
 * Dislikes: 0
 * Total Accepted:    1M
 * Total Submissions: 2.8M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

// @lc code=start
//暴力
// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         int res = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             vector<int> temp(128);
//             int j = i;
//             while (j < s.size() && temp[s[j]] == 0)
//             {
//                 temp[s[j++]] = 1;
//             }
//             res = max(res, j - i);
//         }
//         return res;
//     }
// };
//滑动窗口
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        vector<int> temp(128, -1);
        for (int i = 0, j = 0; j < s.size(); j++)
        {
            i = max(i, temp[s[j]] + 1);
            res = max(res, j - i + 1);
            temp[s[j]] = j;
        }
        return res;
    }
};
// @lc code=end
