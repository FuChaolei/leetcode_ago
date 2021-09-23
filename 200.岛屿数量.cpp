/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (54.46%)
 * Likes:    1240
 * Dislikes: 0
 * Total Accepted:    283.1K
 * Total Submissions: 518.3K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * 输出：3
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
 * grid[i][j] 的值为 '0' 或 '1'
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int numIslands(vector<vector<char>> &g)
    {
        if (g.empty())
            return 0;
        int m = g.size();
        int n = g[0].size();
        if (m == n && m == 1)
            return g[0][0] == '1' ? 1 : 0;
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                res += g[i][j] - '0';
                dfs(g, i, j, m, n);
            }
        }
        return res;
    }

private:
    int res = 0;
    void dfs(vector<vector<char>> &g, int x, int y, int m, int n)
    {
        if (x < 0 || y < 0 || x == m || y == n || g[x][y] == '0')
            return;
        g[x][y] = '0';
        dfs(g, x + 1, y, m, n);
        dfs(g, x - 1, y, m, n);
        dfs(g, x, y + 1, m, n);
        dfs(g, x, y - 1, m, n);
    }
};
// @lc code=end
