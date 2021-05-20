/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode-cn.com/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (77.42%)
 * Likes:    485
 * Dislikes: 0
 * Total Accepted:    94.2K
 * Total Submissions: 121.6K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 * 
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h
 * 层，则该层包含 1~ 2^h 个节点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：0
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0 
 * 题目数据保证输入的树是 完全二叉树
 * 
 * 
 * 
 * 
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？
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
    //int res = 0;
    int k = 0;
    int countNodes(TreeNode *root)
    {
        // {
        //     if (root)
        //     {
        //         res++;
        //         countNodes(root->left);
        //         countNodes(root->right);
        //     }
        //     return res;
        if (root == nullptr)
            return 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        int leftHeight = 0, rightHeight = 0; // 这里初始为0是有目的的，为了下面求指数方便
        while (left)
        { // 求左子树深度
            left = left->left;
            leftHeight++;
        }
        //cout << leftHeight << endl;
        while (right)
        { // 求右子树深度
            right = right->right;
            rightHeight++;
        }
        if (leftHeight == rightHeight)
        {
            //cout << leftHeight << endl;
            int t = (2 << leftHeight) - 1;
            cout << (2 << leftHeight);
            return t; // 注意(2<<1) 相当于2^2，所以leftHeight初始为0
        }
        k = countNodes(root->left) + countNodes(root->right) + 1;
        //cout << k;
        // if (root->val == 1 && root->left->val == 2 && root->right == nullptr)
        //     return 0;
        return k;
    }
};
// @lc code=end
