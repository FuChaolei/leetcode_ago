/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 *
 * https://leetcode-cn.com/problems/partition-to-k-equal-sum-subsets/description/
 *
 * algorithms
 * Medium (43.34%)
 * Likes:    367
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 53.1K
 * Testcase Example:  '[4,3,2,3,5,2,1]\n4'
 *
 * 给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 * 
 * 示例 1：
 * 
 * 输入： nums = [4, 3, 2, 3, 5, 2, 1], k = 4
 * 输出： True
 * 说明： 有可能将其分成 4 个子集（5），（1,4），（2,3），（2,3）等于总和。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= k <= len(nums) <= 16
 * 0 < nums[i] < 10000
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool backtracking(vector<int> &nums, int &total, int start, vector<int> &res)
    {
        if (start >= nums.size())
        {
            return true;
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (nums[start] + res[i] <= total)
            {
                res[i] += nums[start];
                if (backtracking(nums, total, start + 1, res))
                    return true;
                res[i] -= nums[start];
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int s = 0;
        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            s += nums[i];
        }
        if (s % k != 0)
        {
            return false;
        }
        int total = s / k;
        sort(nums.begin(), nums.end(), greater());
        vector<int> res(k);
        return backtracking(nums, total, 0, res);
    }
};
// @lc code=end
