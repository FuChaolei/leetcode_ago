/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 *
 * https://leetcode-cn.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (74.00%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    76.9K
 * Total Submissions: 103.9K
 * Testcase Example:  '3\n7'
 *
 * 找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
 * 
 * 说明：
 * 
 * 
 * 所有数字都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: k = 3, n = 7
 * 输出: [[1,2,4]]
 * 
 * 
 * 示例 2:
 * 
 * 输入: k = 3, n = 9
 * 输出: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */

// @lc code=start
class Solution
{
    vector<vector<int>> result;
    vector<int> path;
    void backtrcking(int start, int k, int n, int sum)
    {
        if (sum > n)
            return;
        if (path.size() == k && sum == n)
        {
            result.emplace_back(path);
            return;
        }
        for (int i = start; i <= 9 - (k - path.size()) + 1; i++)
        {
            sum += i;
            path.emplace_back(i);
            backtrcking(i + 1, k, n, sum);
            path.pop_back();
            sum -= i;
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        backtrcking(1, k, n, 0);
        return result;
    }
};
// @lc code=end
