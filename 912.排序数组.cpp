// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem912.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (57.46%)
 * Likes:    320
 * Dislikes: 0
 * Total Accepted:    181.1K
 * Total Submissions: 316K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 * 
 * 
 */

// @lc code=start

//无脑排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

//冒泡排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         for (int i = 0; i < nums.size() - 1; i++)
//         {
//             for (int j = 0; j < nums.size() - 1; j++)
//             {
//                 if (nums[j] > nums[j + 1])
//                     swap(nums[j], nums[j + 1]);
//             }
//         }
//         return nums;
//     }
// };

//选择排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int t = i;
//             for (int j = i + 1; j < nums.size(); j++)
//             {
//                 if (nums[j] < nums[t])
//                     t = j;
//             }
//             swap(nums[i], nums[t]);
//         }
//         return nums;
//     }
// };

//插入排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         for (int i = 1; i < nums.size(); i++)
//         {
//             int key = nums[i];
//             int j = i - 1;
//             while (j >= 0 && nums[j] > key)
//             {
//                 nums[j + 1] = nums[j];
//                 j--;
//             }
//             nums[++j] = key;
//         }
//         return nums;
//     }
// };

//快速排序
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return;
        srand((unsigned)time(NULL));
        int m = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
        swap(nums[m], nums[l]);
        int t = nums[l];
        int i = l;
        int j = r;
        while (i != j)
        {
            while (j > i && nums[j] >= t)
                j--;
            while (j > i && nums[i] <= t)
                i++;
            swap(nums[i], nums[j]);
        }
        swap(nums[i], nums[l]);
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
};

//计数排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

//堆排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

//归并排序
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };
// class Solution
// {
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         return nums;
//     }
// };

// class Solution
// {
//     int partition(vector<int> &nums, int l, int r)
//     {
//         int pivot = nums[r];
//         int i = l - 1;
//         for (int j = l; j <= r - 1; ++j)
//         {
//             if (nums[j] <= pivot)
//             {
//                 i = i + 1;
//                 swap(nums[i], nums[j]);
//             }
//         }
//         swap(nums[i + 1], nums[r]);
//         return i + 1;
//     }
//     int rpartition(vector<int> &nums, int l, int r)
//     {
//         int i = rand() % (r - l + 1) + l; // 随机选一个作为我们的主元
//         swap(nums[r], nums[i]);
//         return partition(nums, l, r);
//     }
//     void rquicksort(vector<int> &nums, int l, int r)
//     {
//         if (l < r)
//         {
//             int pos = rpartition(nums, l, r);
//             rquicksort(nums, l, pos - 1);
//             rquicksort(nums, pos + 1, r);
//         }
//     }
// public:
//     vector<int> sortArray(vector<int> &nums)
//     {
//         srand((unsigned)time(NULL));
//         rquicksort(nums, 0, (int)nums.size() - 1);
//         return nums;
//     }
// };
// @lc code=end
