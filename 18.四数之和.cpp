/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (40.25%)
 * Likes:    840
 * Dislikes: 0
 * Total Accepted:    177.9K
 * Total Submissions: 441.5K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：答案中不可以包含重复的四元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++)
        {
            if (k > 0 && nums[k - 1] == nums[k])
                continue;
            for (int i = k + 1; i < nums.size(); i++)
            {
                if (i > k + 1 && nums[i] == nums[i - 1])
                    continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right)
                {
                    if (nums[k] + nums[i] + nums[left] + nums[right] > target)
                        right--;
                    else if (nums[k] + nums[i] + nums[left] + nums[right] < target)
                        left++;
                    else
                    {
                        res.emplace_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (right > left && nums[left + 1] == nums[left])
                            left++;
                        while (right > left && nums[right - 1] == nums[right])
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
