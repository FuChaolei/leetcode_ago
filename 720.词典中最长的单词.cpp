/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
 *
 * https://leetcode-cn.com/problems/longest-word-in-dictionary/description/
 *
 * algorithms
 * Easy (48.58%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    16.9K
 * Total Submissions: 34.8K
 * Testcase Example:  '["w","wo","wor","worl","world"]'
 *
 * 
 * 给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。
 * 
 * 若无答案，则返回空字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * words = ["w","wo","wor","worl", "world"]
 * 输出："world"
 * 解释： 
 * 单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
 * 输出："apple"
 * 解释：
 * "apply"和"apple"都能由词典中的单词组成。但是"apple"的字典序小于"apply"。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有输入的字符串都只包含小写字母。
 * words数组长度范围为[1,1000]。
 * words[i]的长度范围为[1,30]。
 * 
 * 
 */

// @lc code=start

// class Solution
// {
// public:
//     string longestWord(vector<string> &w)
//     {
//         set<string> st;
//         sort(w.begin(), w.end());
//         string res;
//         for (auto t : w)
//         {
//             if (t.size() == 1 || st.count(t.substr(0, t.size() - 1)) == 1)
//             {
//                 st.insert(t);
//                 if (res.size() < t.size() || t < res)
//                     res = t;
//             }
//         }
//         return res;
//     }
// };
// class Solution
// {
// public:
//     string longestWord(vector<string> &words)
//     {
//         set<string> cur;
//         sort(words.begin(), words.end());
//         string res = "";
//         for (string tem : words)
//         {
//             // cout<<tem<<endl;
//             if (tem.size() == 1 || tem.size() > 1 && cur.count(tem.substr(0, tem.size() - 1)) == 1)
//             {
//                 cur.insert(tem);
//                 if (res.size() < tem.size() || res.size() == tem.size() && res > tem)
//                     res = tem;
//             }
//         }
//         return res;
//     }
// };
class Solution
{
public:
    string longestWord(vector<string> &w)
    {
        //set<string> st;
        vector<string> st;
        sort(w.begin(), w.end());
        string res;
        for (auto t : w)
        {
            if (t.size() == 1 || count(st.begin(), st.end(), t.substr(0, t.size() - 1)) >= 1)
            {
                st.emplace_back(t);
                if (res.size() < t.size() || t < res)
                    res = t;
            }
        }
        return res;
    }
};
// @lc code=end
