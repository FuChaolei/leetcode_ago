/*
 * @lc app=leetcode.cn id=1720 lang=cpp
 *
 * [1720] 解码异或后的数组
 *
 * https://leetcode-cn.com/problems/decode-xored-array/description/
 *
 * algorithms
 * Easy (84.02%)
 * Likes:    65
 * Dislikes: 0
 * Total Accepted:    41.1K
 * Total Submissions: 47K
 * Testcase Example:  '[1,2,3]\n1'
 *
 * 未知 整数数组 arr 由 n 个非负整数组成。
 * 
 * 经编码后变为长度为 n - 1 的另一个整数数组 encoded ，其中 encoded[i] = arr[i] XOR arr[i + 1]
 * 。例如，arr = [1,0,2,1] 经编码后得到 encoded = [1,2,3] 。
 * 
 * 给你编码后的数组 encoded 和原数组 arr 的第一个元素 first（arr[0]）。
 * 
 * 请解码返回原数组 arr 。可以证明答案存在并且是唯一的。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：encoded = [1,2,3], first = 1
 * 输出：[1,0,2,1]
 * 解释：若 arr = [1,0,2,1] ，那么 first = 1 且 encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] =
 * [1,2,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：encoded = [6,2,7,3], first = 4
 * 输出：[4,2,0,7,4]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 
 * encoded.length == n - 1
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> res;
        res.emplace_back(first);
        int count = encoded.size();
        for (int i = 0; i < count; i++)
        {
            res.emplace_back(first ^ encoded[i]);
            first = res.back();
            cout << first;
        }
        return res;
    }
};
// @lc code=end
