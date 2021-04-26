/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 *
 * https://leetcode-cn.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (26.54%)
 * Likes:    345
 * Dislikes: 0
 * Total Accepted:    35.4K
 * Total Submissions: 132.6K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j])
 * ，同时又满足 abs(i - j)  。
 * 
 * 如果存在则返回 true，不存在返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1], k = 3, t = 0
 * 输出：true
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,0,1,1], k = 1, t = 2
 * 输出：true
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,5,9,1,5,9], k = 2, t = 3
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -2^31 
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
// 题目：在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于k
// 要满足两个条件
// 1、存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t
// 2、满足 i 和 j 的差的绝对值也小于等于k
// 第二个条件很好满足，维持一个滑动窗口即可，关键是第一个条件
// 由|nums[i]-num[j]|<=t可以推出
// nums[i]-t<=nums[j]<=nums[i]+t
// 现在，set的内置函数lower_bound可以找到第一个大于等于nums[i]-t的数，则这个数再满足小于等于nums[i]+t即可
// 同时，这道题目不需要multiset。即便有重复，重复数字挨得足够近在插入之前就已经满足条件了；重复数字离得太远，不会同时进入滑动窗口
// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//         set<long long> st;
//         int left = 0;
//         for (int right = 0; right < nums.size(); right ++) {
//             if (right - left > k) {
//                 st.erase(nums[left]);
//                 left ++;
//             }
//             auto a = st.lower_bound((long long) nums[right] - t);
//             if (a != st.end() && abs(*a - nums[right]) <= t) {
//                 return true;
//             }
//             st.insert(nums[right]);
//         }
//         return false;
//     }
// };
// class Solution {
// public:
//     bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
//         std::set<long> s;
//         for (int i = 0; i < nums.size(); ++i) {
//             auto pos = s.lower_bound(long(nums[i])-t);
//             ////< @attention
//             if (pos!=s.end() && *pos<=long(nums[i])+t) {return true;}
//             s.insert(nums[i]);
//             if (s.size() > k) {s.erase(nums[i-k]);} ////< @note 维护活动窗口
//         }
//         return false;
//     }
// };

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        // int count = nums.size();
        // if (count < 2)
        //     return false;
        // // vector<long> nums1;
        // // nums1.resize(nums.size());
        // // copy(nums.begin(), nums.end(), nums1.begin());
        // while (k)
        // {
        //     // if (k == 0)
        //     //     break;
        //     for (int i = 0; i < count; i++)
        //     {
        //         long long c;
        //         if (i + k < count)
        //             c = (long)nums[i] - (long)nums[i + k];
        //         if (i + k < count && abs(c) <= t)
        //         {
        //             return true;
        //         }
        //     }
        //     k--;
        // }
        // return false;
        int left = 0, count = nums.size();
        set<long> st;
        for (int i = 0; i < count; i++)
        {
            if (i - left > k)
            {
                st.erase(nums[left]);
                left++;
            }
            auto pos = st.lower_bound((long long)nums[i] - t);
            if (pos != st.end() && long(nums[i]) + t >= *pos)
                return true;
            st.insert(nums[i]);
        }
        return false;
    }
};
// @lc code=end
