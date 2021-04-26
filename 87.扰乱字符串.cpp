/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 *
 * https://leetcode-cn.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (48.47%)
 * Likes:    219
 * Dislikes: 0
 * Total Accepted:    19.3K
 * Total Submissions: 40K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
 * 
 * 如果字符串的长度为 1 ，算法停止
 * 如果字符串的长度 > 1 ，执行下述步骤：
 * 
 * 在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y
 * 。
 * 随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y +
 * x 。
 * 在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
 * 
 * 
 * 
 * 
 * 给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s1 = "great", s2 = "rgeat"
 * 输出：true
 * 解释：s1 上可能发生的一种情形是：
 * "great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
 * "gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
 * "gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
 * "g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
 * "r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
 * "r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」
 * 算法终止，结果字符串和 s2 相同，都是 "rgeat"
 * 这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s1 = "abcde", s2 = "caebd"
 * 输出：false
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s1 = "a", s2 = "a"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * s1.length == s2.length
 * 1 
 * s1 和 s2 由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution
{
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2)
    {
        if (s1 == s2)
            return 1;
        int n = s1.size();
        if (n == 1)
            return 0; //只有一个字母又不相等，返回False。
        if (freq(s1) != freq(s2))
            return 0;
        for (int i = 1; i < n; i++)
        {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);

            bool one, two, three, four;
            string ID1 = hash(s11, s21), ID2 = hash(s12, s22);
            if (dp.count(ID1))
                one = dp[ID1];
            else
                one = isScramble(s11, s21);
            dp[ID1] = one;
            if (dp.count(ID2))
                two = dp[ID2];
            else
                two = isScramble(s12, s22);
            dp[ID2] = two;
            if (one && two)
                return 1;

            string s31 = s2.substr(0, n - i);
            string s32 = s2.substr(n - i);
            string ID3 = hash(s11, s32), ID4 = hash(s12, s31);
            if (dp.count(ID3))
                three = dp[ID3];
            else
                three = isScramble(s11, s32);
            dp[ID3] = three;
            if (dp.count(ID4))
                four = dp[ID4];
            else
                four = isScramble(s12, s31);
            dp[ID4] = four;
            if (three && four)
                return 1;
        }
        return 0;
    }

    string hash(string &s1, string &s2)
    {
        return s1 + '#' + s2;
    }

    vector<int> freq(string &s)
    {
        vector<int> f(26);
        for (auto c : s)
        {
            f[c - 'a']++;
        }
        return f;
    }
};
// @lc code=end
