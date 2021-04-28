/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 *
 * https://leetcode-cn.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (40.26%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    32.3K
 * Total Submissions: 72.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i],
 * answer[j]) 都应当满足：
 * 
 * answer[i] % answer[j] == 0 ，或
 * answer[j] % answer[i] == 0
 * 
 * 
 * 如果存在多个有效解子集，返回其中任何一个均可。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,2]
 * 解释：[1,3] 也会被视为正确答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,2,4,8]
 * 输出：[1,2,4,8]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * nums 中的所有整数 互不相同
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);
        for (int i = 0; i < n; i++)
        {
            int len = 1;
            int pre;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && len < f[j] + 1)
                {
                    len = f[j] + 1;
                    pre = j;
                }
            }
            f[i] = len;
            g[i] = pre;
        }
        int k = max_element(f.begin(), f.end()) - f.begin();
        int max = f[k];
        vector<int> res;
        //int r = 0;
        while (res.size() != max)
        {
            res.emplace_back(nums[k]);
            k = g[k];
        }
        return res;
    }
};
// @lc code=end
