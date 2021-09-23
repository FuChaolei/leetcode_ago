/*
 * @lc app=leetcode.cn id=814 lang=cpp
 *
 * [814] 二叉树剪枝
 *
 * https://leetcode-cn.com/problems/binary-tree-pruning/description/
 *
 * algorithms
 * Medium (70.11%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 30K
 * Testcase Example:  '[1,null,0,0,1]'
 *
 * 给定二叉树根结点 root ，此外树的每个结点的值要么是 0，要么是 1。
 * 
 * 返回移除了所有不包含 1 的子树的原二叉树。
 * 
 * ( 节点 X 的子树为 X 本身，以及所有 X 的后代。)
 * 
 * 
 * 示例1:
 * 输入: [1,null,0,0,1]
 * 输出: [1,null,0,null,1]
 * ⁠
 * 解释: 
 * 只有红色节点满足条件“所有不包含 1 的子树”。
 * 右图为返回的答案。
 * 
 * 
 * 
 * 
 * 
 * 示例2:
 * 输入: [1,0,1,0,0,0,1]
 * 输出: [1,null,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例3:
 * 输入: [1,1,0,1,1,0,1,0]
 * 输出: [1,1,0,1,1,null,1]
 * 
 * 
 * 
 * 
 * 
 * 说明: 
 * 
 * 
 * 给定的二叉树最多有 200 个节点。
 * 每个节点的值只会为 0 或 1 。
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
class Solution
{
private:
    void pastOrder(TreeNode *&root)
    {
        if (root)
        {
            pastOrder(root->left);
            pastOrder(root->right);
            if (root->val == 0 && root->left == nullptr && root->right == nullptr)
            {
                root = nullptr;
            }
        }
    }

public:
    TreeNode *pruneTree(TreeNode *root)
    {
        pastOrder(root);
        return root;
    }
};
// @lc code=end
