/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (76.64%)
 * Likes:    574
 * Dislikes: 0
 * Total Accepted:    159.5K
 * Total Submissions: 207.9K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(n, k, 1);
        return res;
    }
    void backtracking(int n, int k, int st)
    {
        if (cur.size() == k)
        {
            res.emplace_back(cur);
            return;
        }
        for (int i = st; i <= n; i++)
        {
            cur.emplace_back(i);
            backtracking(n, k, i + 1);
            cur.pop_back();
        }
    }
};
// @lc code=end
