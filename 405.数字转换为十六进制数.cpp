/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        string a;
        if (num == 0)
            return a + '0';

        unsigned t = num;
        char b[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        while (t != 0)
        {
            a = b[t % 16] + a;
            t /= 16;
        }
        return a;
    }
};
// @lc code=end
