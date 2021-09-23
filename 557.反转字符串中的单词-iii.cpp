/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (74.17%)
 * Likes:    294
 * Dislikes: 0
 * Total Accepted:    124.2K
 * Total Submissions: 167.4K
 * Testcase Example:  `"Let's take LeetCode contest"`
 *
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入："Let's take LeetCode contest"
 * 输出："s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string reverseWords(string s)
    {
        string res = "";
        string a;
        for (int i = 0; i < s.size(); i++)
        {
            //a = "";
            if (s[i] != ' ')
                a += s[i];
            else
            {
                reverse(a.begin(), a.end());
                cout << a << endl;
                res += a;
                res += " ";
                if (i != s.size() - 1)
                    a = "";
            }
        }
        reverse(a.begin(), a.end());
        cout << a << endl;
        res += a;
        return res;
    }
};
// @lc code=end
