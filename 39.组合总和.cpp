/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.22%)
 * Likes:    1323
 * Dislikes: 0
 * Total Accepted:    249.6K
 * Total Submissions: 344.9K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, cur, res);
        return res;
    }
    void dfs(vector<int> &candidates, int target, int s, vector<int> &cur, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.emplace_back(cur);
            //cur.clear();
            return;
        }
        for (int i = s; i < candidates.size(); ++i)
        {
            if (candidates[i] > target)
                break;
            cur.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, cur, res);
            cur.pop_back();
            // cout << "i=" << i << endl;
            // for (int t = 0; t < cur.size(); t++)
            // {
            //     cout << cur[t] << " ";
            // }
            // cout << endl;
        }
    }
};
// @lc code=end
