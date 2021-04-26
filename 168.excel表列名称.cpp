/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        char k[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
        string s;
        while (columnNumber > 0)
        {
            char c;
            columnNumber--;
            c = k[columnNumber % 26];
            s = c + s;
            columnNumber /= 26;
        }
        return s;
    }
};
// @lc code=end
