/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int s = 0, k;
        int n = (int)prices.size();
        k = prices[0];
        for (int i = 1; i < n; i++)
        {
            if (prices[i] < k)
                k = prices[i];
            else if (s < prices[i] - k)
                s = prices[i] - k;
        }
        return s;
    }
};
// @lc code=end
