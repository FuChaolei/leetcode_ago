/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (45.67%)
 * Likes:    667
 * Dislikes: 0
 * Total Accepted:    276K
 * Total Submissions: 604.3K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = [1,2,3]
 * 输出：[1,2,4]
 * 解释：输入数组表示数字 123。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = [4,3,2,1]
 * 输出：[4,3,2,2]
 * 解释：输入数组表示数字 4321。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = [0]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int count = digits.size();
        while (count)
        {
            if (digits[count - 1] != 9)
            {
                digits[count - 1]++;
                break;
            }
            else
            {
                while (digits[count - 1] == 9 && count)
                {
                    if (count == 1)
                    {
                        digits[count - 1] = 0;
                        digits.insert(digits.begin(), 1);
                        goto zhe;
                    }
                    digits[count - 1] = 0;
                    count--;
                }
            }
        }
    zhe:
        return digits;
    }
};
// @lc code=end
