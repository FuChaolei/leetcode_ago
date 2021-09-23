/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 *
 * https://leetcode-cn.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (61.66%)
 * Likes:    579
 * Dislikes: 0
 * Total Accepted:    144.4K
 * Total Submissions: 234K
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * 
 * 
 * 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c
 * 间接相连。
 * 
 * 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
 * 
 * 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而
 * isConnected[i][j] = 0 表示二者不直接相连。
 * 
 * 返回矩阵中 省份 的数量。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] 为 1 或 0
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 * 
 * 
 * 
 * 
 */

// @lc code=start
//DFS
// class Solution
// {
// public:
//     int findCircleNum(vector<vector<int>> &c)
//     {
//         if (c.empty())
//         {
//             return 0;
//         }
//         if (c.size() == 1)
//             return 1;
//         int n = c.size();
//         vector<int> v(n);
//         int res = 0;
//         for (int i = 0; i < c.size(); i++)
//         {
//             if (v[i] == 1)
//                 continue;
//             else
//             {
//                 res++;
//                 dfs(c, i, c.size(), v);
//             }
//         }
//         return res;
//     }

// private:
//     void
//     dfs(vector<vector<int>> &c, int x, int n, vector<int> &v)
//     {
//         if (v[x] == 1)
//             return;
//         v[x] = 1;
//         for (int i = 0; i < n; i++)
//         {
//             if (c[x][i] == 1)
//             {
//                 dfs(c, i, n, v);
//             }
//         }
//     }
// };
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &c)
    {
        int res = 0;
        for (int i = 0; i < c.size(); i++)
        {
            if (c[i][i] == 0)
                continue;
            res++;
            dfs(c, i, c.size());
        }
        return res;
    }

private:
    void dfs(vector<vector<int>> &c, int x, int n)
    {
        if (c[x][x] == 0)
            return;
        for (int i = 0; i < n; i++)
        {
            if (c[x][i] == 0)
                continue;
            c[x][i] = c[i][x] = 0;
            dfs(c, i, n);
        }
    }
};
// @lc code=end
