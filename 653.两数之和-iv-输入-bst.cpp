/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (58.68%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    33.3K
 * Total Submissions: 56.7K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 * 
 * 案例 1:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 9
 * 
 * 输出: True
 * 
 * 
 * 
 * 
 * 案例 2:
 * 
 * 
 * 输入: 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * Target = 28
 * 
 * 输出: False
 * 
 * 
 * 
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
//暴力
class Solution
{
private:
    vector<int> res;
    void preOrder(TreeNode *root)
    {
        if (root)
        {
            preOrder(root->left);
            res.emplace_back(root->val);
            preOrder(root->right);
        }
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        preOrder(root);
        for (int i = 0; i < res.size(); i++)
        {
            for (int j = i + 1; j < res.size(); j++)
            {
                if (res[i] + res[j] == k)
                    return true;
            }
        }
        return false;
    }
};
//回溯
// class Solution {
// public:
//     bool findTarget(TreeNode* root, int k) {

//     }
// };
// @lc code=end
