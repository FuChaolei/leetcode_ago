/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 *
 * https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (58.66%)
 * Likes:    201
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 57.1K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * 对于字符串 S 和 T，只有在 S = T + ... + T（T 自身连接 1 次或多次）时，我们才认定 “T 能除尽 S”。
 * 
 * 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：str1 = "ABCABC", str2 = "ABC"
 * 输出："ABC"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：str1 = "ABABAB", str2 = "ABAB"
 * 输出："AB"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：str1 = "LEET", str2 = "CODE"
 * 输出：""
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * str1[i] 和 str2[i] 为大写英文字母
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    //     string gcdOfStrings(string str1, string str2)
    //     {
    //         string temp, temp2;
    //         temp = str1.size() > str2.size() ? str2 : str1;
    //         temp2 = str1.size() > str2.size() ? str1 : str2;
    //         for (int i = 0; i < temp.size(); i++)
    //         {
    //             string t = temp.substr(i);
    //             string t2 = t;
    //             while (t != temp.size())
    //             {
    //             }
    //             while (t.size())
    //         }
    //     }
    // };
    string gcdOfStrings(string s1, string s2)
    {
        if (s1 + s2 != s2 + s1)
            return "";
        return s1.substr(0, __gcd((int)s1.size(), (int)s2.size()));
    }
};
// @lc code=end
