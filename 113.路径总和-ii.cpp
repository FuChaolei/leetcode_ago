/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (62.16%)
 * Likes:    483
 * Dislikes: 0
 * Total Accepted:    139.6K
 * Total Submissions: 224.5K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
 * 
 * 叶子节点 是指没有子节点的节点。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：[[5,4,11,2],[5,8,4,5]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3], targetSum = 5
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2], targetSum = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点总数在范围 [0, 5000] 内
 * -1000 
 * -1000 
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
class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(TreeNode *root, int targetSum)
    {

        //int cur = targetSum;
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            res.emplace_back(path);
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
            return;
        if (root->left)
        {
            path.emplace_back(root->left->val);
            targetSum -= root->left->val;
            backtracking(root->left, targetSum);
            targetSum += root->left->val;
            path.pop_back();
        }
        if (root->right)
        {
            path.emplace_back(root->right->val);
            targetSum -= root->right->val;
            backtracking(root->right, targetSum);
            targetSum += root->right->val;
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return res;
        path.emplace_back(root->val);
        backtracking(root, targetSum - root->val);
        return res;
    }
};
// @lc code=end
