/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 *
 * https://leetcode-cn.com/problems/making-a-large-island/description/
 *
 * algorithms
 * Hard (39.39%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    7.5K
 * Total Submissions: 19.1K
 * Testcase Example:  '[[1,0],[0,1]]'
 *
 * 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
 * 
 * 返回执行此操作后，grid 中最大的岛屿面积是多少？
 * 
 * 岛屿 由一组上、下、左、右四个方向相连的 1 形成。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: grid = [[1, 0], [0, 1]]
 * 输出: 3
 * 解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: grid = [[1, 1], [1, 0]]
 * 输出: 4
 * 解释: 将一格0变成1，岛屿的面积扩大为 4。
 * 
 * 示例 3:
 * 
 * 
 * 输入: grid = [[1, 1], [1, 1]]
 * 输出: 4
 * 解释: 没有0可以让我们变成1，面积依然为 4。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == grid.length
 * n == grid[i].length
 * 1 
 * grid[i][j] 为 0 或 1
 * 
 * 
 */

// @lc code=start
//暴力：TLE
// class Solution1
// {
// public:
//     int ans = 0;
//     int maxAreaOfIsland(vector<vector<int>> g)
//     {
//         int res = 0;
//         if (g.empty())
//         {
//             return 0;
//         }
//         int m = g.size();
//         int n = g[0].size();
//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (g[i][j] == 1)
//                 {
//                     dfs(g, res, i, j, m, n);
//                     ans = max(res, ans);
//                     res = 0;
//                 }
//             }
//         }
//         return ans;
//     }

// private:
//     void dfs(vector<vector<int>> &g, int &res, int x, int y, int m, int n)
//     {
//         if (x < 0 || y < 0 || x == m || y == n || g[x][y] == 0)
//             return;
//         res++;
//         g[x][y] = 0;
//         dfs(g, res, x - 1, y, m, n);
//         dfs(g, res, x + 1, y, m, n);
//         dfs(g, res, x, y - 1, m, n);
//         dfs(g, res, x, y + 1, m, n);
//     }
// };
// class Solution
// {
// public:
//     int largestIsland(vector<vector<int>> &gr)
//     {
//         int as = Solution1().maxAreaOfIsland(gr);
//         for (int i = 0; i < gr.size(); i++)
//         {
//             for (int j = 0; j < gr.size(); j++)
//             {
//                 if (gr[i][j] == 1)
//                     continue;
//                 else
//                 {
//                     gr[i][j] = 1;
//                     as = max(as, Solution1().maxAreaOfIsland(gr));
//                     gr[i][j] = 0;
//                 }
//             }
//         }
//         return as;
//     }
// };
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        g_ = grid;
        int m = g_.size();
        int n = g_[0].size();
        int color = 1;
        unordered_map<int, int> mp;
        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g_[i][j] == 1)
                {

                    ++color;
                    mp[color] = dfs(g_, i, j, m, n, color);

                    res = max(res, mp[color]);
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (g_[i][j] == 0)
                {
                    int area = 1;
                    for (int color : set<int>{getcor(g_, i - 1, j), getcor(g_, i + 1, j), getcor(g_, i, j - 1), getcor(g_, i, j + 1)})
                    {
                        area += mp[color];
                    }
                    res = max(res, area);
                }
            }
        }
        return res;
    }

private:
    vector<vector<int>> g_;
    int getcor(vector<vector<int>> &g_, int x, int y)
    {
        if (x < 0 || y < 0 || x == g_.size() || y == g_[0].size())
            return 0;
        return g_[x][y];
    }
    int dfs(vector<vector<int>> &g_, int x, int y, int &m, int &n, int &color)
    {
        if (x < 0 || y < 0 || x == m || y == n || g_[x][y] != 1)
            return 0;
        g_[x][y] = color;
        return 1 + dfs(g_, x + 1, y, m, n, color) +
               dfs(g_, x - 1, y, m, n, color) +
               dfs(g_, x, y + 1, m, n, color) +
               dfs(g_, x, y - 1, m, n, color);
    }
};
// @lc code=end
