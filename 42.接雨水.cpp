/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (56.44%)
 * Likes:    2483
 * Dislikes: 0
 * Total Accepted:    273.2K
 * Total Submissions: 483.6K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
//暴力
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int n=height.size();
//         auto s = height.cbegin();
//         auto e = height.cend();
//         int res = 0;
//         for (int i = 0; i < n; i++)
//         {
//             int l = *max_element(s, s + i + 1);
//             int r = *max_element(s + i, e);
//             res += min(l, r) - height[i];
//         }
//         return res;
//     }
// };
//DP
// class Solution
// {
// public:
//     int trap(vector<int> &height)
//     {
//         int n = height.size();
//         vector<int> l(n);
//         vector<int> r(n);
//         for (int i = 0; i < n; i++)
//             l[i] = i == 0 ? height[i] : max(l[i - 1], height[i]);
//         for (int i = n - 1; i >= 0; i--)
//             r[i] = i == n - 1 ? height[i] : max(r[i + 1], height[i]);
//         int res = 0;
//         for (int i = 0; i < n; i++)
//         {
//             res += min(l[i], r[i]) - height[i];
//         }
//         return res;
//     }
// };
//空间优化
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n <= 1)
            return 0;
        int l = 0, r = n - 1;
        int max_l = height[0], max_r = height[n - 1];
        int res = 0;
        while (l < r)
        {
            if (max_l < max_r)
            {
                res += max_l - height[l];
                max_l = max(max_l, height[++l]);
            }
            else
            {
                res += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        return res;
    }
};
// @lc code=end
