/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        int end = 0, start = 0;
        vector<int> re;
        int map[26];
        for (int i = 0; i < S.size(); i++)
        {
            map[S[i] - 'a'] = i;
        }
        for (int i = 0; i < S.size(); i++)
        {
            end = max(end, map[S[i] - 'a']);
            if (i == end)
            {
                re.push_back(end - start + 1);
                start = end + 1;
                end = start;
            }
        }
        return re;
    }
};
// @lc code=end
