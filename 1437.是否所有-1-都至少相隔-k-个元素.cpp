/*
 * @lc app=leetcode.cn id=1437 lang=cpp
 *
 * [1437] 是否所有 1 都至少相隔 k 个元素
 *
 * https://leetcode-cn.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/
 *
 * algorithms
 * Easy (59.15%)
 * Likes:    14
 * Dislikes: 0
 * Total Accepted:    9.4K
 * Total Submissions: 16K
 * Testcase Example:  '[1,0,0,0,1,0,0,1]\n2'
 *
 * 给你一个由若干 0 和 1 组成的数组 nums 以及整数 k。如果所有 1 都至少相隔 k 个元素，则返回 True ；否则，返回 False
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：nums = [1,0,0,0,1,0,0,1], k = 2
 * 输出：true
 * 解释：每个 1 都至少相隔 2 个元素。
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：nums = [1,0,0,1,0,1], k = 2
 * 输出：false
 * 解释：第二个 1 和第三个 1 之间只隔了 1 个元素。
 * 
 * 示例 3：
 * 
 * 输入：nums = [1,1,1,1,1], k = 0
 * 输出：true
 * 
 * 
 * 示例 4：
 * 
 * 输入：nums = [0,1,0,1], k = 1
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 0 <= k <= nums.length
 * nums[i] 的值为 0 或 1
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        int j, i, s, n;
        for (j = 0; j < nums.size(); j++)
        {
            if (nums[j] != 0)
            {
                break;
            }
        }
        for (int i = j + 1; i < nums.size(); i++)
        {
            n = i;
            while (n - i < k)
            {
                if (n < nums.size() && nums[n] != 0)
                    return false;
                n++;
            }
            s = n;
            for (; s < nums.size(); s++)
            {
                cout << s << endl;
                if (nums[s] != 0)
                {
                    break;
                }
            }
            i = s;
        }
        return true;
    }
};
// @lc code=end
