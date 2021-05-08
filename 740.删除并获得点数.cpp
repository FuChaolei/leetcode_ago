/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 *
 * https://leetcode-cn.com/problems/delete-and-earn/description/
 *
 * algorithms
 * Medium (54.37%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    33.9K
 * Total Submissions: 54.2K
 * Testcase Example:  '[3,4,2]'
 *
 * 给你一个整数数组 nums ，你可以对它进行一些操作。
 * 
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和
 * nums[i] + 1 的元素。
 * 
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,4,2]
 * 输出：6
 * 解释：
 * 删除 4 获得 4 个点数，因此 3 也被删除。
 * 之后，删除 2 获得 2 个点数。总共获得 6 个点数。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [2,2,3,3,3,4]
 * 输出：9
 * 解释：
 * 删除 3 获得 3 个点数，接着要删除两个 2 和 4 。
 * 之后，再次删除 3 获得 3 个点数，再次删除 3 获得 3 个点数。
 * 总共获得 9 个点数。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {

        vector<int> sums(10000);
        vector<int> res;
        int count = nums.size();
        if (count == 0)
            return 0;
        if (count == 1)
            return nums[0];
        for (int i = 0; i < count; i++)
        {
            sums[nums[i]] += nums[i];
        }
        // for (int i = 1; i <= 400; i++)
        // {
        //     sums[i] += i;
        // }
        // for (int i = 1; i <= 400; i++)
        // {
        //     if (sums[i])
        //         res.emplace_back(sums[i]);
        // }
        // for (int i = 0; i < 2; i++)
        // {
        //     cout << res[i] << endl;
        // }

        int first = sums[0];
        int second = max(sums[0], sums[1]);
        for (int i = 2; i < sums.size(); i++)
        {
            //cout << res.size();
            int temp = second;
            second = max(second, first + sums[i]);
            first = temp;
        }
        return second;
    }
};
// @lc code=end
