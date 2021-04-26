/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

// @lc code=start
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int s = 0, count = nums.size(), c = 0;
        for (int i = 0; i < count; i++)
        {
            if (nums[i] == 1)
            {
                c++;
                s = max(s, c);
            }
            else
            {
                c = 0;
            }
        }

        return s;
    }
};
// @lc code=end
