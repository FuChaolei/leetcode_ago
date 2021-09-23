/*
 * @lc app=leetcode.cn id=1287 lang=cpp
 *
 * [1287] 有序数组中出现次数超过25%的元素
 *
 * https://leetcode-cn.com/problems/element-appearing-more-than-25-in-sorted-array/description/
 *
 * algorithms
 * Easy (60.70%)
 * Likes:    44
 * Dislikes: 0
 * Total Accepted:    14.1K
 * Total Submissions: 23.3K
 * Testcase Example:  '[1,2,2,6,6,6,6,7,10]'
 *
 * 给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。
 * 
 * 请你找到并返回这个整数
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：arr = [1,2,2,6,6,6,6,7,10]
 * 输出：6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= arr.length <= 10^4
 * 0 <= arr[i] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        double t = arr.size() * 1.0 / 4;
        int temp = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == temp)
                continue;
            if (count(arr.begin(), arr.end(), arr[i]) * 1.0 > t)
                return arr[i];
            temp = arr[i];
        }
        return -1;
    }
};
// @lc code=end
