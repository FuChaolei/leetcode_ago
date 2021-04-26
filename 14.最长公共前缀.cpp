/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (39.31%)
 * Likes:    1568
 * Dislikes: 0
 * Total Accepted:    499.1K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string s;
        if (strs.size() == 0)
            return s;
        int count = strs[0].size();

        for (int i = 0; i < count; i++)
        {
            char c = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
            {
                if (c != strs[j][i])
                    return s;
                if (j == strs.size() - 1)
                    s += c;
            }
        }
        return s;
    }
};
// @lc code=end
