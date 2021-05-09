/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (65.24%)
 * Likes:    281
 * Dislikes: 0
 * Total Accepted:    114.2K
 * Total Submissions: 175K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret;
        vector<int> mid;
        for (int i = 0; i <= rowIndex; i++)
        {
            //vector<int> tmp(i + 1, 1);
            ret.resize(i + 1);
            ret[0] = ret[i] = 1;
            for (int j = 1; j < i; j++)
            {
                ret[j] = mid[j - 1] + mid[j];
            }
            mid = ret;
        }
        return ret;
    }
};
// @lc code=end
