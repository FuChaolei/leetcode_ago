/*
 * @lc app=leetcode.cn id=1154 lang=cpp
 *
 * [1154] 一年中的第几天
 *
 * https://leetcode-cn.com/problems/day-of-the-year/description/
 *
 * algorithms
 * Easy (56.10%)
 * Likes:    36
 * Dislikes: 0
 * Total Accepted:    12.8K
 * Total Submissions: 22.8K
 * Testcase Example:  '"2019-01-09"'
 *
 * 给你一个按 YYYY-MM-DD 格式表示日期的字符串 date，请你计算并返回该日期是当年的第几天。
 * 
 * 通常情况下，我们认为 1 月 1 日是每年的第 1 天，1 月 2 日是每年的第 2
 * 天，依此类推。每个月的天数与现行公元纪年法（格里高利历）一致。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：date = "2019-01-09"
 * 输出：9
 * 
 * 
 * 示例 2：
 * 
 * 输入：date = "2019-02-10"
 * 输出：41
 * 
 * 
 * 示例 3：
 * 
 * 输入：date = "2003-03-01"
 * 输出：60
 * 
 * 
 * 示例 4：
 * 
 * 输入：date = "2004-03-01"
 * 输出：61
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * date.length == 10
 * date[4] == date[7] == '-'，其他的 date[i] 都是数字。
 * date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日。
 * 
 * 
 */

// @lc code=start
class Solution
{
    vector<vector<int>> m{{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
    bool judge(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

public:
    int dayOfYear(string date)
    {
        int y = stoi(date.substr(0, 4));
        int mo = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8));
        cout << mo;
        int res = 0;
        int b = judge(y) ? 1 : 0;
        for (int i = 0; i < mo - 1; i++)
            res += m[b][i];
        res += d;
        return res;
    }
};
// @lc code=end
