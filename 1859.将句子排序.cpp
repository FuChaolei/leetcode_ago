/*
 * @lc app=leetcode.cn id=1859 lang=cpp
 *
 * [1859] 将句子排序
 *
 * https://leetcode-cn.com/problems/sorting-the-sentence/description/
 *
 * algorithms
 * Easy (77.95%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 6.6K
 * Testcase Example:  '"is2 sentence4 This1 a3"'
 *
 * 一个 句子 指的是一个序列的单词用单个空格连接起来，且开头和结尾没有任何空格。每个单词都只包含小写或大写英文字母。
 * 
 * 我们可以给一个句子添加 从 1 开始的单词位置索引 ，并且将句子中所有单词 打乱顺序 。
 * 
 * 
 * 比方说，句子 "This is a sentence" 可以被打乱顺序得到 "sentence4 a3 is2 This1" 或者 "is2
 * sentence4 This1 a3" 。
 * 
 * 
 * 给你一个 打乱顺序 的句子 s ，它包含的单词不超过 9 个，请你重新构造并得到原本顺序的句子。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "is2 sentence4 This1 a3"
 * 输出："This is a sentence"
 * 解释：将 s 中的单词按照初始位置排序，得到 "This1 is2 a3 sentence4" ，然后删除数字。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "Myself2 Me1 I4 and3"
 * 输出："Me Myself and I"
 * 解释：将 s 中的单词按照初始位置排序，得到 "Me1 Myself2 and3 I4" ，然后删除数字。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * s 只包含小写和大写英文字母、空格以及从 1 到 9 的数字。
 * s 中单词数目为 1 到 9 个。
 * s 中的单词由单个空格分隔。
 * s 不包含任何前导或者后缀空格。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string sortSentence(string s1)
    {
        map<int, string> mp;
        string res;
        vector<string> s;
        int start = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ' ')
            {
                s.emplace_back(s1.substr(start, i - start));
                start = i + 1;
            }
            if (i == s1.size() - 1)
            {
                s.emplace_back(s1.substr(start, i - start + 1));
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i][s[i].size() - 1]] = s[i];
        }
        for (auto it : mp)
        {
            res += it.second.substr(0, it.second.size() - 1);
            res += " ";
        }
        res = res.substr(0, res.size() - 1);
        return res;
    }
};
// @lc code=end
