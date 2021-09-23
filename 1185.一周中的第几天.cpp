/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 *
 * https://leetcode-cn.com/problems/day-of-the-week/description/
 *
 * algorithms
 * Easy (61.27%)
 * Likes:    35
 * Dislikes: 0
 * Total Accepted:    10.4K
 * Total Submissions: 17K
 * Testcase Example:  '31\n8\n2019'
 *
 * 给你一个日期，请你设计一个算法来判断它是对应一周中的哪一天。
 * 
 * 输入为三个整数：day、month 和 year，分别表示日、月、年。
 * 
 * 您返回的结果必须是这几个值中的一个 {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
 * "Friday", "Saturday"}。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：day = 31, month = 8, year = 2019
 * 输出："Saturday"
 * 
 * 
 * 示例 2：
 * 
 * 输入：day = 18, month = 7, year = 1999
 * 输出："Sunday"
 * 
 * 
 * 示例 3：
 * 
 * 输入：day = 15, month = 8, year = 1993
 * 输出："Sunday"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 给出的日期一定是在 1971 到 2100 年之间的有效日期。
 * 
 * 
 */

// @lc code=start
class Solution
{
    vector<string> week{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    vector<vector<int>> month{{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    bool isleapyear(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }
    int yearstill1970(int y, int m, int d)
    {
        int res = 0, y1 = 1970;
        while (y1 != y) //y > y1
        {
            if (isleapyear(y1))
            {
                res += 366;
            }
            else
            {
                res += 365;
            }
            y1++;
        }
        int b = isleapyear(y) ? 0 : 1;
        for (int i = 0; i < m - 1; i++)
        {
            res += month[b][i];
        }
        res += d;
        return res;
    }

public:
    string dayOfTheWeek(int day, int month, int year)
    {
        int day1 = yearstill1970(1999, 7, 18);
        int day2 = yearstill1970(year, month, day);
        int day3 = day2 - day1;
        return week[(day3 % 7 + 7) % 7];
    }
};
// @lc code=end
