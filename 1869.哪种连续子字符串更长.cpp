/*
 * @lc app=leetcode.cn id=1869 lang=cpp
 *
 * [1869] 哪种连续子字符串更长
 *
 * https://leetcode-cn.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/
 *
 * algorithms
 * Easy (84.48%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    11.1K
 * Total Submissions: 13.3K
 * Testcase Example:  '"1101"'
 *
 * 给你一个二进制字符串 s 。如果字符串中由 1 组成的 最长 连续子字符串 严格长于 由 0 组成的 最长 连续子字符串，返回 true ；否则，返回
 * false 。
 * 
 * 
 * 例如，s = "110100010" 中，由 1 组成的最长连续子字符串的长度是 2 ，由 0 组成的最长连续子字符串的长度是 3 。
 * 
 * 
 * 注意，如果字符串中不存在 0 ，此时认为由 0 组成的最长连续子字符串的长度是 0 。字符串中不存在 1 的情况也适用此规则。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1101"
 * 输出：true
 * 解释：
 * 由 1 组成的最长连续子字符串的长度是 2："1101"
 * 由 0 组成的最长连续子字符串的长度是 1："1101"
 * 由 1 组成的子字符串更长，故返回 true 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "111000"
 * 输出：false
 * 解释：
 * 由 1 组成的最长连续子字符串的长度是 3："111000"
 * 由 0 组成的最长连续子字符串的长度是 3："111000"
 * 由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "110100010"
 * 输出：false
 * 解释：
 * 由 1 组成的最长连续子字符串的长度是 2："110100010"
 * 由 0 组成的最长连续子字符串的长度是 3："110100010"
 * 由 1 组成的子字符串不比由 0 组成的子字符串长，故返回 false 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s[i] 不是 '0' 就是 '1'
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    int jud(string s, int n)
    {
        int t = 0, res = 0, flag = 0;
        if (s.size() == 1 && s[0] == n + '0')
            flag = 1;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i + 1] == n + '0' || s[i] == n + '0')
                flag = 1;
            if (s[i] == s[i + 1] && s[i] == n + '0')
            {
                t++;
                if (n == 0)
                    cout << t << endl;
            }
            else
            {
                res = max(t, res);
                t = 0;
            }
        }
        res = max(t, res);
        // if (res != 0||s.size())
        //     res++;
        // if (n == 0)
        //     cout << res << endl;
        return res + flag;
    }

public:
    bool checkZeroOnes(string s)
    {
        //cout << jud(s, 1) << jud(s, 0) << endl;
        return jud(s, 1) > jud(s, 0);
    }
};
// @lc code=end
