/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (43.92%)
 * Likes:    2337
 * Dislikes: 0
 * Total Accepted:    605.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "()"
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "()[]{}"
 * 输出：true
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(]"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "([)]"
 * 输出：false
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "{[]}"
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由括号 '()[]{}' 组成
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> a;
        int count = s.size();
        for (int i = 0; i < count; i++)
        {
            if (a.empty())
            {
                a.push(s[i]);
            }
            else
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                    a.push(s[i]);
                else
                {
                    char x = a.top();
                    if (x == '(' && s[i] == ')' || x == '[' && s[i] == ']' || x == '{' && s[i] == '}')
                    {
                        a.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (!a.empty())
            return false;
        return true;
    }
};
// @lc code=end
