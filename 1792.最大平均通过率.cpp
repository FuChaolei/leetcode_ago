/*
 * @lc app=leetcode.cn id=1792 lang=cpp
 *
 * [1792] 最大平均通过率
 *
 * https://leetcode-cn.com/problems/maximum-average-pass-ratio/description/
 *
 * algorithms
 * Medium (51.41%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    6.1K
 * Total Submissions: 11.9K
 * Testcase Example:  '[[1,2],[3,5],[2,2]]\n2'
 *
 * 一所学校里有一些班级，每个班级里有一些学生，现在每个班都会进行一场期末考试。给你一个二维数组 classes ，其中 classes[i] =
 * [passi, totali] ，表示你提前知道了第 i 个班级总共有 totali 个学生，其中只有 passi 个学生可以通过考试。
 * 
 * 给你一个整数 extraStudents ，表示额外有 extraStudents 个聪明的学生，他们 一定 能通过任何班级的期末考。你需要给这
 * extraStudents 个学生每人都安排一个班级，使得 所有 班级的 平均 通过率 最大 。
 * 
 * 一个班级的 通过率 等于这个班级通过考试的学生人数除以这个班级的总人数。平均通过率 是所有班级的通过率之和除以班级数目。
 * 
 * 请你返回在安排这 extraStudents 个学生去对应班级后的 最大 平均通过率。与标准答案误差范围在 10^-5
 * 以内的结果都会视为正确结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：classes = [[1,2],[3,5],[2,2]], extraStudents = 2
 * 输出：0.78333
 * 解释：你可以将额外的两个学生都安排到第一个班级，平均通过率为 (3/4 + 3/5 + 2/2) / 3 = 0.78333 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
 * 输出：0.53485
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * classes[i].length == 2
 * 1 i i 
 * 1 
 * 
 * 
 */

// @lc code=start
// class Solution
// {
// public:
//     double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
//     {
//         priority_queue<tuple<double, int, int>> q;

//         auto diff = [](int x, int y)
//         {
//             return (double)(x + 1) / (y + 1) - (double)x / y;
//         };

//         double ans = 0.;
//         for (const auto &c : classes)
//         {
//             int x = c[0], y = c[1];
//             ans += (double)x / y;
//             q.emplace(diff(x, y), x, y);
//         }
//         for (int _ = 0; _ < extraStudents; ++_)
//         {
//             auto [d, x, y] = q.top();
//             q.pop();
//             ans += d;
//             q.emplace(diff(x + 1, y + 1), x + 1, y + 1);
//         }
//         return ans / classes.size();
//     }
// };
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int e)
    {
        priority_queue<tuple<double, int, int>> q;
        auto diff = [](int x, int y)
        {
            return (x + 1) * 1.0 / (y + 1) - x * 1.0 / y;
        };
        double ans = 0;
        for (const auto &c : classes)
        {
            int x = c[0], y = c[1];
            ans += x * 1.0 / y;
            q.emplace(diff(x, y), c[0], c[1]);
        }
        for (int i = 0; i < e; i++)
        {
            auto [d, x, y] = q.top();
            q.pop();
            ans += d;
            q.emplace(diff(x + 1, y + 1), x + 1, y + 1);
        }
        return ans / classes.size();
    }
};
// @lc code=end
