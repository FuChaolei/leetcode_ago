/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 *
 * https://leetcode-cn.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (45.40%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    58K
 * Total Submissions: 127.8K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：[1,12,-5,-6,50,3], k = 4
 * 输出：12.75
 * 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 k n 
 * 所给数据范围 [-10,000，10,000]。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int res = 0;
        for (int i = 0; i < k; i++)
            res += nums[i];
        //cout << res;
        int temp = res;
        for (int i = 0; i < nums.size() - k; i++)
        {
            temp = temp - nums[i] + nums[i + k];
            res = max(temp, res);
        }
        return res * 1.0 / k;
    }
};
// @lc code=end
