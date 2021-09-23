/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 *
 * https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (44.80%)
 * Likes:    995
 * Dislikes: 0
 * Total Accepted:    128.4K
 * Total Submissions: 286.8K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 * 
 * 示例 1 :
 * 
 * 
 * 输入:nums = [1,1,1], k = 2
 * 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 * 
 * 
 * 说明 :
 * 
 * 
 * 数组的长度为 [1, 20,000]。
 * 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
 * 
 * 
 */

// @lc code=start
//暴力:TLE
// class Solution
// {
// public:
//     int subarraySum(vector<int> &nums, int k)
//     {
//         int res = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int temp = 0;
//             for (int j = i; j < nums.size(); j++)
//             {
//                 temp += nums[j];
//                 if (temp == k)
//                     res++;
//             }
//         }
//         return res;
//     }
// };
//前缀和:TLE
// class Solution
// {
// public:
//     int subarraySum(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         vector<int> sums(nums.size() + 1);
//         int res = 0;
//         partial_sum(nums.begin(), nums.end(), ++sums.begin());
//         for (auto it : sums)
//             cout << it << endl;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 if (sums[j + 1] - sums[i] == k)
//                 {
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };
//前缀和+hashmap
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if (nums.size() == 0)
            return 0;
        unordered_map<int, int> mp{{0, 1}};
        int res = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            res += mp[sum - k];
            mp[sum]++;
        }
        return res;
    }
};
// @lc code=end
