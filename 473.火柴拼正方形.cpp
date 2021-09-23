/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 *
 * https://leetcode-cn.com/problems/matchsticks-to-square/description/
 *
 * algorithms
 * Medium (41.26%)
 * Likes:    182
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 41.9K
 * Testcase Example:  '[1,1,2,2,2]'
 *
 * 
 * 还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。
 * 
 * 输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,2,2,2]
 * 输出: true
 * 
 * 解释: 能拼成一个边长为2的正方形，每边两根火柴。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [3,3,3,3,4]
 * 输出: false
 * 
 * 解释: 不能用所有火柴拼成一个正方形。
 * 
 * 
 * 注意:
 * 
 * 
 * 给定的火柴长度和在 0 到 10^9之间。
 * 火柴数组的长度不超过15。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        if (matchsticks.size() < 4)
        {
            return false;
        }
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0)
        {
            return false;
        }
        vector<int> res(4);
        sum /= 4;
        sort(matchsticks.begin(), matchsticks.end(), greater());
        return backtracking(0, matchsticks, res, sum);
    }
    bool backtracking(int start, vector<int> &matchsticks, vector<int> &res, int nums)
    {
        if (start >= matchsticks.size())
        {
            return nums == res[0] && nums == res[1] && nums == res[2];
        }
        for (int i = 0; i < 4; i++)
        {
            if (matchsticks[start] + res[i] <= nums)
            {
                res[i] += matchsticks[start];
                if (backtracking(start + 1, matchsticks, res, nums))
                    return true;
                res[i] -= matchsticks[start];
            }
        }
        return false;
    }
};
//  class Solution
// {
// public:
//     bool makesquare(vector<int> &nums)
//     {
//         if (nums.size() < 4)
//             return false; //边数小于4
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         if (sum % 4)
//             return false;                               //和不是4的倍数
//         sort(nums.begin(), nums.end(), greater<int>()); //降序排列
//         vector<int> bucket(4);                          //4个边的值
//         return dfs(0, nums, sum / 4, bucket);
//     }
//     bool dfs(int index, vector<int> &nums, int target, vector<int> &bucket)
//     {                             //index为当前遍历到的下标，nums为边长数组,target为目标边长，bucket表示当前每条边的长度
//         if (index >= nums.size()) //每条边都用了
//             return bucket[0] == target && bucket[1] == target && bucket[2] == target;
//         for (int i = 0; i < 4; i++) //将当前边放在四个桶中分别尝试
//         {
//             if (bucket[i] + nums[index] > target) //说明不可以放在这一个边
//                 continue;
//             bucket[i] += nums[index]; //放入该边后继续DFS
//             if (dfs(index + 1, nums, target, bucket))
//                 return true;
//             bucket[i] -= nums[index]; //注意回溯的恢复状态
//         }
//         return false;
//     }
// };

// @lc code=end
