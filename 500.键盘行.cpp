/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 *
 * https://leetcode-cn.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (70.51%)
 * Likes:    134
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 38.7K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。
 * 
 * 美式键盘 中：
 * 
 * 
 * 第一行由字符 "qwertyuiop" 组成。
 * 第二行由字符 "asdfghjkl" 组成。
 * 第三行由字符 "zxcvbnm" 组成。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：words = ["Hello","Alaska","Dad","Peace"]
 * 输出：["Alaska","Dad"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：words = ["omk"]
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：words = ["adsdf","sfd"]
 * 输出：["adsdf","sfd"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * words[i] 由英文字母（小写和大写字母）组成
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    bool judge(string s, string s1)
    {
        int q;
        // if (s1 == "zZxcvbnm")
        //     cout << s1<<endl;
        // if (s1 == "zZxcvbnm" && s == "zxcvbnm")
        //     p = i;
        if (s.find(s1[0]) != s.npos || s.find(tolower(s1[0])) != s.npos)
        {
            if (s1.size() == 1)
                return true;
            for (int j = 1; j < s1.size(); j++)
            {
                if (s1 == "zZxcvbnm" && s == "zxcvbnm")
                    q = j;
                if (s.find(s1[j]) == s.npos && s.find(tolower(s1[j])) == s.npos)
                {
                    break;
                }
                if (j == s1.size() - 1)
                {
                    cout << s1 << endl;
                    return true;
                }
            }
        }
        if (s1 == "zZxcvbnm" && s == "zxcvbnm")
            cout << " " << q;
        return false;
    }

public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> res;
        string a = "qwertyuiop";
        string b = "asdfghjkl";
        string c = "zxcvbnm";
        for (int i = 0; i < words.size(); i++)
        {
            if (judge(a, words[i]) || judge(b, words[i]) || judge(c, words[i]))
            {
                res.emplace_back(words[i]);
            }
        }
        return res;
    }
};
// @lc code=end
