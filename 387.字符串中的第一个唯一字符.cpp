/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (52.24%)
 * Likes:    400
 * Dislikes: 0
 * Total Accepted:    187.6K
 * Total Submissions: 359.1K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 
 * 
 * 示例：
 * 
 * s = "leetcode"
 * 返回 0
 * 
 * s = "loveleetcode"
 * 返回 2
 * 
 * 
 * 
 * 
 * 提示：你可以假定该字符串只包含小写字母。
 * 
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};
// @lc code=end
