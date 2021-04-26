/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 *
 * https://leetcode-cn.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (73.41%)
 * Likes:    357
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 31.3K
 * Testcase Example:  '"2-1-1"'
 *
 * 给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及
 * * 。
 * 
 * 示例 1:
 * 
 * 输入: "2-1-1"
 * 输出: [0, 2]
 * 解释: 
 * ((2-1)-1) = 0 
 * (2-(1-1)) = 2
 * 
 * 示例 2:
 * 
 * 输入: "2*3-4*5"
 * 输出: [-34, -14, -10, -10, 10]
 * 解释: 
 * (2*(3-(4*5))) = -34 
 * ((2*3)-(4*5)) = -14 
 * ((2*(3-4))*5) = -10 
 * (2*((3-4)*5)) = -10 
 * (((2*3)-4)*5) = 10
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> diffWaysToCompute(string input)
    {
        //input = "1 + 5";
        vector<int> n;
        for (int i = 0; i < input.length(); ++i)
        {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));

                for (int i : left)
                {
                    for (int j : right)
                    {
                        switch (c)
                        {
                        case '+':
                            n.push_back(i + j);
                            break;
                        case '-':
                            n.push_back(i - j);
                            break;
                        case '*':
                            n.push_back(i * j);
                            break;
                        }
                    }
                }
            }
        }
        if (n.empty())
            n.push_back(stoi(input));
        return n;
        //return n;
    }
};
// @lc code=end
