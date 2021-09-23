/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 *
 * https://leetcode-cn.com/problems/valid-boomerang/description/
 *
 * algorithms
 * Easy (44.18%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    8.8K
 * Total Submissions: 19.9K
 * Testcase Example:  '[[1,1],[2,3],[3,2]]'
 *
 * 回旋镖定义为一组三个点，这些点各不相同且不在一条直线上。
 * 
 * 给出平面上三个点组成的列表，判断这些点是否可以构成回旋镖。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[1,1],[2,3],[3,2]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,1],[2,2],[3,3]]
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * points.length == 3
 * points[i].length == 2
 * 0 <= points[i][j] <= 100
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isBoomerang(vector<vector<int>> &p)
    {
        int x1 = p[0][0], y1 = p[0][1], x2 = p[1][0], y2 = p[1][1], x3 = p[2][0], y3 = p[2][1];
        return (y1 - y2) * (x2 - x3) != (x1 - x2) * (y2 - y3);
    }
};
// @lc code=end
