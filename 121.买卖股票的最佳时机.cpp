/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
//贪心
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int s = 0, k;
//         int n = prices.size();
//         k = prices[0];
//         for (int i = 1; i < n; i++)
//         {
//             k = min(k, prices[i]);
//             s = max(s, prices[i] - k);
//         }
//         return s;
//     }
// };
//动态规划
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         vector<int> res(prices.size(), 0);
//         res[0] = 0;
//         int minp = prices[0];
//         for (int i = 1; i < prices.size(); i++)
//         {
//             minp = min(minp, prices[i]);
//             res[i] = max(res[i - 1], prices[i] - minp);
//         }
//         return res[prices.size() - 1];
//     }
// };
//动态规划优化
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minp = prices[0];
        int maxp = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            minp = min(minp, prices[i]);
            maxp = max(maxp, prices[i] - minp);
        }
        return maxp;
    }
};
// @lc code=end
