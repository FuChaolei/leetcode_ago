/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 *
 * https://leetcode-cn.com/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (67.43%)
 * Likes:    811
 * Dislikes: 0
 * Total Accepted:    181.3K
 * Total Submissions: 268.8K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * 请根据每日 气温 列表，重新生成一个列表。对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0
 * 来代替。
 * 
 * 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4,
 * 2, 1, 1, 0, 0]。
 * 
 * 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 * 
 */

// @lc code=start
//暴力超时
// class Solution
// {
// public:
//     vector<int> dailyTemperatures(vector<int> &t)
//     {
//         vector<int> res(t.size());
//         for (int i = 0; i < t.size(); i++)
//         {
//             for (int j = i + 1; j < t.size(); j++)
//             {
//                 if(t[i])
//                 if (t[j] > t[i])
//                 {
//                     res[i] = j - i;
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
//单调栈
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &t)
    {
        stack<int> st;
        vector<int> res(t.size());
        st.push(0);
        for (int i = 1; i < t.size(); i++)
        {
            while (!st.empty() && t[st.top()] < t[i])
            {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
// @lc code=end
