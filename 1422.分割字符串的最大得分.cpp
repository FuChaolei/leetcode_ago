/*
 * @lc app=leetcode.cn id=1422 lang=cpp
 *
 * [1422] 分割字符串的最大得分
 *
 * https://leetcode-cn.com/problems/maximum-score-after-splitting-a-string/description/
 *
 * algorithms
 * Easy (54.26%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    9.6K
 * Total Submissions: 17.8K
 * Testcase Example:  '"011101"'
 *
 * 给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右
 * 子字符串）所能获得的最大得分。
 * 
 * 「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "011101"
 * 输出：5 
 * 解释：
 * 将字符串 s 划分为两个非空子字符串的可行方案有：
 * 左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5 
 * 左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4 
 * 左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3 
 * 左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2 
 * 左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "00111"
 * 输出：5
 * 解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "1111"
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 500
 * 字符串 s 仅由字符 '0' 和 '1' 组成。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxScore(string s)
    {
        int res = 0;
        for (int i = 1; i < s.size(); i++)
        {
            string t1 = s.substr(0, i);
            string t2 = s.substr(i, s.size() - i);
            int n1 = count(t1.begin(), t1.end(), '0');
            int n2 = count(t2.begin(), t2.end(), '1');
            cout << t1 << " " << t2;
            int t = n1 + n2;
            res = max(res, t);
        }
        return res;
    }
};
// @lc code=end
