/*
 * @lc app=leetcode.cn id=1232 lang=cpp
 *
 * [1232] 缀点成线
 *
 * https://leetcode-cn.com/problems/check-if-it-is-a-straight-line/description/
 *
 * algorithms
 * Easy (46.94%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    32.8K
 * Total Submissions: 69.8K
 * Testcase Example:  '[[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]'
 *
 * 在一个 XY 坐标系中有一些点，我们用数组 coordinates 来分别记录它们的坐标，其中 coordinates[i] = [x, y]
 * 表示横坐标为 x、纵坐标为 y 的点。
 * 
 * 请你来判断，这些点是否在该坐标系中属于同一条直线上，是则返回 true，否则请返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= coordinates.length <= 1000
 * coordinates[i].length == 2
 * -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
 * coordinates 中不含重复的点
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &c)
    {

        if (c.size() == 2)
            return true;
        for (int i = 0; i < c.size() - 2; i++)
        {
            int x1 = c[i][0], y1 = c[i][1], x2 = c[i + 1][0], y2 = c[i + 1][1], x3 = c[i + 2][0], y3 = c[i + 2][1];
            if ((y1 - y2) * (x2 - x3) != (x1 - x2) * (y2 - y3))
                return false;
        }
        return true;
    }
};
// @lc code=end
