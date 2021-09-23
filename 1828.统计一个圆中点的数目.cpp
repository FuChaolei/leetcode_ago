
/*
 * @lc app=leetcode.cn id=1828 lang=cpp
 *
 * [1828] 统计一个圆中点的数目
 *
 * https://leetcode-cn.com/problems/queries-on-number-of-points-inside-a-circle/description/
 *
 * algorithms
 * Medium (87.79%)
 * Likes:    6
 * Dislikes: 0
 * Total Accepted:    6.4K
 * Total Submissions: 7.3K
 * Testcase Example:  '[[1,3],[3,3],[5,3],[2,2]]\n[[2,3,1],[4,3,1],[1,1,2]]'
 *
 * 给你一个数组 points ，其中 points[i] = [xi, yi] ，表示第 i 个点在二维平面上的坐标。多个点可能会有 相同 的坐标。
 * 
 * 同时给你一个数组 queries ，其中 queries[j] = [xj, yj, rj] ，表示一个圆心在 (xj, yj) 且半径为 rj
 * 的圆。
 * 
 * 对于每一个查询 queries[j] ，计算在第 j 个圆 内 点的数目。如果一个点在圆的 边界上 ，我们同样认为它在圆 内 。
 * 
 * 请你返回一个数组 answer ，其中 answer[j]是第 j 个查询的答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：points = [[1,3],[3,3],[5,3],[2,2]], queries = [[2,3,1],[4,3,1],[1,1,2]]
 * 输出：[3,2,2]
 * 解释：所有的点和圆如上图所示。
 * queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆。
 * 
 * 
 * 示例 2：
 * 
 * 输入：points = [[1,1],[2,2],[3,3],[4,4],[5,5]], queries =
 * [[1,2,2],[2,2,2],[4,3,2],[4,3,3]]
 * 输出：[2,3,2,4]
 * 解释：所有的点和圆如上图所示。
 * queries[0] 是绿色的圆，queries[1] 是红色的圆，queries[2] 是蓝色的圆，queries[3] 是紫色的圆。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= points.length <= 500
 * points[i].length == 2
 * 0 <= x​​​​​​i, y​​​​​​i <= 500
 * 1 <= queries.length <= 500
 * queries[j].length == 3
 * 0 <= xj, yj <= 500
 * 1 <= rj <= 500
 * 所有的坐标都是整数。
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    int juli2(int x1, int y1, int x2, int y2)
    {
        return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    }

public:
    vector<int> countPoints(vector<vector<int>> &p, vector<vector<int>> &q)
    {
        vector<int> res(q.size());
        for (int i = 0; i < q.size(); i++)
        {
            int t = 0;
            for (int j = 0; j < p.size(); j++)
            {
                if (juli2(q[i][0], q[i][1], p[j][0], p[j][1]) <= (q[i][2] * q[i][2]))
                {
                    t++;
                }
            }
            res[i] = t;
        }
        return res;
    }
};
// @lc code=end
