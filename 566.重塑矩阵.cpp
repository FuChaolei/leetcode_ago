/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {

        int n = nums.size();
        int m = nums[0].size();
        if (m * n != r * c)
            return nums;
        int x = 0, y = 0;
        vector<vector<int>> a(r, vector<int>(c));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                a[x][y] = nums[i][j];
                y++;
                if (y > c - 1)
                {
                    x++;
                    y = 0;
                }
            }
        }
        return a;
    }
};
// @lc code=end
