/*
 * @lc app=leetcode.cn id=1360 lang=cpp
 *
 * [1360] 日期之间隔几天
 *
 * https://leetcode-cn.com/problems/number-of-days-between-two-dates/description/
 *
 * algorithms
 * Easy (50.08%)
 * Likes:    33
 * Dislikes: 0
 * Total Accepted:    7.8K
 * Total Submissions: 15.5K
 * Testcase Example:  '"2019-06-29"\n"2019-06-30"'
 *
 * 请你编写一个程序来计算两个日期之间隔了多少天。
 * 
 * 日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：date1 = "2019-06-29", date2 = "2019-06-30"
 * 输出：1
 * 
 * 
 * 示例 2：
 * 
 * 输入：date1 = "2020-01-15", date2 = "2019-12-31"
 * 输出：15
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给定的日期是 1971 年到 2100 年之间的有效日期。
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<vector<int>> m{{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    bool py(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }
    int to1970(int y, int m1, int d)
    {
        int y1 = 1970;
        int res = 0;
        while (y1 != y)
        {
            if (py(y1))
                res += 366;
            else
            {
                res += 365;
            }
            y1++;
        }
        int b = py(y) ? 1 : 0;
        for (int i = 0; i < m1 - 1; i++)
        {
            res += m[b][i];
        }
        res += d;
        cout << y << endl;
        return res;
    }

public:
    int daysBetweenDates(string date1, string date2)
    {
        int y1 = stoi(date1.substr(0, 4));
        int y2 = stoi(date2.substr(0, 4));
        int m1 = stoi(date1.substr(5, 2));
        int m2 = stoi(date2.substr(5, 2));
        int d1 = stoi(date1.substr(8, 2));
        int d2 = stoi(date2.substr(8, 2));
        return abs(to1970(y1, m1, d1) - to1970(y2, m2, d2));
    }
};
// @lc code=end
