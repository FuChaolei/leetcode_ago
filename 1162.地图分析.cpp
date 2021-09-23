/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 *
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (46.84%)
 * Likes:    210
 * Dislikes: 0
 * Total Accepted:    36.5K
 * Total Submissions: 77.9K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 N x N 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1
 * 代表陆地，请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。
 * 
 * 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 -
 * x1| + |y0 - y1| 。
 * 
 * 如果网格上只有陆地或者海洋，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释： 
 * 海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释： 
 * 海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 不是 0 就是 1
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxDistance(vector<vector<int>> &g)
    {
        queue<pair<int, int>> q;
        int m = g.size();
        int n = g[0].size();
        for (int i = 0; i < g.size(); i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                if (g[i][j] == 1)
                    q.push({i, j});
            }
        }
        if (q.size() == 0 || q.size() == m * n)
            return -1;
        int d = -1;
        while (q.size() != 0)
        {
            d++;
            int s = q.size();
            while (s--)
            {
                auto cur = q.front();
                q.pop();
                for (auto it : dir)
                {
                    int x = cur.first + it[0];
                    int y = cur.second + it[1];
                    if (x < 0 || x >= m || y >= n || y < 0 || g[x][y] != 0)
                        continue;
                    g[x][y] = 2;
                    q.push({x, y});
                }
            }
        }
        return d;
    }

private:
    vector<vector<int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
};
// class Solution
// {
// public:
//     int maxDistance(vector<vector<int>> &grid)
//     {
//         const int M = grid.size();
//         const int N = grid[0].size();
//         // 使用deque作为队列
//         deque<pair<int, int>> deq;
//         for (int i = 0; i < M; ++i)
//         {
//             for (int j = 0; j < N; ++j)
//             {
//                 if (grid[i][j] == 1)
//                 {
//                     // 将所有陆地都放入队列中
//                     deq.push_back({i, j});
//                 }
//             }
//         }
//         // 如果没有陆地或者海洋，返回-1
//         if (deq.size() == 0 || deq.size() == M * N)
//         {
//             return -1;
//         }
//         // 由于BFS的第一层遍历是从陆地开始，因此遍历完第一层之后distance应该是0
//         int distance = -1;
//         // 对队列的元素进行遍历
//         while (deq.size() != 0)
//         {
//             // 新遍历了一层
//             distance++;
//             // 当前层的元素有多少，在该轮中一次性遍历完当前层
//             int size = deq.size();
//             while (size--)
//             {
//                 // BFS遍历的当前元素永远是队列的开头元素
//                 auto cur = deq.front();
//                 deq.pop_front();
//                 // 对当前元素的各个方向进行搜索
//                 for (auto &d : directions)
//                 {
//                     int x = cur.first + d[0];
//                     int y = cur.second + d[1];
//                     // 如果搜索到的新坐标超出范围/陆地/已经遍历过，则不搜索了
//                     if (x < 0 || x >= M || y < 0 || y >= N ||
//                         grid[x][y] != 0)
//                     {
//                         continue;
//                     }
//                     // 把grid中搜索过的元素设置为2
//                     grid[x][y] = 2;
//                     // 放入队列中
//                     deq.push_back({x, y});
//                 }
//             }
//         }
//         // 最终走了多少层才把海洋遍历完
//         return distance;
//     }

// private:
//     vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
// };
// @lc code=end
