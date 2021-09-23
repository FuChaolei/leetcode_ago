// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem416.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (50.05%)
 * Likes:    821
 * Dislikes: 0
 * Total Accepted:    134.5K
 * Total Submissions: 268.4K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,5,11,5]
 * 输出：true
 * 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,5]
 * 输出：false
 * 解释：数组不能分割成两个元素和相等的子集。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<int> dp(10001);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};
// class Solution
// {
// private:
//     bool backtracking(vector<int> &nums, int &s, vector<int> &k, int start)
//     {
//         if (start >= nums.size())
//         {
//             return k[0] == s;
//         }
//         for (int i = 0; i <= 1; i++)
//             if (k[i] + nums[start] <= s)
//             {
//                 k[i] += nums[start];
//                 if (backtracking(nums, s, k, start + 1))
//                     return true;
//                 k[i] -= nums[start];
//             }
//         return false;
//     }

// public:
//     bool
//     canPartition(vector<int> &nums)
//     {

//         int count = nums.size();
//         int s = 0;
//         for (int i = 0; i < count; i++)
//         {
//             s += nums[i];
//         }
//         if (s % 2 == 1)
//         {
//             return false;
//         }
//         sort(nums.begin(), nums.end(), greater());
//         s = s / 2;
//         vector<int> k(2);
//         return backtracking(nums, s, k, 0);
//     }
// };
// @lc code=end
