/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (63.67%)
 * Likes:    572
 * Dislikes: 0
 * Total Accepted:    155.6K
 * Total Submissions: 244.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &candidate, int sum, int target, int start)
    {
        if (sum == target)
        {
            result.emplace_back(path);
            return;
        }
        for (int i = start; i < candidate.size() && sum + candidate[i] <= target; i++)
        {
            if (i > start && candidate[i] == candidate[i - 1])
                continue;
            sum += candidate[i];
            path.emplace_back(candidate[i]);
            backtracking(candidate, sum, target, i + 1);
            sum -= candidate[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, 0, target, 0);
        return result;
    }
};
// @lc code=end
