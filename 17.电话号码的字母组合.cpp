/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (56.59%)
 * Likes:    1303
 * Dislikes: 0
 * Total Accepted:    265.2K
 * Total Submissions: 468.7K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<string> a{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    string path;
    void backtrcking(string &digits, int n)
    {
        if (n == digits.size())
        {
            res.emplace_back(path);
            return;
        }
        //cout << a[digits[n] - '0'].size();
        for (int i = 0; i < a[digits[n] - '0'].size(); i++)
        {
            path += a[digits[n] - '0'][i];
            backtrcking(digits, n + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return res;
        backtrcking(digits, 0);
        return res;
    }
};
// @lc code=end
