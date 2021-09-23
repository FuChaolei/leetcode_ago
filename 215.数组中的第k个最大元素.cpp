// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (64.71%)
 * Likes:    1216
 * Dislikes: 0
 * Total Accepted:    397.2K
 * Total Submissions: 613.8K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 
 * 
 * 提示： 
 * 
 * 
 * 1 
 * -10^4 
 * 
 * 
 */

// @lc code=start
//无脑排序
// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         sort(begin(nums), end(nums), greater<int>());
//         return nums[k - 1];
//     }
// };

//随机快排
// class Solution
// {
// public:
//     int findKthLargest(vector<int> &nums, int k)
//     {
//         int res = 0;
//         srand((unsigned)time(NULL));
//         quickSort(nums, 0, nums.size() - 1, k, res);
//         return res;
//     }
// private:
//     void quickSort(vector<int> &nums, int l, int r, int &k, int &res)
//     {
//         if (l > r)
//             return;
//         int m = rand() % (r - l + 1) + l;
//         swap(nums[l], nums[m]);
//         int t = nums[l];
//         int i = l;
//         int j = r;
//         while (i != j)
//         {
//             while (i < j && nums[j] <= t)
//                 j--;
//             while (i < j && nums[i] >= t)
//                 i++;
//             swap(nums[i], nums[j]);
//         }
//         swap(nums[l], nums[i]);
//         if (i == k - 1)
//         {
//             res = nums[i];
//             return;
//         }
//         quickSort(nums, l, i - 1, k, res);
//         quickSort(nums, i + 1, r, k, res);
//     }
// };

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        srand(time(0));
        return quickSort(nums, 0, nums.size() - 1, k);
    }

private:
    int quickSort(vector<int> &nums, int l, int r, int &k)
    {
        int m = rand() % (r - l + 1) + l;
        swap(nums[l], nums[m]);
        int t = nums[l];
        int i = l;
        int j = r;
        while (i != j)
        {
            while (i < j && nums[j] <= t)
                j--;
            while (i < j && nums[i] >= t)
                i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        if (i == k - 1)
            return nums[i];
        else if (i > k - 1)
            return quickSort(nums, l, i - 1, k);
        else
            return quickSort(nums, i + 1, r, k);
    }
};
