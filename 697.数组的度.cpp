/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * https://leetcode-cn.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (60.73%)
 * Likes:    331
 * Dislikes: 0
 * Total Accepted:    59.3K
 * Total Submissions: 97.7K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums，数组的度的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[1, 2, 2, 3, 1]
 * 输出：2
 * 解释：
 * 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[1,2,2,3,1,4,2]
 * 输出：6
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums.length 在1到 50,000 区间范围内。
 * nums[i] 是一个在 0 到 49,999 范围内的整数。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        unordered_map<int, int> n_first;
        unordered_map<int, int> n_last;
        int count = nums.size();
        int m = count;
        for (int i = 0; i < count; i++)
        {
            cnt[nums[i]]++;
            if (n_first.count(nums[i]) == 0)
            {

                n_first[nums[i]] = i;
                cout << "n_first[nums[i]]" << i << "  " << n_first[nums[i]] << endl;
            }
            n_last[nums[i]] = i;
        }
        int n_max = 0;
        for (int i = 0; i < count; i++)
        {
            n_max = max(n_max, cnt[nums[i]]);
        }
        for (int i = 0; i < count; i++)
        {
            if (n_max == cnt[nums[i]])
            {
                //cout << m << endl;
                cout << "cnt[nums[i]]" << i << cnt[nums[i]] << endl;
                cout << "n_last[nums[i]]" << n_last[nums[i]] << endl;
                cout << "n_first[nums[i]]" << n_first[nums[i]] << endl;
                m = min(m, n_last[nums[i]] - n_first[nums[i]] + 1);
            }
        }
        return m;
    }
};
// @lc code=end
