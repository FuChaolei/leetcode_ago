/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
 *
 * https://leetcode-cn.com/problems/most-frequent-subtree-sum/description/
 *
 * algorithms
 * Medium (67.21%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 20.1K
 * Testcase Example:  '[5,2,-3]'
 *
 * 给你一个二叉树的根结点，请你找出出现次数最多的子树元素和。一个结点的「子树元素和」定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。
 * 
 * 你需要返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
 * 
 * 
 * 
 * 示例 1：
 * 输入:
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -3
 * 
 * 
 * 返回 [2, -3, 4]，所有的值均只出现一次，以任意顺序返回所有值。
 * 
 * 示例 2：
 * 输入：
 * 
 * ⁠ 5
 * ⁠/  \
 * 2   -5
 * 
 * 
 * 返回 [2]，只有 2 出现两次，-5 只出现 1 次。
 * 
 * 
 * 
 * 提示： 假设任意子树元素和均可以用 32 位有符号整数表示。
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        if (!root)
            return {};
        vector<int> res;
        unordered_map<int, int> mp;
        dfs(mp, root);
        int feq = 0;
        for (auto [k, v] : mp)
        {
            feq = max(feq, v);
        }
        for (auto [k, v] : mp)
            if (v == feq)
                res.emplace_back(k);
        return res;
    }

private:
    int dfs(unordered_map<int, int> &mp, TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = dfs(mp, root->left);
        int right = dfs(mp, root->right);
        int sum = root->val + left + right;
        mp[sum]++;
        return sum;
    }
};
// class Solution
// {
// public:
//     vector<int> findFrequentTreeSum(TreeNode *root)
//     {
//         unordered_map<int, int> freqs;
//         int max_freq = -1;
//         vector<int> ans;
//         (void)treeSum(root, freqs, max_freq, ans);
//         return ans;
//     }

// private:
//     int treeSum(TreeNode *root, unordered_map<int, int> &freqs, int &max_freq, vector<int> &ans)
//     {
//         if (!root)
//             return 0;
//         int sum = root->val +
//                   treeSum(root->left, freqs, max_freq, ans) +
//                   treeSum(root->right, freqs, max_freq, ans);
//         int freq = ++freqs[sum];
//         if (freq > max_freq)
//         {
//             max_freq = freq;
//             ans.clear();
//         }
//         if (freq == max_freq)
//             ans.push_back(sum);
//         return sum;
//     }
// };
// @lc code=end
