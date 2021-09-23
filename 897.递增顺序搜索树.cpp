/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
 *
 * https://leetcode-cn.com/problems/increasing-order-search-tree/description/
 *
 * algorithms
 * Easy (74.69%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    58.8K
 * Total Submissions: 78.7K
 * Testcase Example:  '[5,3,6,2,4,null,8,1,null,null,null,7,9]'
 *
 * 给你一棵二叉搜索树，请你 按中序遍历
 * 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [5,1,7]
 * 输出：[1,null,5,null,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数的取值范围是 [1, 100]
 * 0 
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
    TreeNode *res = new TreeNode(-1);
    TreeNode *tmp = res;
    void Inorder(TreeNode *root)
    {
        if (root)
        {
            Inorder(root->left);
            tmp->right = root;
            tmp->right->left = nullptr;
            tmp = root;
            Inorder(root->right);
        }
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        Inorder(root);
        return res->right;
    }
};
// @lc code=end
