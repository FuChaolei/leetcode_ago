/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 *
 * https://leetcode-cn.com/problems/monotone-increasing-digits/description/
 *
 * algorithms
 * Medium (50.14%)
 * Likes:    188
 * Dislikes: 0
 * Total Accepted:    36.8K
 * Total Submissions: 73.3K
 * Testcase Example:  '10'
 *
 * 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。
 * 
 * （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）
 * 
 * 示例 1:
 * 
 * 输入: N = 10
 * 输出: 9
 * 
 * 
 * 示例 2:
 * 
 * 输入: N = 1234
 * 输出: 1234
 * 
 * 
 * 示例 3:
 * 
 * 输入: N = 332
 * 输出: 299
 * 
 * 
 * 说明: N 是在 [0, 10^9] 范围内的一个整数。
 * 
 */

// @lc code=start
class Solution
{
    // private:
    //     bool diZeng(long long k)
    //     {
    //         int t = k % 10;
    //         int c;
    //         k /= 10;
    //         while (k)
    //         {
    //             c = k % 10;
    //             if (t < c)
    //                 return false;
    //             t = c;
    //             k /= 10;
    //         }
    //         return true;
    //     }

public:
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        int count = s.size();
        int flag = count;
        for (int i = s.size() - 1; i > 0; i--)
        {
            if (s[i] < s[i - 1])
            {
                flag = i - 1;
                s[i - 1]--;
            }
        }
        //int count = s.size();
        for (int i = flag + 1; i < count; i++)
        {
            s[i] = '9';
        }
        return stoi(s);
    }
};
// @lc code=end
