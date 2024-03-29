/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (47.05%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    29.7K
 * Total Submissions: 63.2K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * 
 * 给定一个字符串和一个字符串字典，找到字典里面最长的字符串，该字符串可以通过删除给定字符串的某些字符来得到。如果答案不止一个，返回长度最长且字典顺序最小的字符串。如果答案不存在，则返回空字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["ale","apple","monkey","plea"]
 * 
 * 输出: 
 * "apple"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s = "abpcplea", d = ["a","b","c"]
 * 
 * 输出: 
 * "a"
 * 
 * 
 * 说明:
 * 
 * 
 * 所有输入的字符串只包含小写字母。
 * 字典的大小不会超过 1000。
 * 所有输入的字符串长度不会超过 1000。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool IsSubsequence(string s2, string s1)
    {
        cout << s1 << endl;
        cout << s2 << endl;
        int j = 0, count = s2.size();
        for (int i = 0; j < s1.size() && i < count; i++)
        {
            if (s1[j] == s2[i])
                j++;
        }
        return j == s1.size();
    }
    string findLongestWord(string s, vector<string> &dictionary)
    {
        string s1 = "";
        for (string s2 : dictionary)
        {
            if (IsSubsequence(s, s2))
            {
                //cout << IsSubsequence(s, s2);
                if (s2.size() > s1.size() || (s2.size() == s1.size() && s2 < s1))
                    s1 = s2;
            }
        }
        return s1;
    }
};
// @lc code=end
