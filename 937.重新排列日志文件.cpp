/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 *
 * https://leetcode-cn.com/problems/reorder-data-in-log-files/description/
 *
 * algorithms
 * Easy (58.86%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    10.7K
 * Total Submissions: 18.1K
 * Testcase Example:  '["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]'
 *
 * 给你一个日志数组 logs。每条日志都是以空格分隔的字串，其第一个字为字母与数字混合的 标识符 。
 * 
 * 有两种不同类型的日志：
 * 
 * 
 * 字母日志：除标识符之外，所有字均由小写字母组成
 * 数字日志：除标识符之外，所有字均由数字组成
 * 
 * 
 * 请按下述规则将日志重新排序：
 * 
 * 
 * 所有 字母日志 都排在 数字日志 之前。
 * 字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
 * 数字日志 应该保留原来的相对顺序。
 * 
 * 
 * 返回日志的最终顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3
 * art zero"]
 * 输出：["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3
 * 6"]
 * 解释：
 * 字母日志的内容都不同，所以顺序为 "art can", "art zero", "own kit dig" 。
 * 数字日志保留原来的相对顺序 "dig1 8 1 5 1", "dig2 3 6" 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act
 * zoo"]
 * 输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 3 
 * logs[i] 中，字与字之间都用 单个 空格分隔
 * 题目数据保证 logs[i] 都有一个标识符，并且在标识符之后至少存在一个字
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        stable_sort(logs.begin(), logs.end(), [&](string a, string b)
                    {
                        int t = 0, s = 0;
                        for (int i = 0; i < a.size(); i++)
                        {
                            if (a[i] == ' ')
                            {
                                t = i;
                                break;
                            }
                        }
                        for (int i = 0; i < b.size(); i++)
                        {
                            if (b[i] == ' ')
                            {
                                s = i;
                                break;
                            }
                        }
                        if (isdigit(a[t + 1]) && isalpha(b[s + 1]))
                            return false;
                        else if (isalpha(a[t + 1]) && isalpha(b[s + 1]))
                        {
                            if (a.substr(t + 1) != b.substr(s + 1))
                            {
                                return a.substr(t + 1) < b.substr(s + 1);
                            }
                            if (a.substr(t + 1) == b.substr(s + 1))
                                return a.substr(0, t + 1) < b.substr(0, s + 1);
                        }
                        else if (isalpha(a[t + 1]) && isdigit(b[s + 1]))
                            return true;
                        return false;
                    });
        return logs;
    }
};
// @lc code=end
