/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (67.36%)
 * Likes:    500
 * Dislikes: 0
 * Total Accepted:    114.7K
 * Total Submissions: 170.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
    void backtracking(TreeNode *root, vector<int> &path, vector<string> &res)
    {
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            int count = path.size();
            string spath;
            for (int i = 0; i < count - 1; i++)
            {
                spath += to_string(path[i]);
                spath += "->";
            }
            spath += to_string(path[path.size() - 1]);
            res.emplace_back(spath);
        }
        else
        {
            if (root->left)
            {
                //path.emplace_back(root->left->val);
                backtracking(root->left, path, res);
                path.pop_back();
            }
            if (root->right)
            {
                //path.emplace_back(root->right->val);
                backtracking(root->right, path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root == nullptr)
            return res;
        vector<int> path;
        backtracking(root, path, res);
        return res;
    }
};
// @lc code=end
