/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (79.63%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    109.2K
 * Total Submissions: 137.2K
 * Testcase Example:  '3'
 *
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：[[1,2,3],[8,9,4],[7,6,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<int> c{0, 1, 0, -1};
        vector<int> r{1, 0, -1, 0};
        int m = n * n;
        vector<vector<int>> res(n, vector<int>(n));
        int t = 0;
        int col = 0, row = 0;
        int d = 0;
        while (t < m)
        {
            t++;
            res[col][row] = t;
            int ncol = col + c[d];
            int nrow = row + r[d];

            if (ncol >= n || nrow >= n || nrow < 0 || ncol < 0 || res[ncol][nrow] != 0)
                d = (d + 1) % 4;
            col = col + c[d];
            row = row + r[d];
            cout << col << " " << row << endl;
        }
        return res;
    }
};
// @lc code=end
