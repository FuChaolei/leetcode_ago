/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> a(nums.size(), 1);
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++)
        {
            a[i] = a[i - 1] * nums[i - 1];
        }
        int k = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            a[i] = k * a[i];
            k = k * nums[i];
        }
        return a;
    }
};
// @lc code=end
