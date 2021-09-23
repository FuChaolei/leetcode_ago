/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 *
 * https://leetcode-cn.com/problems/largest-perimeter-triangle/description/
 *
 * algorithms
 * Easy (59.67%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    51.3K
 * Total Submissions: 85.9K
 * Testcase Example:  '[2,1,2]'
 *
 * 给定由一些正数（代表长度）组成的数组 A，返回由其中三个长度组成的、面积不为零的三角形的最大周长。
 * 
 * 如果不能形成任何面积不为零的三角形，返回 0。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[2,1,2]
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 输入：[1,2,1]
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 输入：[3,2,3,4]
 * 输出：10
 * 
 * 
 * 示例 4：
 * 
 * 输入：[3,6,2,3]
 * 输出：8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= A.length <= 10000
 * 1 <= A[i] <= 10^6
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    bool judge(int a, int b, int c)
    {
        if (a + b > c && (a + c > b) && (c + b > a))
            return true;
        return false;
    }

public:
    int largestPerimeter(vector<int> &nums)
    {
        //int res = 0;
        sort(nums.begin(), nums.end(), greater());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (judge(nums[i], nums[i + 1], nums[i + 2]))
            {
                return nums[i] + nums[i + 1] + nums[i + 2];
            }
        }
        return 0;
    }
};
// @lc code=end
