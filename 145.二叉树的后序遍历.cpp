/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (74.48%)
 * Likes:    584
 * Dislikes: 0
 * Total Accepted:    228.9K
 * Total Submissions: 307.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    // vector<int> res;
    // vector<int> postorderTraversal(TreeNode *root)
    // {
    //     if (root == nullptr)
    //         return res;
    //     postorderTraversal(root->left);
    //     postorderTraversal(root->right);
    //     res.emplace_back(root->val);
    //     return res;
    // }
    vector<int> postorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> res;
        if (root == nullptr)
            return res;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            res.emplace_back(node->val);
            if (node->left != nullptr)
                st.push(node->left);
            if (node->right != nullptr)
                st.push(node->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
