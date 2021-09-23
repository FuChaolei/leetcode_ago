/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 *
 * https://leetcode-cn.com/problems/valid-triangle-number/description/
 *
 * algorithms
 * Medium (53.20%)
 * Likes:    302
 * Dislikes: 0
 * Total Accepted:    49.5K
 * Total Submissions: 93.1K
 * Testcase Example:  '[2,2,3,4]'
 *
 * 给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2,2,3,4]
 * 输出: 3
 * 解释:
 * 有效的组合是: 
 * 2,3,4 (使用第一个 2)
 * 2,3,4 (使用第二个 2)
 * 2,2,3
 * 
 * 
 * 注意:
 * 
 * 
 * 数组长度不超过1000。
 * 数组里整数的范围为 [0, 1000]。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int l = j + 1, r = nums.size() - 1, k = j;
                while (l <= r)
                {
                    int mid = l + (r - l) / 2;
                    if (nums[i] + nums[j] > nums[mid])
                    {
                        k = mid;
                        l = mid + 1;
                    }
                    else
                    {
                        r = mid - 1;
                    }
                }
                res += k - j;
            }
        }
        return res;
    }
};
// @lc code=end
