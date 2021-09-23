/*
 * @lc app=leetcode.cn id=5818 lang=cpp
 *
 * [5818] Longest Common Subsequence Between Sorted Arrays
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence-between-sorted-arrays/description/
 *
 * algorithms
 * Medium (83.67%)
 * Likes:    1
 * Dislikes: 0
 * Total Accepted:    152
 * Total Submissions: 181
 * Testcase Example:  '[[1,3,4],[1,4,7,9]]'
 *
 * Given an array of integer arrays arrays where each arrays[i] is sorted in
 * strictly increasing order, return an integer array representing the longest
 * common subsequence between all the arrays.
 * 
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arrays = [[1,3,4],
 * [1,4,7,9]]
 * Output: [1,4]
 * Explanation: The longest subsequence which in the two arrays is [1,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arrays = [[2,3,6,8],
 * [1,2,3,5,6,7,10],
 * [2,3,4,6,9]]
 * Output: [2,3,6]
 * Explanation: The longest subsequence which in all of the three arrays is
 * [2,3,6].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arrays = [[1,2,3,4,5],
 * [6,7,8]]
 * Output: []
 * Explanation: There is no common subsequence between the two arrays.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arrays.length <= 100
 * 1 <= arrays[i].length <= 100
 * 1 <= arrays[i][j] <= 100
 * arrays[i] is sorted in strictly increasing order.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<int> longestCommomSubsequence(vector<vector<int>> &a)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < a[i].size(); j++)
            {
                mp[a[i][j]]++;
                if (mp[a[i][j]] == a.size())
                    res.emplace_back(a[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end
