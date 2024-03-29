/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 *
 * https://leetcode-cn.com/problems/score-after-flipping-matrix/description/
 *
 * algorithms
 * Medium (80.90%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    30.7K
 * Total Submissions: 37.9K
 * Testcase Example:  '[[0,0,1,1],[1,0,1,0],[1,1,0,0]]'
 *
 * 有一个二维矩阵 A 其中每个元素的值为 0 或 1 。
 * 
 * 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。
 * 
 * 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。
 * 
 * 返回尽可能高的分数。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
 * 输出：39
 * 解释：
 * 转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
 * 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= A.length <= 20
 * 1 <= A[0].length <= 20
 * A[i][j] 是 0 或 1
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int matrixScore(vector<vector<int>> &g)
    {
        int res = g.size() * (1 << (g[0].size() - 1));
        for (int j = 1; j < g[0].size(); j++)
        {
            int n = 0;
            for (int i = 0; i < g.size(); i++)
            {
                if (g[i][0] == 1)
                {
                    n += g[i][j];
                }
                else
                {
                    n += (1 - g[i][j]);
                }
            }
            int m = g.size();
            int t = max(n, m - n);
            res += t * (1 << (g[0].size() - j - 1));
        }
        return res;
    }
};
// @lc code=end
