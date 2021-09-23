/*
 * @lc app=leetcode.cn id=243 lang=cpp
 *
 * [243] 最短单词距离
 *
 * https://leetcode-cn.com/problems/shortest-word-distance/description/
 *
 * algorithms
 * Easy (65.60%)
 * Likes:    70
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 12.6K
 * Testcase Example:  '["practice", "makes", "perfect", "coding", "makes"]\n"coding"\n"practice"'
 *
 * 给定一个单词列表和两个单词 word1 和 word2，返回列表中这两个单词之间的最短距离。
 * 
 * 示例:
 * 假设 words = ["practice", "makes", "perfect", "coding", "makes"]
 * 
 * 输入: word1 = “coding”, word2 = “practice”
 * 输出: 3
 * 
 * 
 * 输入: word1 = "makes", word2 = "coding"
 * 输出: 1
 * 
 * 
 * 注意:
 * 你可以假设 word1 不等于 word2, 并且 word1 和 word2 都在列表里。
 * 
 */

// @lc code=start
class Solution
{
public:
    int shortestDistance(vector<string> &wordsDict, string word1, string word2)
    {
        //return abs(find(wordsDict.begin(), wordsDict.end(), word1) - find(wordsDict.begin(), wordsDict.end(), word2));
        int res = INT_MAX;
        for (int i = 0; i < wordsDict.size(); i++)
        {
            if (res == 1)
                return res;
            if (wordsDict[i] == word1)
                for (int j = i + 1; j < wordsDict.size(); j++)
                {
                    if (wordsDict[j] == word2)
                    {
                        res = min(res, j - i);
                    }
                }
            else if (wordsDict[i] == word2)
                for (int j = i + 1; j < wordsDict.size(); j++)
                {
                    if (wordsDict[j] == word1)
                    {
                        res = min(res, j - i);
                    }
                }
        }
        return res;
    }
};
// @lc code=end
