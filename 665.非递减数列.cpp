/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        //int f=0,k=0,j=0;
        int s = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
            {
                if (i == 1 || nums[i] >= nums[i - 2])
                    nums[i - 1] = nums[i];
                else
                    nums[i] = nums[i - 1];
                s++;
            }
        }
        return s <= 1;
    }
};
// @lc code=end
