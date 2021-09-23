/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 *
 * https://leetcode-cn.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (65.66%)
 * Likes:    517
 * Dislikes: 0
 * Total Accepted:    103.7K
 * Total Submissions: 157.6K
 * Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * 给定一个包含了一些 0 和 1 的非空二维数组 grid 。
 * 
 * 一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被
 * 0（代表水）包围着。
 * 
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
 * 
 * 
 * 
 * 示例 1:
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * 
 * 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
 * 
 * 示例 2:
 * 
 * [[0,0,0,0,0,0,0,0]]
 * 
 * 对于上面这个给定的矩阵, 返回 0。
 * 
 * 
 * 
 * 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 * 
 */

// @lc code=start
class Solution
{
public:
    int ans = 0;
    int maxAreaOfIsland(vector<vector<int>> &g)
    {
        int res = 0;
        if (g.empty())
        {
            return 0;
        }
        int m = g.size();
        int n = g[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == 1)
                {
                    dfs(g, res, i, j, m, n);
                    ans = max(res, ans);
                    res = 0;
                }
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<int>> &g, int &res, int x, int y, int m, int n)
    {
        if (x < 0 || y < 0 || x == m || y == n || g[x][y] == 0)
            return;
        res++;
        g[x][y] = 0;
        dfs(g, res, x - 1, y, m, n);
        dfs(g, res, x + 1, y, m, n);
        dfs(g, res, x, y - 1, m, n);
        dfs(g, res, x, y + 1, m, n);
    }
};
// @lc code=end
