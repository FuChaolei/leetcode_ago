/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        string res = "";
        unordered_map<char, int> mp;
        for (auto ch : s)
            mp[ch]++;
        while (!mp.empty())
        {
            int max = 0;
            char temp;
            for (unordered_map<char, int>::iterator it = mp.begin(); it != mp.end(); it++)
            {
                if (max < it->second)
                {
                    max = it->second;
                    temp = it->first;
                }
            }
            while (max--)
            {
                res += temp;
            }
            mp.erase(temp);
        }
        return res;
    }
};
// @lc code=end
