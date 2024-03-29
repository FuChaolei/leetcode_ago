/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 *
 * https://leetcode-cn.com/problems/relative-sort-array/description/
 *
 * algorithms
 * Easy (70.69%)
 * Likes:    178
 * Dislikes: 0
 * Total Accepted:    61.1K
 * Total Submissions: 86.4K
 * Testcase Example:  '[2,3,1,3,2,4,6,7,9,2,19]\n[2,1,4,3,9,6]'
 *
 * 给你两个数组，arr1 和 arr2，
 * 
 * 
 * arr2 中的元素各不相同
 * arr2 中的每个元素都出现在 arr1 中
 * 
 * 
 * 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1
 * 的末尾。
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * 输出：[2,2,2,1,4,3,3,9,6,7,19]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * arr2 中的元素 arr2[i] 各不相同
 * arr2 中的每个元素 arr2[i] 都出现在 arr1 中
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr2.size(); i++)
        {
            mp[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y)
             {
                 if (mp.count(x))
                 {
                     return mp.count(y) ? mp[x] < mp[y] : true;
                 }
                 else
                 {
                     return mp.count(y) ? false : x < y;
                 }
             });

        return arr1;
    }
};
// class Solution {
// public:
//     vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
//         unordered_map<int, int> rank;
//         for (int i = 0; i < arr2.size(); ++i) {
//             rank[arr2[i]] = i;
//         }
//         sort(arr1.begin(), arr1.end(), [&](int x, int y) {
//             if (rank.count(x)) {
//                 return rank.count(y) ? rank[x] < rank[y] : true;
//             }
//             else {
//                 return rank.count(y) ? false : x < y;
//             }
//         });
//         return arr1;
//     }
// };

// @lc code=end
