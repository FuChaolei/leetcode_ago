/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (77.83%)
 * Likes:    1323
 * Dislikes: 0
 * Total Accepted:    310.9K
 * Total Submissions: 399.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }
    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur, int s)
    {
        if (cur.size() == nums.size())
        {
            res.emplace_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(cur.begin(), cur.end(), nums[i]) != cur.end())
                continue;
            cur.emplace_back(nums[i]);
            dfs(nums, res, cur, i);
            cur.pop_back();
        }
    }
};
// @lc code=end
