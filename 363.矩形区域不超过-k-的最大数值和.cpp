/*
 * @lc app=leetcode.cn id=363 lang=cpp
 *
 * [363] 矩形区域不超过 K 的最大数值和
 *
 * https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/description/
 *
 * algorithms
 * Hard (39.94%)
 * Likes:    321
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 58.6K
 * Testcase Example:  '[[1,0,1],[0,-2,3]]\n2'
 *
 * 给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
 * 
 * 题目数据保证总会存在一个数值和不超过 k 的矩形区域。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,0,1],[0,-2,3]], k = 2
 * 输出：2
 * 解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[2,2,-1]], k = 3
 * 输出：3
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
 * -10^5 
 * 
 * 
 * 
 * 
 * 进阶：如果行数远大于列数，该如何设计解决方案？
 * 
 */

// @lc code=start
class Solution
{
public:
    //const int INF INT_MAX;
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                //p = 0;
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        //vector<int> res;
        int z = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int t = i; t <= n; t++)
                {
                    for (int l = j; l <= m; l++)
                    {
                        int c = s[t][l] - s[i - 1][l] - s[t][j - 1] + s[i - 1][j - 1];
                        if (c <= k)
                        {
                            z = max(z, c);
                        }
                    }
                }
            }
        }
        return z;
    }
};
// @lc code=end
