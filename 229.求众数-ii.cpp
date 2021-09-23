/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 *
 * https://leetcode-cn.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (46.02%)
 * Likes:    382
 * Dislikes: 0
 * Total Accepted:    32.4K
 * Total Submissions: 70.5K
 * Testcase Example:  '[3,2,3]'
 *
 * 给定一个大小为 n 的整数数组，找出其中所有出现超过 ⌊ n/3 ⌋ 次的元素。
 * 
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1)的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[3,2,3]
 * 输出：[3]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：[1,1,1,3,3,2,2,2]
 * 输出：[1,2]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^9 
 * 
 * 
 */

// @lc code=start
// class Solution
// {
// public:
//     vector<int> majorityElement(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         int d = nums.size() / 3;
//         vector<int> st;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (count(nums.begin(), nums.end(), nums[i]) > d)
//             {
//                 st.emplace_back(nums[i]);
//                 while ((i < nums.size() - 1) && nums[i] == nums[i + 1])
//                     i++;
//             }
//         }
//         //vector<int> ans(st.begin(), st.end());
//         //return {};
//         return st;
//     }
// };
//投票法
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int a = 0, b = 0, ac = 0, bc = 0;
        vector<int> res;
        if (nums.size() == 1)
            return {nums[0]};
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == a)
                ac++;
            else if (nums[i] == b)
            {
                bc++;
            }
            else if (ac == 0)
            {
                a = nums[i];
                ac++;
            }
            else if (bc == 0)
            {
                b = nums[i];
                bc++;
            }
            else
            {
                ac--;
                bc--;
            }
        }
        if (count(nums.begin(), nums.end(), a) > nums.size() / 3)
            res.emplace_back(a);
        if (count(nums.begin(), nums.end(), b) > nums.size() / 3 && a != b)
            res.emplace_back(b);
        return res;
    }
};
// @lc code=end
