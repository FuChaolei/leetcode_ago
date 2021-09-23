/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 *
 * https://leetcode-cn.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (45.75%)
 * Likes:    350
 * Dislikes: 0
 * Total Accepted:    74.5K
 * Total Submissions: 162.9K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。
 * 
 * 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。
 * 
 * 示例1:
 * 
 * 输入: pattern = "abba", str = "dog cat cat dog"
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:pattern = "abba", str = "dog cat cat fish"
 * 输出: false
 * 
 * 示例 3:
 * 
 * 输入: pattern = "aaaa", str = "dog cat cat dog"
 * 输出: false
 * 
 * 示例 4:
 * 
 * 输入: pattern = "abba", str = "dog dog dog dog"
 * 输出: false
 * 
 * 说明:
 * 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
 * 
 */

// @lc code=start
class Solution
{
public:
    bool wordPattern(string p, string s)
    {
        stringstream w(s);
        string temp;
        vector<string> res;
        while (w >> temp)
            res.emplace_back(temp);
        if (res.size() != p.size())
            return false;
        unordered_map<char, string> cmp;
        unordered_map<string, char> smp;
        int i = 0;
        for (auto c : p)
        {
            if (cmp.count(c) != 0 && cmp[c] != res[i])
                return false;
            if (smp.count(res[i]) != 0 && smp[res[i]] != c)
                return false;
            smp[res[i]] = c;
            cmp[c] = res[i];
            i++;
        }
        return true;
    }
};
// // =====================
// // stringstream 版本
// // =====================
// class Solution
// {
// public:
//     bool wordPattern(string pattern, string str)
//     {
//         unordered_map<string, char> str2ch;
//         unordered_map<char, string> ch2str;

//         // 切割字串，把單字放入 vector 中
//         stringstream ss(str);
//         string s;
//         vector<string> v;
//         while (getline(ss, s, ' '))
//         {
//             v.push_back(s);
//         }
//         if (pattern.size() != v.size())
//             return false;

//         int idx = 0;
//         for (char c : pattern)
//         {

//             // 檢查 1 對 1 的關係
//             string word = v[idx++];
//             if (idx == 4)
//             {
//                 cout << c << "  " << ch2str.count(c);
//             }
//             if (ch2str.count(c) != 0 && ch2str[c] != word)
//                 return false;
//             // if (str2ch.count(word) != 0 && str2ch[word] != c)
//             //     return false;
//             ch2str[c] = word;
//             //str2ch[word] = c;
//         }
//         return true;
//     }
// };
// @lc code=end
