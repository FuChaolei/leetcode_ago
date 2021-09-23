/*
 * @lc app=leetcode.cn id=1880 lang=cpp
 *
 * [1880] 检查某单词是否等于两单词之和
 *
 * https://leetcode-cn.com/problems/check-if-word-equals-summation-of-two-words/description/
 *
 * algorithms
 * Easy (77.77%)
 * Likes:    4
 * Dislikes: 0
 * Total Accepted:    6K
 * Total Submissions: 7.7K
 * Testcase Example:  '"acb"\n"cba"\n"cdb"'
 *
 * 字母的 字母值 取决于字母在字母表中的位置，从 0 开始 计数。即，'a' -> 0、'b' -> 1、'c' -> 2，以此类推。
 * 
 * 对某个由小写字母组成的字符串 s 而言，其 数值 就等于将 s 中每个字母的 字母值 按顺序 连接 并 转换 成对应整数。
 * 
 * 
 * 例如，s = "acb" ，依次连接每个字母的字母值可以得到 "021" ，转换为整数得到 21 。
 * 
 * 
 * 给你三个字符串 firstWord、secondWord 和 targetWord ，每个字符串都由从 'a' 到 'j' （含 'a' 和 'j'
 * ）的小写英文字母组成。
 * 
 * 如果 firstWord 和 secondWord 的 数值之和 等于 targetWord 的数值，返回 true ；否则，返回 false
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：firstWord = "acb", secondWord = "cba", targetWord = "cdb"
 * 输出：true
 * 解释：
 * firstWord 的数值为 "acb" -> "021" -> 21
 * secondWord 的数值为 "cba" -> "210" -> 210
 * targetWord 的数值为 "cdb" -> "231" -> 231
 * 由于 21 + 210 == 231 ，返回 true
 * 
 * 
 * 示例 2：
 * 
 * 输入：firstWord = "aaa", secondWord = "a", targetWord = "aab"
 * 输出：false
 * 解释：
 * firstWord 的数值为 "aaa" -> "000" -> 0
 * secondWord 的数值为 "a" -> "0" -> 0
 * targetWord 的数值为 "aab" -> "001" -> 1
 * 由于 0 + 0 != 1 ，返回 false
 * 
 * 示例 3：
 * 
 * 输入：firstWord = "aaa", secondWord = "a", targetWord = "aaaa"
 * 输出：true
 * 解释：
 * firstWord 的数值为 "aaa" -> "000" -> 0
 * secondWord 的数值为 "a" -> "0" -> 0
 * targetWord 的数值为 "aaaa" -> "0000" -> 0
 * 由于 0 + 0 == 0 ，返回 true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= firstWord.length, secondWord.length, targetWord.length <= 8
 * firstWord、secondWord 和 targetWord 仅由从 'a' 到 'j' （含 'a' 和 'j' ）的小写英文字母组成。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        string s;
        for (int i = 0; i < max(firstWord.size(), secondWord.size()); i++)
        {
            if (i < firstWord.size() && i < secondWord.size())
                s += firstWord[firstWord.size() - 1 - i] + secondWord[secondWord.size() - 1 - i] - 'a';
            else if (firstWord.size() > secondWord.size())
                s += firstWord[firstWord.size() - 1 - i];
            else
            {
                s += secondWord[secondWord.size() - 1 - i];
            }
        }
        cout << s;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] > 'j')
            {
                if (i < s.size() - 1)
                    s[i + 1]++;
                if (i == s.size() - 1)
                {
                    s += "a";
                    s[i + 1]++;
                    s[i] -= 10;
                    break;
                }
                s[i] -= 10;
            }
        }
        // if (s[s.size() - 1] > 'j')
        // {
        //     s += "b";
        //     s[s.size() - 1]-=
        //     reverse(s.begin(), s.end());

        // }
        // else
        reverse(s.begin(), s.end());
        for (int i = 0; targetWord[i] == 'a' && targetWord.size() > 0; i++)
        {
            targetWord.erase(0, 1);
            i--;
        }
        for (int i = 0; s[i] == 'a' && s.size() > 0; i++)
        {
            s.erase(0, 1);
            i--;
        }
        cout << s << "  " << targetWord << endl;
        return s == targetWord;
    }
};
// @lc code=end
