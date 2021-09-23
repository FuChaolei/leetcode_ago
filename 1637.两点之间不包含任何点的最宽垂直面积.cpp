/*
 * @lc app=leetcode.cn id=1637 lang=cpp
 *
 * [1637] 两点之间不包含任何点的最宽垂直面积
 *
 * https://leetcode-cn.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/
 *
 * algorithms
 * Medium (80.62%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 6.1K
 * Testcase Example:  '[[8,7],[9,9],[7,4],[9,7]]'
 *
 * 给你 n 个二维平面上的点 points ，其中 points[i] = [xi, yi] ，请你返回两点之间内部不包含任何点的 最宽垂直面积
 * 的宽度。
 * 
 * 垂直面积 的定义是固定宽度，而 y 轴上无限延伸的一块区域（也就是高度为无穷大）。 最宽垂直面积 为宽度最大的一个垂直面积。
 * 
 * 请注意，垂直区域 边上 的点 不在 区域内。
 * 
 * 
 * 
 * 示例 1：
 * ​
 * 
 * 输入：points = [[8,7],[9,9],[7,4],[9,7]]
 * 输出：1
 * 解释：红色区域和蓝色区域都是最优区域。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == points.length
 * 2 
 * points[i].length == 2
 * 0 i, yi 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &p)
    {
        sort(p.begin(), p.end());
        // for (int i = 0; i < p.size(); i++)
        // {
        //     cout << p[i][0] << " " << p[i][1] << endl;
        // }
        int res = 0;
        for (int i = 0; i < p.size() - 1; i++)
        {
            res = max(res, p[i + 1][0] - p[i][0]);
        }
        return res;
    }
};
// @lc code=end
