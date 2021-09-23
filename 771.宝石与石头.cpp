/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 *
 * https://leetcode-cn.com/problems/jewels-and-stones/description/
 *
 * algorithms
 * Easy (85.08%)
 * Likes:    647
 * Dislikes: 0
 * Total Accepted:    147.3K
 * Total Submissions: 173.1K
 * Testcase Example:  '"aA"\n"aAAbbbb"'
 *
 *  给定字符串J 代表石头中宝石的类型，和字符串 S代表你拥有的石头。 S 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头中有多少是宝石。
 * 
 * J 中的字母不重复，J 和 S中的所有字符都是字母。字母区分大小写，因此"a"和"A"是不同类型的石头。
 * 
 * 示例 1:
 * 
 * 输入: J = "aA", S = "aAAbbbb"
 * 输出: 3
 * 
 * 
 * 示例 2:
 * 
 * 输入: J = "z", S = "ZZ"
 * 输出: 0
 * 
 * 
 * 注意:
 * 
 * 
 * S 和 J 最多含有50个字母。
 * J 中的字符不重复。
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int res = 0;
        sort(jewels.begin(), jewels.end());
        sort(stones.begin(), stones.end());
        int i = 0, j = 0;
        while (j != jewels.size() && i != stones.size())
        {
            if (stones[i] == jewels[j])
            {
                cout << stones[i] << endl;
                res++;
                i++;
            }
            else if (stones[i] > jewels[j])
            {

                j++;
            }
            else
            {
                cout << stones[i] << " " << jewels[j];
                i++;
            }
        }
        return res;
    }
};
// @lc code=end
