/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
bool help(string s, string t);
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        return help(s, t) && help(t, s);
    }
    bool help(string s, string t)
    {
        unordered_map<char, char> hash;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (hash.count(s[i]))
            {
                if (hash[s[i]] != t[i])
                    return false;
            }
            else
            {
                hash[s[i]] = t[i];
            }
        }
        return true;
    }
};
// @lc code=end
