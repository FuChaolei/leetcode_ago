// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem4.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.66%)
 * Likes:    4393
 * Dislikes: 0
 * Total Accepted:    480.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 
 * 0 
 * 1 
 * -10^6 
 * 
 * 
 * 
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 */

// @lc code=start
// class Solution
// {
// public:
//     double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
//     {
//         int m = nums1.size();
//         int n = nums2.size();
//         if (m == 0 && n == 0)
//             return 0;
//         else if (m == 0)
//         {
//             if (n % 2 == 1)
//                 return nums2[nums2.size() / 2];
//             else
//             {
//                 return 1.0 * (nums2[n / 2 - 1] + nums2[n / 2]) / 2;
//             }
//         }
//         else if (n == 0)
//         {
//             if (m % 2 == 1)
//                 return nums1[nums1.size() / 2];
//             else
//             {
//                 return 1.0 * (nums1[m / 2 - 1] + nums1[m / 2]) / 2;
//             }
//         }
//         if (m < n)
//         {
//             for (int i = 0; i < m; i++)
//             {
//                 nums2.emplace_back(nums1[i]);
//             }
//             sort(nums2.begin(), nums2.end());
//             n = nums2.size();
//             if (n % 2 == 1)
//                 return nums2[nums2.size() / 2];
//             else
//             {
//                 return 1.0 * (nums2[n / 2 - 1] + nums2[n / 2]) / 2;
//             }
//         }
//         else
//         {
//             for (int i = 0; i < n; i++)
//          {
//                 nums1.emplace_back(nums2[i]);
//             }
//             sort(nums1.begin(), nums1.end());
//             n = nums1.size();
//             if (n % 2 == 1)
//                 return nums1[nums1.size() / 2];
//             else
//             {
//                 return 1.0 * (nums1[n / 2 - 1] + nums1[n / 2]) / 2;
//             }
//         }
//     }
// };

class Solution
{
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
	{
		int tot = nums1.size() + nums2.size();
		if (tot % 2 == 0)
		{
			int left = find(nums1, 0, nums2, 0, tot / 2);
			int right = find(nums1, 0, nums2, 0, tot / 2 + 1);
			return (left + right) / 2.0;
		}
		else
		{
			return find(nums1, 0, nums2, 0, tot / 2 + 1);
		}
	}

	int find(vector<int> &nums1, int i, vector<int> &nums2, int j, int k)
	{
		if (nums1.size() - i > nums2.size() - j)
			return find(nums2, j, nums1, i, k);
		if (k == 1)
		{
			if (nums1.size() == i)
				return nums2[j];
			else
				return min(nums1[i], nums2[j]);
		}
		if (nums1.size() == i)
			return nums2[j + k - 1];
		int si = min((int)nums1.size(), i + k / 2), sj = j + k - k / 2;
		if (nums1[si - 1] > nums2[sj - 1])
			return find(nums1, i, nums2, sj, k - (sj - j));
		else
			return find(nums1, si, nums2, j, k - (si - i));
	}
};
// @lc code=end
