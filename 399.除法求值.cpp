// @before-stub-for-debug-begin
/*
 * @lc app=leetcode.cn id=399 lang=cpp
 *
 * [399] 除法求值
 *
 * https://leetcode-cn.com/problems/evaluate-division/description/
 *
 * algorithms
 * Medium (59.16%)
 * Likes:    570
 * Dislikes: 0
 * Total Accepted:    39.1K
 * Total Submissions: 66.1K
 * Testcase Example:  '[["a","b"],["b","c"]]\n' +
  '[2.0,3.0]\n' +
  '[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]'
 *
 * 给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和
 * values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
 * 
 * 另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj
 * = ? 的结果作为答案。
 * 
 * 返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0
 * 替代这个答案。
 * 
 * 注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
 * [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
 * 输出：[6.00000,0.50000,-1.00000,1.00000,-1.00000]
 * 解释：
 * 条件：a / b = 2.0, b / c = 3.0
 * 问题：a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
 * 结果：[6.0, 0.5, -1.0, 1.0, -1.0 ]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
 * queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
 * 输出：[3.75000,0.40000,5.00000,0.20000]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：equations = [["a","b"]], values = [0.5], queries =
 * [["a","b"],["b","a"],["a","c"],["x","y"]]
 * 输出：[0.50000,2.00000,-1.00000,-1.00000]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * equations[i].length == 2
 * 1 i.length, Bi.length 
 * values.length == equations.length
 * 0.0 < values[i] 
 * 1 
 * queries[i].length == 2
 * 1 j.length, Dj.length 
 * Ai, Bi, Cj, Dj 由小写英文字母与数字组成
 * 
 * 
 */

// @lc code=start
//DFS
// class Solution
// {
// public:
//     vector<double> calcEquation(vector<vector<string>> &e, vector<double> &vi, vector<vector<string>> &q)
//     {
//         unordered_map<string, unordered_map<string, double>> g;
//         for (int i = 0; i < e.size(); i++)
//         {
//             string A = e[i][0];
//             string B = e[i][1];
//             double k = vi[i];
//             g[A][B] = k;
//             g[B][A] = 1.0 / k;
//         }
//         vector<double> ans;
//         for (auto it : q)
//         {
//             string A = it[0];
//             string B = it[1];
//             if (!g.count(A) || !g.count(B))
//             {
//                 ans.emplace_back(-1.0);
//                 continue;
//             }
//             multiset<string> v;
//             ans.emplace_back(dfs(A, B, g, v));
//         }
//         return ans;
//     }

// private:
//     double dfs(string A, string B, unordered_map<string, unordered_map<string, double>> &g, multiset<string> &v)
//     {
//         if (A == B)
//             return 1.0;
//         v.insert(A);
//         for (auto it : g[A])
//         {
//             string s = it.first;
//             if (v.count(s))
//             {
//                 continue;
//             }
//             double d = dfs(s, B, g, v);
//             if (d > 0)
//                 return g[A][s] * d;
//         }
//         return -1.0;
//     }
// };
// class Solution
// {
// public:
//     vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
//     {
//     }
// };
class Solution
{
public:
    vector<double> calcEquation(const vector<pair<string, string>> &equations, vector<double> &values, const vector<pair<string, string>> &queries)
    {
        // parents["A"] = {"B", 2.0} -> A = 2.0 * B
        // parents["B"] = {"C", 3.0} -> B = 3.0 * C
        unordered_map<string, pair<string, double>> parents;

        for (int i = 0; i < equations.size(); ++i)
        {
            const string &A = equations[i].first;
            const string &B = equations[i].second;
            const double k = values[i];
            // Neighter is in the forrest
            if (!parents.count(A) && !parents.count(B))
            {
                parents[A] = {B, k};
                parents[B] = {B, 1.0};
            }
            else if (!parents.count(A))
            {
                parents[A] = {B, k};
            }
            else if (!parents.count(B))
            {
                parents[B] = {A, 1.0 / k};
            }
            else
            {
                auto &rA = find(A, parents);
                auto &rB = find(B, parents);
                parents[rA.first] = {rB.first, k / rA.second * rB.second};
            }
        }

        vector<double> ans;
        for (const auto &pair : queries)
        {
            const string &X = pair.first;
            const string &Y = pair.second;
            if (!parents.count(X) || !parents.count(Y))
            {
                ans.push_back(-1.0);
                continue;
            }
            auto &rX = find(X, parents); // {rX, X / rX}
            auto &rY = find(Y, parents); // {rY, Y / rY}
            if (rX.first != rY.first)
                ans.push_back(-1.0);
            else // X / Y = (X / rX / (Y / rY))
                ans.push_back(rX.second / rY.second);
        }
        return ans;
    }

private:
    pair<string, double> &find(const string &C, unordered_map<string, pair<string, double>> &parents)
    {
        if (C != parents[C].first)
        {
            const auto &p = find(parents[C].first, parents);
            parents[C].first = p.first;
            parents[C].second *= p.second;
        }
        return parents[C];
    }
};
