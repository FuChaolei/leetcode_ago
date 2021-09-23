/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.25%)
 * Likes:    1868
 * Dislikes: 0
 * Total Accepted:    299.4K
 * Total Submissions: 387.5K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
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
//暴力
// class Solution
// {
// private:
//     bool judge(string s)
//     {
//         stack<char> st;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (st.empty())
//             {
//                 if (s[i] == ')')
//                     return false;
//             }
//             if (s[i] == ')')
//             {
//                 if (st.top() == '(')
//                 {
//                     st.pop();
//                     continue;
//                 }
//             }
//             if (s[i] == '(')
//                 st.push(s[i]);
//         }
//         if (!st.empty())
//         {
//             return false;
//         }
//         return true;
//     }

// public:
//     vector<string> generateParenthesis(int n)
//     {
//         //next_permutation
//         string s;
//         vector<string> res;
//         for (int i = 0; i < n; i++)
//         {
//             s += '(';
//         }
//         for (int i = 0; i < n; i++)
//         {
//             s += ')';
//         }
//         res.emplace_back(s);
//         while (next_permutation(s.begin(), s.end()))
//         {
//             if (judge(s))
//                 res.emplace_back(s);
//         }
//         return res;
//     }
// };
//回溯
// class Solution
// {
// public:
//     int left = 0, right = 0;
//     void dfs(vector<string> &res, string &cur, int n)
//     {
//         if (cur.size() == 2 * n)
//             res.emplace_back(cur);
//         if (left < n)
//         {
//             cur += '(';
//             left++;
//             dfs(res, cur, n);
//             cur.pop_back();
//             left--;
//         }
//         if (right < left)
//         {
//             cur += ')';
//             right++;
//             dfs(res, cur, n);
//             cur.pop_back();
//             right--;
//         }
//     }
//     vector<string> generateParenthesis(int n)
//     {
//         vector<string> res;
//         string cur;
//         dfs(res, cur, n);
//         return res;
//     }
// };
//动态规划
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};
        dp[1] = {"()"};
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (auto l : dp[j])
                {
                    for (auto r : dp[i - j - 1])
                    {
                        string s = "(" + l + ")" + r;
                        dp[i].emplace_back(s);
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
