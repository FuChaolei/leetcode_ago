/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 *
 * https://leetcode-cn.com/problems/increasing-subsequences/description/
 *
 * algorithms
 * Medium (55.28%)
 * Likes:    282
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 67K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是 2 。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：[4, 6, 7, 7]
 * 输出：[[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7],
 * [4,7,7]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定数组的长度不会超过15。
 * 数组中的整数范围是 [-100,100]。
 * 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> &nums, int start)
    {
        if (path.size() > 1)
            res.emplace_back(path);
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++)
        {
            if (!path.empty() && nums[i] < path.back() || used.find(nums[i]) != used.end())
            {
                continue;
            }
            used.insert(nums[i]);
            path.emplace_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        backtracking(nums, 0);
        return res;
    }
};
// @lc code=end
