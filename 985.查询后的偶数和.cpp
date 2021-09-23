/*
 * @lc app=leetcode.cn id=985 lang=cpp
 *
 * [985] 查询后的偶数和
 *
 * https://leetcode-cn.com/problems/sum-of-even-numbers-after-queries/description/
 *
 * algorithms
 * Easy (59.75%)
 * Likes:    67
 * Dislikes: 0
 * Total Accepted:    15.5K
 * Total Submissions: 25.9K
 * Testcase Example:  '[1,2,3,4]\n[[1,0],[-3,1],[-4,0],[2,3]]'
 *
 * 给出一个整数数组 A 和一个查询数组 queries。
 * 
 * 对于第 i 次查询，有 val = queries[i][0], index = queries[i][1]，我们会把 val 加到 A[index]
 * 上。然后，第 i 次查询的答案是 A 中偶数值的和。
 * 
 * （此处给定的 index = queries[i][1] 是从 0 开始的索引，每次查询都会永久修改数组 A。）
 * 
 * 返回所有查询的答案。你的答案应当以数组 answer 给出，answer[i] 为第 i 次查询的答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：A = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
 * 输出：[8,6,2,4]
 * 解释：
 * 开始时，数组为 [1,2,3,4]。
 * 将 1 加到 A[0] 上之后，数组为 [2,2,3,4]，偶数值之和为 2 + 2 + 4 = 8。
 * 将 -3 加到 A[1] 上之后，数组为 [2,-1,3,4]，偶数值之和为 2 + 4 = 6。
 * 将 -4 加到 A[0] 上之后，数组为 [-2,-1,3,4]，偶数值之和为 -2 + 4 = 2。
 * 将 2 加到 A[3] 上之后，数组为 [-2,-1,3,6]，偶数值之和为 -2 + 6 = 4。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 10000
 * -10000 <= A[i] <= 10000
 * 1 <= queries.length <= 10000
 * -10000 <= queries[i][0] <= 10000
 * 0 <= queries[i][1] < A.length
 * 
 * 
 */

// @lc code=start
class Solution
{
    // private:
    //     int evensum(vector<int> &nums)
    //     {
    //         int res = 0;
    //         for (int i = 0; i < nums.size(); i++)
    //         {
    //             if (nums[i] % 2 == 0)
    //                 res += nums[i];
    //         }
    //         return res;
    //     }

public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> res;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
                temp += nums[i];
        }
        for (int i = 0; i < queries.size(); i++)
        {
            int cur = nums[queries[i][1]];
            nums[queries[i][1]] += queries[i][0];
            if (abs(nums[queries[i][1]]) % 2 == 1 && abs(cur) % 2 == 1)
                res.emplace_back(temp);
            else if (abs(nums[queries[i][1]]) % 2 == 0 && abs(cur) % 2 == 1)
            {
                res.emplace_back(temp + nums[queries[i][1]]);
                temp = temp + nums[queries[i][1]];
            }
            else if (abs(nums[queries[i][1]]) % 2 == 1 && abs(cur) % 2 == 0)
            {
                res.emplace_back(temp - cur);
                temp = temp - cur;
            }
            else
            {
                res.emplace_back(temp - cur + nums[queries[i][1]]);
                temp = res.back();
            }
        }
        return res;
    }
};
// @lc code=end
