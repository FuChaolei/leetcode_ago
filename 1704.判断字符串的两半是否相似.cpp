/*
 * @lc app=leetcode.cn id=1704 lang=cpp
 *
 * [1704] 判断字符串的两半是否相似
 *
 * https://leetcode-cn.com/problems/determine-if-string-halves-are-alike/description/
 *
 * algorithms
 * Easy (78.30%)
 * Likes:    2
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 14K
 * Testcase Example:  '"book"'
 *
 * 给你一个偶数长度的字符串 s 。将其拆分成长度相同的两半，前一半为 a ，后一半为 b 。
 * 
 * 两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。注意，s
 * 可能同时含有大写和小写字母。
 * 
 * 如果 a 和 b 相似，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：s = "book"
 * 输出：true
 * 解释：a = "bo" 且 b = "ok" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
 * 
 * 
 * 示例 2：
 * 
 * 输入：s = "textbook"
 * 输出：false
 * 解释：a = "text" 且 b = "book" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
 * 注意，元音 o 在 b 中出现两次，记为 2 个。
 * 
 * 
 * 示例 3：
 * 
 * 输入：s = "MerryChristmas"
 * 输出：false
 * 
 * 
 * 示例 4：
 * 
 * 输入：s = "AbCdEfGh"
 * 输出：true
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= s.length <= 1000
 * s.length 是偶数
 * s 由 大写和小写 字母组成
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        string s1 = s.substr(0, s.size() / 2);
        string s2 = s.substr(s.size() / 2, s.size() / 2);
        cout << s1 << " " << s2;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < s1.size(); i++)
            if (s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] == 'o' || s1[i] == 'u' || s1[i] == 'A' || s1[i] == 'E' || s1[i] == 'I' || s1[i] == 'O' || s1[i] == 'U')
                sum1++;
        for (int i = 0; i < s1.size(); i++)
            if (s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] == 'o' || s2[i] == 'u' || s2[i] == 'A' || s2[i] == 'E' || s2[i] == 'I' || s2[i] == 'O' || s2[i] == 'U')
                sum2++;
        return sum1 == sum2;
    }
};
// @lc code=end
