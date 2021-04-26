/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
#include <stdlib.h>
class Solution
{
public:
    string convertToBase7(int num)
    {
        string a;
        int f = 0;
        if (num < 0)
        {
            f = 1;
            num *= -1;
        }
        if (num == 0)
            return a + '0';
        for (int i = 0; num != 0; i++)
        {
            int k = 0;
            k = num % 7;
            a.insert(0, 1, k + '0');
            num = num / 7;
        }
        if (f == 1)
            a.insert(0, 1, '-');
        return a;
    }
};
// @lc code=end
