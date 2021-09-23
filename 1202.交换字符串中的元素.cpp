/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 *
 * https://leetcode-cn.com/problems/smallest-string-with-swaps/description/
 *
 * algorithms
 * Medium (50.21%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 51.9K
 * Testcase Example:  '"dcab"\n[[0,3],[1,2]]'
 *
 * 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0
 * 开始）。
 * 
 * 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。
 * 
 * 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入：s = "dcab", pairs = [[0,3],[1,2]]
 * 输出："bacd"
 * 解释： 
 * 交换 s[0] 和 s[3], s = "bcad"
 * 交换 s[1] 和 s[2], s = "bacd"
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
 * 输出："abcd"
 * 解释：
 * 交换 s[0] 和 s[3], s = "bcad"
 * 交换 s[0] 和 s[2], s = "acbd"
 * 交换 s[1] 和 s[2], s = "abcd"
 * 
 * 示例 3：
 * 
 * 输入：s = "cba", pairs = [[0,1],[1,2]]
 * 输出："abc"
 * 解释：
 * 交换 s[0] 和 s[1], s = "bca"
 * 交换 s[1] 和 s[2], s = "bac"
 * 交换 s[0] 和 s[1], s = "abc"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 10^5
 * 0 <= pairs.length <= 10^5
 * 0 <= pairs[i][0], pairs[i][1] < s.length
 * s 中只含有小写英文字母
 * 
 * 
 */
// @lc code=start
//DFS
// class Solution
// {
// public:
//     string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
//     {
//         vector<vector<int>> fList(s.size());
//         for (const auto &it : pairs)
//         {
//             fList[it[0]].emplace_back(it[1]);
//             fList[it[1]].emplace_back(it[0]);
//         }
//         unordered_set<int> seen;
//         vector<int> idx;
//         string temp;
//         function<void(int)> dfs = [&](int cur)
//         {
//             if (seen.count(cur))
//                 return;
//             seen.insert(cur);
//             idx.emplace_back(cur);
//             temp += s[cur];
//             for (auto it : fList[cur])
//             {
//                 dfs(it);
//             }
//         };
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (seen.count(i))
//                 continue;
//             temp.clear();
//             idx.clear();
//             dfs(i);
//             sort(begin(idx), end(idx));
//             sort(begin(temp), end(temp));
//             for (int j = 0; j < idx.size(); j++)
//             {
//                 s[idx[j]] = temp[j];
//             }
//         }
//         return s;
//     }
// };

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.size();
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x)
        {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        for (const auto &it : pairs)
        {
            p[find(it[0])] = find(it[1]);
        }
        vector<vector<int>> idx(n);
        vector<string> ids(n);
        for (int i = 0; i < n; i++)
        {
            int id = find(i);
            idx[id].emplace_back(i);
            ids[id].push_back(s[i]);
        }
        for (int i = 0; i < n; i++)
        {
            if (ids[i] != "")
            {
                sort(ids[i].begin(), ids[i].end());
                for (int k = 0; k < idx[i].size(); k++)
                {
                    s[idx[i][k]] = ids[i][k];
                }
            }
        }
        return s;
    }
};

//union
// class Solution
// {
// public:
//     string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
//     {
//         int n = s.length();
//         vector<int> p(n);
//         iota(begin(p), end(p), 0); // p = {0, 1, 2, ... n - 1}
//         function<int(int)> find = [&](int x)
//         {
//             return p[x] == x ? x : p[x] = find(p[x]);
//         };
//         for (const auto &e : pairs)
//         {
//             p[find(e[0])] = find(e[1]);
//         } // union
//         vector<vector<int>> idx(n);
//         vector<string> ss(n);
//         for (int i = 0; i < s.length(); ++i)
//         {
//             int id = find(i);
//             idx[id].push_back(i); // already sorted
//             ss[id].push_back(s[i]);
//         }
//         for (int i = 0; i < n; ++i)
//         {
//             if (ss[i] != "")
//             {
//                 sort(begin(ss[i]), end(ss[i]));
//                 for (int k = 0; k < idx[i].size(); ++k)
//                     s[idx[i][k]] = ss[i][k];
//             }
//         }
//         return s;
//     }
// };
//@lc code=end
