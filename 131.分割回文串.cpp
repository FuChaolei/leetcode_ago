/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (72.55%)
 * Likes:    717
 * Dislikes: 0
 * Total Accepted:    106.1K
 * Total Submissions: 146.3K
 * Testcase Example:  '"aab"'
 *
 * 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
 * 
 * 回文串 是正着读和反着读都一样的字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aab"
 * 输出：[["a","a","b"],["aa","b"]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a"
 * 输出：[["a"]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<vector<string>> res;
    vector<string> path;
    bool ishuiwen(string s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(const string &s, int start)
    {
        // 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
        if (start >= s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (ishuiwen(s, start, i))
            {
                string ss = s.substr(start, i - start + 1);
                path.emplace_back(ss);
                //cout << ss << endl;
            }
            else
            {
                continue;
            }
            backtracking(s, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return res;
    }
};
// @lc code=end
