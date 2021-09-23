/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 *
 * https://leetcode-cn.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (34.31%)
 * Likes:    291
 * Dislikes: 0
 * Total Accepted:    25.3K
 * Total Submissions: 73.9K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
 * 
 * 你需要返回给定数组中的重要翻转对的数量。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,3,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [2,4,3,5,1]
 * 输出: 3
 * 
 * 
 * 注意:
 * 
 * 
 * 给定数组的长度不会超过50000。
 * 输入数组中的所有数字都在32位整数的表示范围内。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (abs(nums[i]) <= nums[j])
                    continue;
                if (nums[i] - nums[j] > nums[j])
                    res++;
            }
        }
        return res;
    }
};
// @lc code=end
