/*
 * @lc app=leetcode.cn id=812 lang=cpp
 *
 * [812] 最大三角形面积
 *
 * https://leetcode-cn.com/problems/largest-triangle-area/description/
 *
 * algorithms
 * Easy (62.83%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    9.9K
 * Total Submissions: 15.7K
 * Testcase Example:  '[[0,0],[0,1],[1,0],[0,2],[2,0]]'
 *
 * 给定包含多个点的集合，从其中取三个点组成三角形，返回能组成的最大三角形的面积。
 * 
 * 
 * 示例:
 * 输入: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
 * 输出: 2
 * 解释: 
 * 这五个点如下图所示。组成的橙色三角形是最大的，面积为2。
 * 
 * 
 * 
 * 
 * 注意: 
 * 
 * 
 * 3 <= points.length <= 50.
 * 不存在重复的点。
 * -50 <= points[i][j] <= 50.
 * 结果误差值在 10^-6 以内都认为是正确答案。
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    double area(vector<int> a, vector<int> b, vector<int> c)
    {
        double la = sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
        //cout << "la=" << la << endl;
        double lb = sqrt((b[0] - c[0]) * (b[0] - c[0]) + (b[1] - c[1]) * (b[1] - c[1]));
        //cout << "lb=" << lb << endl;
        double lc = sqrt((a[0] - c[0]) * (a[0] - c[0]) + (a[1] - c[1]) * (a[1] - c[1]));
        //cout << "lc=" << lc << endl;
        double p = (la + lb + lc) * 0.5;
        //cout << "p=" << p << endl;
        double res = sqrt(p * (p - la) * (p - lb) * (p - lc));
        //cout << "res=" << res << endl;
        return res;
    }

public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double res = 0;
        for (int i = 0; i < points.size() - 2; i++)
        {
            for (int j = i + 1; j < points.size() - 1; j++)
            {
                for (int k = j + 1; k < points.size(); k++)
                {
                    //cout << area(points[i], points[j], points[k]) << endl;
                    // cout << points[i][0] << " " << points[i][1] << endl;
                    // cout << points[j][0] << " " << points[j][1] << endl;
                    // cout << points[k][0] << " " << points[k][1] << endl;
                    res = max(res, area(points[i], points[j], points[k]));
                }
            }
        }
        return res;
    }
};
// @lc code=end
