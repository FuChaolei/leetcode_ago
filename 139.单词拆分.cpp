/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (50.34%)
 * Likes:    1017
 * Dislikes: 0
 * Total Accepted:    152.2K
 * Total Submissions: 302.2K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
 * 
 * 说明：
 * 
 * 
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 * 
 * 
 * 示例 1：
 * 
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 * 
 * 
 * 示例 2：
 * 
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 * 
 * 
 * 示例 3：
 * 
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 * 
 * 
 */

//@lc code = start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        //a = 0;
        vector<bool> dp(s.size() + 1);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string word = s.substr(j, i - j);
                vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), word);
                if (it != wordDict.end() && dp[j] == 1)
                    dp[i] = 1;
            }
        }
        return dp[s.size()];
    }
};
// 回溯
// class Solution
// {
// private:
//     bool dfs(string &s, vector<string> &wordDict, vector<int> &memo, int start)
//     {
//         if (start >= s.size())
//         {
//             return true;
//         }
//         if (memo[start] != -1)
//             return memo[start];
//         for (int i = start; i < s.size(); i++)
//         {
//             string word = s.substr(start, i - start + 1);
//             vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), word);
//             if (it != wordDict.end() && dfs(s, wordDict, memo, i + 1))
//             {
//                 memo[start] = 1;
//                 return true;
//             }
//         }
//         memo[start] = 0;
//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string> &wordDict)
//     {
//         vector<int> memo(s.size(), -1);
//         return dfs(s, wordDict, memo, 0);
//     }
// };
// class Solution
// {
// private:
//     bool backtracking(const string &s,
//                       vector<string> &wordDict,
//                       vector<int> &memory,
//                       int startIndex)
//     {
//         if (startIndex >= s.size())
//             return true;
//         // 如果memory[startIndex]不是初始值了，直接使用memory[startIndex]的结果
//         if (memory[startIndex] != -1)
//             return memory[startIndex];
//         for (int i = startIndex; i < s.size(); i++)
//         {
//             string word = s.substr(startIndex, i - startIndex + 1);
//             vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), word);
//             if (it != wordDict.end() && backtracking(s, wordDict, memory, i + 1))
//             {
//                 memory[startIndex] = 1; // 记录以startIndex开始的子串是可以被拆分的
//                 return true;
//             }
//         }
//         memory[startIndex] = 0; // 记录以startIndex开始的子串是不可以被拆分的
//         return false;
//     }
// public:
//     bool wordBreak(string s, vector<string> &wordDict)
//     {
//         vector<int> memory(s.size(), -1); // -1 表示初始化状态
//         return backtracking(s, wordDict, memory, 0);
//     }
// };
// @lc code=end
