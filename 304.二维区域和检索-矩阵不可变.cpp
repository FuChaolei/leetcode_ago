/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-2d-immutable/description/
 *
 * algorithms
 * Medium (53.89%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    53K
 * Total Submissions: 97.3K
 * Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
  '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'
 *
 * 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。
 * 
 * 
 * 上图子矩阵左上角 (row1, col1) = (2, 1) ，右下角(row2, col2) = (4, 3)，该子矩形内元素的总和为 8。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 给定 matrix = [
 * ⁠ [3, 0, 1, 4, 2],
 * ⁠ [5, 6, 3, 2, 1],
 * ⁠ [1, 2, 0, 1, 5],
 * ⁠ [4, 1, 0, 1, 7],
 * ⁠ [1, 0, 3, 0, 5]
 * ]
 * 
 * sumRegion(2, 1, 4, 3) -> 8
 * sumRegion(1, 1, 2, 2) -> 11
 * sumRegion(1, 2, 2, 4) -> 12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 你可以假设矩阵不可变。
 * 会多次调用 sumRegion 方法。
 * 你可以假设 row1 ≤ row2 且 col1 ≤ col2 。
 * 
 * 
 */

// @lc code=start
class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        sums_.clear();
        if (matrix.empty())
        {
            return;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        sums_ = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                sums_[i][j] = matrix[i - 1][j - 1] + sums_[i - 1][j] + sums_[i][j - 1] - sums_[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1] - sums_[row1][col2 + 1] + sums_[row1][col1];
    }

private:
    vector<vector<int>> sums_;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
