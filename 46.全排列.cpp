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
// class Solution
// {
// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         vector<vector<int>> res;
//         vector<int> cur;
//         dfs(nums, res, cur);
//         return res;
//     }
//     void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &cur)
//     {
//         if (cur.size() == nums.size())
//         {
//             res.emplace_back(cur);
//             return;
//         }
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (find(cur.begin(), cur.end(), nums[i]) != cur.end())
//                 continue;
//             cur.emplace_back(nums[i]);
//             dfs(nums, res, cur);
//             cur.pop_back();
//         }
//     }
// };
class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    const int n = nums.size();
    vector<vector<int>> ans;
    vector<int> used(n);
    vector<int> path;
    function<void(int)> dfs = [&](int d)
    {
      if (d == n)
      {
        ans.push_back(path);
        return;
      }
      for (int i = 0; i < n; ++i)
      {
        if (used[i])
          continue;
        used[i] = 1;
        path.push_back(nums[i]);
        dfs(d + 1);
        path.pop_back();
        used[i] = 0;
      }
    };
    dfs(0);
    return ans;
  }
};

// @lc code=end
