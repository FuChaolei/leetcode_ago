/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.36%)
 * Likes:    944
 * Dislikes: 0
 * Total Accepted:    235.2K
 * Total Submissions: 554.7K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int count = nums.size();
        vector<int> n;
        if (nums.empty())
        {
            n.push_back(-1);
            n.push_back(-1);
            return n;
        }
        if (count == 1 && nums[0] == target)
        {
            n.push_back(0);
            n.push_back(0);
            return n;
        }
        for (int i = 0; i < nums.size() && !nums.empty(); i++)
        {
            if (nums[i] == target && n.empty())
            {
                n.push_back(i);
            }
            if (nums[i] == target && (i + 1 == count || nums[i + 1] != target))
            {
                n.push_back(i);
                return n;
                break;
            }
        }
        if (n.empty())
        {
            n.push_back(-1);
            n.push_back(-1);
            return n;
        }
        return n;
    }
};
// @lc code=end
