/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (47.60%)
 * Likes:    830
 * Dislikes: 0
 * Total Accepted:    171K
 * Total Submissions: 359.1K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * 输出：[1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * 输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 
 * -100 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &ma)
    {
        if (ma.size() == 0)
            return {};
        int m = ma.size(), n = ma[0].size();
        vector<int> res(m * n);
        vector<vector<bool>> s(m, vector<bool>(n));
        vector<int> dc{0, 1, 0, -1};
        vector<int> dr{1, 0, -1, 0};
        int c = 0, r = 0, d = 0;
        for (int i = 0; i < m * n; i++)
        {
            res[i] = ma[c][r];
            s[c][r] = 1;
            int a = c + dc[d];
            int b = r + dr[d];
            if (a < 0 || a >= m || b < 0 || b >= n || s[a][b] == 1)
            {
                d = (d + 1) % 4;
                a = c + dc[d];
                b = r + dr[d];
            }
            c = a, r = b;
        }
        return res;
    }
};
// @lc code=end
