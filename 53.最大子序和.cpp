/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int max = INT_MIN, s = 0;
        
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            if (s > max)
                max = s;
            if (s < 0)
            {
                s = 0;
            }
        }
        return max;
    }
};
// @lc code=end
