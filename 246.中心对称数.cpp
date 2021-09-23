/*
 * @lc app=leetcode.cn id=246 lang=cpp
 *
 * [246] 中心对称数
 *
 * https://leetcode-cn.com/problems/strobogrammatic-number/description/
 *
 * algorithms
 * Easy (47.33%)
 * Likes:    31
 * Dislikes: 0
 * Total Accepted:    5.3K
 * Total Submissions: 11.3K
 * Testcase Example:  '"69"'
 *
 * 中心对称数是指一个数字在旋转了 180 度之后看起来依旧相同的数字（或者上下颠倒地看）。
 * 
 * 请写一个函数来判断该数字是否是中心对称数，其输入将会以一个字符串的形式来表达数字。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: num = "69"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: num = "88"
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: num = "962"
 * 输出: false
 * 
 * 示例 4：
 * 
 * 输入：num = "1"
 * 输出：true
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isStrobogrammatic(string num)
    {
        if (num.size() == 1 && (num[0] == '1' || num[0] == '8'))
            return true;
        else if (num.size() == 1)
        {
            return false;
        }
        int l = 0, r = num.size() - 1;
        while (l <= r)
        {
            if (num[r]=='2'||num[r]=='5'||num[r] == '3' || num[r] == '4' || num[r] == '7' || num[l] == '3' || num[l] == '4' || num[l] == '7'||num[l]=='2'||num[l]=='5')
                return false;
            else if ((num[r]=='2'&&num[l]=='2')||(num[r]=='5'&&num[l]=='5')||(num[l] == '1' && num[r] == '1') || (num[l] == '6' && num[r] == '9') || (num[l] == '9' && num[r] == '6') || (num[l] == '8' && num[r] == '8'))
            {
                l++;
                r--;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
