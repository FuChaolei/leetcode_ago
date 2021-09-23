/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 *
 * https://leetcode-cn.com/problems/valid-mountain-array/description/
 *
 * algorithms
 * Easy (39.25%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    59.9K
 * Total Submissions: 152.7K
 * Testcase Example:  '[2,1]'
 *
 * 给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
 * 
 * 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：
 * 
 * 
 * arr.length >= 3
 * 在 0 < i < arr.length - 1 条件下，存在 i 使得：
 * 
 * arr[0] < arr[1] < ... arr[i-1] < arr[i] 
 * arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：arr = [2,1]
 * 输出：false
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arr = [3,5,5]
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：arr = [0,3,2,1]
 * 输出：true
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        //int temp=0;
        if (arr.size() == 1)
            return 0;
        auto it = max_element(arr.begin(), arr.end());
        if (it == arr.begin() || it == arr.end() - 1)
            return false;
        for (int i = 0; i < it - arr.begin(); i++)
        {
            if (arr[i] >= arr[i + 1])
                return false;
        }
        for (int i = it - arr.begin(); i < arr.size() - 1; i++)
        {
            if (arr[i] <= arr[i + 1])
                return false;
        }
        return true;
    }
};
// @lc code=end
