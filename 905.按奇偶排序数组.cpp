/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 *
 * https://leetcode-cn.com/problems/sort-array-by-parity/description/
 *
 * algorithms
 * Easy (70.19%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    54.2K
 * Total Submissions: 77.3K
 * Testcase Example:  '[3,1,2,4]'
 *
 * 给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
 * 
 * 你可以返回满足此条件的任何数组作为答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[3,1,2,4]
 * 输出：[2,4,3,1]
 * 输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 5000
 * 0 <= A[i] <= 5000
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        vector<int> res(nums.size());
        int i = 0, j = 0, k = nums.size() - 1;
        while (i < nums.size())
        {
            if (nums[i] % 2 == 0)
            {
                res[j] = nums[i];
                j++;
            }
            else
            {
                res[k] = nums[i];
                k--;
            }
            i++;
        }
        return res;
    }
};
// @lc code=end
