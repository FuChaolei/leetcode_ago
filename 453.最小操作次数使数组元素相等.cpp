/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 *
 * https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/description/
 *
 * algorithms
 * Easy (55.12%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    24.2K
 * Total Submissions: 43.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个长度为 n 的 非空 整数数组，每次操作将会使 n - 1 个元素增加 1。找出让数组所有元素相等的最小操作次数。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * [1,2,3]
 * 输出：
 * 3
 * 解释：
 * 只需要3次操作（注意每次操作会增加两个元素的值）：
 * [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int res = 0;
        sort(nums.begin(), nums.end());
        if (nums.size() <= 1)
            return res;
        int diff = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            diff = nums[i] - nums[i - 1];
            res += diff;
            if (i < nums.size() - 1)
                nums[i + 1] += res;
        }
        return res;
    }
};
// @lc code=end
