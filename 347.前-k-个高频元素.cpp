/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    bool static cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        vector<int> n;
        unordered_map<int, int> mp;
        int count = nums.size();
        for (int i = 0; i < count; i++)
        {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), cmp);

        while (k--)
            n.push_back(vec[k].first);

        return n;
    }
};
// @lc code=end
