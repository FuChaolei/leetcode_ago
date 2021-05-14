/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 *
 * https://leetcode-cn.com/problems/reconstruct-itinerary/description/
 *
 * algorithms
 * Medium (44.52%)
 * Likes:    402
 * Dislikes: 0
 * Total Accepted:    32.4K
 * Total Submissions: 72.8K
 * Testcase Example:  '[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]'
 *
 * 给定一个机票的字符串二维数组 [from,
 * to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从
 * JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 如果存在多种有效的行程，请你按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"]
 * 相比就更小，排序更靠前
 * 所有的机场都用三个大写字母表示（机场代码）。
 * 假定所有机票至少存在一种合理的行程。
 * 所有的机票必须都用一次 且 只能用一次。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 * 输出：["JFK", "MUC", "LHR", "SFO", "SJC"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
 * 输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
 * 解释：另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。
 * 
 */

// @lc code=start
class Solution
{
private:
    vector<string> result;
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum)
    {
        if (result.size() == ticketNum + 1)
        {
            return true;
        }
        for (pair<const string, int> &target : targets[result[result.size() - 1]])
        {
            if (target.second > 0)
            { // 使用int字段来记录到达城市是否使用过了
                result.push_back(target.first);
                target.second--;
                if (backtracking(ticketNum))
                    return true;
                result.pop_back();
                target.second++;
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (const vector<string> &vec : tickets)
        {
            targets[vec[0]][vec[1]]++;
        }
        result.emplace_back("JFK");
        backtracking(tickets.size());
        return result;
    }
};

// @lc code=end
