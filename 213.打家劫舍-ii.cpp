/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (41.31%)
 * Likes:    566
 * Dislikes: 0
 * Total Accepted:    95.5K
 * Total Submissions: 227.9K
 * Testcase Example:  '[2,3,2]'
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈
 * ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [2,3,2]
 * 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,3,1]
 * 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    int max1(int s, int e, vector<int> &nums)
    {
        int first = nums[s];
        int second = max(nums[s + 1], nums[s]);
        for (int i = s + 2; i < e; i++)
        {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

public:
    int rob(vector<int> &nums)
    {
        // int count = nums.size();
        // if (count == 0)
        //     return 0;
        // if (count == 1)
        //     return nums[0];
        // if (count == 2)
        // {
        //     if (nums[0] > nums[1])
        //         return nums[0];
        //     else
        //     {
        //         return nums[1];
        //     }
        // }
        // int first = nums[0];
        // int second = max(nums[0], nums[1]);
        // int l = 0;
        // for (int i = 2; i < count - 1; i++)
        // {
        //     int temp = second;
        //     second = max(second, first + nums[i]);
        //     first = temp;
        // }
        // int s1 = second;
        // first = nums[1];
        // second = max(nums[1], nums[2]);
        // l = 0;
        // for (int i = 3; i < count; i++)
        // {
        //     int temp = second;
        //     second = max(second, first + nums[i]);
        //     first = temp;
        // }
        // if (s1 < second)
        //     s1 = second;
        // return s1;
        if (nums.size() < 1)
            return nums.size();
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        int s1 = max1(0, nums.size() - 1, nums);
        int s2 = max1(1, nums.size(), nums);
        return max(s1, s2);
    }
};
// @lc code=end
