/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 *
 * https://leetcode-cn.com/problems/single-number/description/
 *
 * algorithms
 * Easy (71.18%)
 * Likes:    1811
 * Dislikes: 0
 * Total Accepted:    379K
 * Total Submissions: 532K
 * Testcase Example:  '[2,2,1]'
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
 * 
 * 说明：
 * 
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 * 
 * 示例 1:
 * 
 * 输入: [2,2,1]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,1,2,1,2]
 * 输出: 4
 * 
 */

// @lc code=start
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int t;
        sort(nums.begin(), nums.end());
        if (nums.size() == 1)
            return nums[0];
        int count = nums.size();
        if (nums[count - 1] != nums[count - 2])
            return nums[count - 1];
        if (nums[0] != nums[1])
            return nums[0];

        for (int i = 1; i < nums.size() - 1; i++)
        {
            if (nums[i - 1] != nums[i] && nums[i + 1] != nums[i])
            {
                t = nums[i];
                break;
            }
        }
        return t;
    }
};
// @lc code=end
