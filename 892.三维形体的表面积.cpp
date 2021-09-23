/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (63.87%)
 * Likes:    150
 * Dislikes: 0
 * Total Accepted:    32.5K
 * Total Submissions: 50.9K
 * Testcase Example:  '[[2]]'
 *
 * 给你一个 n * n 的网格 grid ，上面放置着一些 1 x 1 x 1 的正方体。
 * 
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
 * 
 * 放置好正方体后，任何直接相邻的正方体都会互相粘在一起，形成一些不规则的三维形体。
 * 
 * 请你返回最终这些形体的总表面积。
 * 
 * 注意：每个形体的底面也需要计入表面积中。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[2]]
 * 输出：10
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1,2],[3,4]]
 * 输出：34
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：grid = [[1,0],[0,2]]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：grid = [[1,1,1],[1,0,1],[1,1,1]]
 * 输出：32
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：grid = [[2,2,2],[2,1,2],[2,2,2]]
 * 输出：46
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        //int res = 0;
        int a = 0, b = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                a += grid[i][j];
                if (grid[i][j] > 0)
                    b += 2 * (grid[i][j] - 1);
                if (i - 1 >= 0)
                    b += min(grid[i][j], grid[i - 1][j]);
                if (i + 1 < grid.size())
                    b += min(grid[i][j], grid[i + 1][j]);
                if (j - 1 >= 0)
                    b += min(grid[i][j], grid[i][j - 1]);
                if (j + 1 < grid.size())
                    b += min(grid[i][j], grid[i][j + 1]);
            }
        }
        return a * 6 - b;
    }
};
// class Solution
// {
// public:
//     int surfaceArea(vector<vector<int>> &grid)
//     {
//         int ans, a = 0, b = 0, len = grid.size(), wid = grid[0].size();
//         for (auto i = 0; i < len; ++i)
//         {
//             for (auto j = 0; j < wid; ++j)
//             {
//                 a += grid[i][j];
//                 if (grid[i][j] > 0)
//                     b += 2 * (grid[i][j] - 1);
//                 if (i - 1 >= 0)
//                     b += min(grid[i][j], grid[i - 1][j]);
//                 if (i + 1 < len)
//                     b += min(grid[i][j], grid[i + 1][j]);
//                 if (j - 1 >= 0)
//                     b += min(grid[i][j], grid[i][j - 1]);
//                 if (j + 1 < wid)
//                     b += min(grid[i][j], grid[i][j + 1]);
//             }
//         }
//         return ans = 6 * a - b;
//     }
// };
// @lc code=end
