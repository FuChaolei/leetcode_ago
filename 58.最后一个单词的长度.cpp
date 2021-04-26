/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (34.35%)
 * Likes:    306
 * Dislikes: 0
 * Total Accepted:    177.2K
 * Total Submissions: 514.6K
 * Testcase Example:  '"Hello World"'
 *
 * 给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。
 * 
 * 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "Hello World"
 * 输出：5
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " "
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅有英文字母和空格 ' ' 组成
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int count = s.size();
        int num = 0;
        reverse(s.begin(), s.end());
        if (count == 0)
            return 0;
        for (int i = 0; i < count; i++)
        {
            if (i == 0 && s[0] == ' ')
            {
                for (int j = 1; j < count; j++)
                {
                    if (s[j] != ' ')
                    {
                        num++;
                    }
                    if (j == count - 1 || (num != 0 && s[j] == ' '))
                        return num;
                }
            }
            if (s[i] == ' ')
                break;
            num++;
        }
        return num;
    }
};
// @lc code=end
