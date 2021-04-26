/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int count = nums.size(), n = 0;
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - 1; j++)
            {
                if (nums[j] == 0)
                {
                    int t = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = t;
                }
            }
        }
        }
};
// @lc code=end
