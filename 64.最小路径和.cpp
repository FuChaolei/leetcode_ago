/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (68.66%)
 * Likes:    925
 * Dislikes: 0
 * Total Accepted:    236.8K
 * Total Submissions: 344.9K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
//记忆化递归
// class Solution
// {
// private:
//     int minS(vector<vector<int>> &g, int m, int n, int x, int y)
//     {
//         if (x == y && x == 0)
//             return g[y][x];
//         if (x < 0 || y < 0)
//             return INT_MAX;
//         if (res[y][x] > 0)
//             return res[y][x];
//         res[y][x] = g[y][x] + min(minS(g, m, n, x - 1, y), minS(g, m, n, x, y - 1));
//         return res[y][x];
//     }

// public:
//     int minPathSum(vector<vector<int>> &g)
//     {
//         int m = g.size();
//         if (m == 0)
//             return 0;
//         int n = g[0].size();
//         res = vector<vector<int>>(m, vector<int>(n));
//         return minS(g, m, n, n - 1, m - 1);
//     }
//     vector<vector<int>> res;
// };
//动态规划
class Solution
{
public:
    int minPathSum(vector<vector<int>> &g)
    {
        int m = g.size();
        int n = g[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    continue;
                }
                if (i == 0)
                    g[i][j] = g[i][j] + g[i][j - 1];
                else if (j == 0)
                    g[i][j] = g[i][j] + g[i - 1][j];
                else
                {
                    g[i][j] = g[i][j] + min(g[i - 1][j], g[i][j - 1]);
                }
            }
        }
        return g[m - 1][n - 1];
    }
};
// @lc code=end
