/*
 * @lc app=leetcode.cn id=884 lang=cpp
 *
 * [884] 两句话中的不常见单词
 *
 * https://leetcode-cn.com/problems/uncommon-words-from-two-sentences/description/
 *
 * algorithms
 * Easy (65.68%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    17.8K
 * Total Submissions: 27.1K
 * Testcase Example:  '"this apple is sweet"\n"this apple is sour"'
 *
 * 给定两个句子 A 和 B 。 （句子是一串由空格分隔的单词。每个单词仅由小写字母组成。）
 * 
 * 如果一个单词在其中一个句子中只出现一次，在另一个句子中却没有出现，那么这个单词就是不常见的。
 * 
 * 返回所有不常用单词的列表。
 * 
 * 您可以按任何顺序返回列表。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：A = "this apple is sweet", B = "this apple is sour"
 * 输出：["sweet","sour"]
 * 
 * 
 * 示例 2：
 * 
 * 输入：A = "apple apple", B = "banana"
 * 输出：["banana"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= A.length <= 200
 * 0 <= B.length <= 200
 * A 和 B 都只包含空格和小写字母。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {
        vector<string> res;
        vector<string> temp1;
        vector<string> temp2;
        int j = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ' ')
            {
                temp1.emplace_back(s1.substr(j, i - j));
                j = i + 1;
            }
            if (i == s1.size() - 1)
                temp1.emplace_back(s1.substr(j, i - j + 1));
        }
        j = 0;
        for (int i = 0; i < s2.size(); i++)
        {
            if (s2[i] == ' ')
            {
                temp2.emplace_back(s2.substr(j, i - j));
                j = i + 1;
            }
            if (i == s2.size() - 1)
                temp2.emplace_back(s2.substr(j, i - j + 1));
        }
        map<string, int> mp;
        for (int i = 0; i < temp1.size(); i++)
        {
            mp[temp1[i]]++;
        }
        for (int i = 0; i < temp2.size(); i++)
        {
            mp[temp2[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second == 1)
                res.emplace_back(it.first);
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<string> uncommonFromSentences(string A, string B) {
//         unordered_map<string, int> mymap;
//         A = A + " " + B;
//         istringstream words(A);
//         string w;
//         vector<string> ans;
//         while (words >> w) ++mymap[w];
//         for (auto m : mymap)
//             if (m.second == 1) ans.push_back(m.first);
//         return ans;
//     }
// };
// @lc code=end
