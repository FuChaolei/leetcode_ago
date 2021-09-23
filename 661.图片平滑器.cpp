/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 *
 * https://leetcode-cn.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (55.46%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 25.1K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入)
 * ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * 输出:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
 * 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
 * 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵中的整数范围为 [0, 255]。
 * 矩阵的长和宽的范围均为 [1, 150]。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        vector<vector<int>> N;
        N = M;
        vector<int> x{0, 1, -1, 0, 1, 1, -1, -1};
        vector<int> y{1, 0, 0, -1, 1, -1, 1, -1};
        for (int i = 0; i < M.size(); i++)
        {
            for (int j = 0; j < M.back().size(); j++)
            {
                int sum = M[i][j];
                int count = 1;
                for (int k = 0; k < 8; k++)
                {
                    int xx = i + x[k];
                    int yy = j + y[k];
                    if (xx >= 0 && xx < M.size() && yy >= 0 && yy < M[0].size())
                    {
                        sum += M[xx][yy];
                        count++;
                    }
                }
                N[i][j] = sum / count;
                cout << N[i][j] << endl;
            }
        }
        return N;
    }
};
// @lc code=end
