/*
 * @lc app=leetcode.cn id=1399 lang=cpp
 *
 * [1399] 统计最大组的数目
 *
 * https://leetcode-cn.com/problems/count-largest-group/description/
 *
 * algorithms
 * Easy (66.47%)
 * Likes:    18
 * Dislikes: 0
 * Total Accepted:    8.6K
 * Total Submissions: 12.9K
 * Testcase Example:  '13\r'
 *
 * 给你一个整数 n 。请你先求出从 1 到 n 的每个整数 10 进制表示下的数位和（每一位上的数字相加），然后把数位和相等的数字放到同一个组中。
 * 
 * 请你统计每个组中的数字数目，并返回数字数目并列最多的组有多少个。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：n = 13
 * 输出：4
 * 解释：总共有 9 个组，将 1 到 13 按数位求和后这些组分别是：
 * [1,10]，[2,11]，[3,12]，[4,13]，[5]，[6]，[7]，[8]，[9]。总共有 4 个组拥有的数字并列最多。
 * 
 * 
 * 示例 2：
 * 
 * 输入：n = 2
 * 输出：2
 * 解释：总共有 2 个大小为 1 的组 [1]，[2]。
 * 
 * 
 * 示例 3：
 * 
 * 输入：n = 15
 * 输出：6
 * 
 * 
 * 示例 4：
 * 
 * 输入：n = 24
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution
{
private:
    int num(int n)
    {
        int s = 0;
        while (n)
        {
            s += n % 10;
            n /= 10;
        }
        return s;
    }

public:
    int countLargestGroup(int n)
    {
        vector<int> count(100, 0);
        for (int i = 1; i <= n; i++)
        {
            int t = num(i);
            count[t]++;
        }
        int max = *max_element(count.begin(), count.end());
        int res = 0;
        for (auto it : count)
        {
            if (it == max)
                res++;
        }
        return res;
    }
};
// @lc code=end
