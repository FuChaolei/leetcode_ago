/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 *
 * https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (69.87%)
 * Likes:    115
 * Dislikes: 0
 * Total Accepted:    17.9K
 * Total Submissions: 25.6K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。例如，如果路径为 0 -> 1 -> 1
 * -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
 * 
 * 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
 * 
 * 返回这些数字之和。题目数据保证答案是一个 32 位 整数。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,0,1,0,1,0,1]
 * 输出：22
 * 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [0]
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
 * 示例 4：
 * 
 * 
 * 输入：root = [1,1]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中的结点数介于 1 和 1000 之间。
 * Node.val 为 0 或 1 。
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
    int res = 0;
    int temp = 0;
    void backtracking(TreeNode *root)
    {
        temp = temp * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr)
            res += temp;
        if (root->left)
        {
            int temp2 = temp;
            backtracking(root->left);
            temp = temp2;
        }
        if (root->right)
        {
            int temp2 = temp;
            backtracking(root->right);
            temp = temp2;
        }
    }

public:
    int sumRootToLeaf(TreeNode *root)
    {
        backtracking(root);
        return res;
    }
};
// @lc code=end
