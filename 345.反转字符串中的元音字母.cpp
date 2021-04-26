/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 *
 * https://leetcode-cn.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (51.62%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    66.3K
 * Total Submissions: 128.4K
 * Testcase Example:  '"hello"'
 *
 * 编写一个函数，以字符串作为输入，反转该字符串中的元音字母。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入："hello"
 * 输出："holle"
 * 
 * 
 * 示例 2：
 * 
 * 输入："leetcode"
 * 输出："leotcede"
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 元音字母不包含字母 "y" 。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string reverseVowels(string s)
    {
        int count = s.size();
        string n;
        for (int i = 0; i < count; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                n += s[i];
            }
        }
        reverse(n.begin(), n.end());
        int m = 0;
        //cout << m << endl;
        for (int i = 0; i < count; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                //cout << n[m - 1] << endl;
                s[i] = n[m];
                m++;
            }
        }
        return s;
    }
};
// @lc code=end
