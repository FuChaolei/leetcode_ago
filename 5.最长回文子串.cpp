/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (34.59%)
 * Likes:    3812
 * Dislikes: 0
 * Total Accepted:    636.1K
 * Total Submissions: 1.8M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

// @lc code=start
//暴力
// class Solution
// {
// public:
//     //unordered_map<string, int> temp;
//     bool judge(string &s, int l, int r)
//     {
//         //if (s == "bb")
//         for (int i = l, j = r; i < j; j--, i++)
//         {
//             if (s[i] != s[j])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
//     string longestPalindrome(string s)
//     {
//         if (s == "")
//             return s;
//         string t;
//         t += s[0];
//         int n = 0;
//         for (int i = 0; i < s.size(); i++)
//         {
//             for (int j = s.size(); j > i; j--)
//             {

//                 // cout << s.substr(i, j - i) << endl;
//                 if ((j - i + 1) > n && judge(s, i, j))
//                 {
//                     n = j - i + 1;
//                     t.clear();
//                     t = s.substr(i, j - i + 1);
//                 }
//             }
//         }

//         return t;
//     }
// };
//中心扩展法
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int len = 0;
//         if (s.size() == 0)
//             return "";
//         if (s.size() == 1)
//             return s;
//         auto wide1 = [&](int l, int r)
//         {
//             while (l >= 0 && r < s.size() && s[l] == s[r])
//             {
//                 r++;
//                 l--;
//             }
//             return r - l - 1;
//         };
//         int t;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (max(wide1(i, i), wide1(i, i + 1)) > len)
//             {
//                 len = max(wide1(i, i), wide1(i, i + 1));
//                 t = i;
//             }
//         }
//         cout << t << " " << len;
//         return s.substr(t - (len - 1) / 2, len);
//     }
// };
//动态规划
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;
        int start = 0;
        int len = 1;
        vector<vector<int>> res(s.size(), vector<int>(s.size()));
        for (int i = 0; i < s.size(); i++)
        {
            res[i][i] = 1;
            if (i + 1 < s.size() && s[i] == s[i + 1])
            {
                res[i][i + 1] = 1;
                start = i;
                len = 2;
            }
        }
        for (int i = 3; i <= s.size(); i++)
        {
            for (int j = 0; j + i - 1 < s.size(); j++)
            {
                int k = j + i - 1;
                if (s[j] == s[k] && res[j + 1][k - 1] == 1)
                {
                    res[j][k] = 1;
                    start = j;
                    len = i;
                }
            }
        }
        return s.substr(start, len);
    }
};
// @lc code=end
