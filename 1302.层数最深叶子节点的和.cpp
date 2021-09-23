/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 *
 * https://leetcode-cn.com/problems/deepest-leaves-sum/description/
 *
 * algorithms
 * Medium (81.53%)
 * Likes:    59
 * Dislikes: 0
 * Total Accepted:    17.9K
 * Total Submissions: 22K
 * Testcase Example:  '[1,2,3,4,5,null,6,7,null,null,null,null,8]'
 *
 * 给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
 * 输出：15
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
 * 输出：19
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中节点数目在范围 [1, 10^4] 之间。
 * 1 
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
// class Solution
// {
// public:
//     int deepestLeavesSum(TreeNode *root)
//     {
//         queue<TreeNode *> q;
//         if (root == nullptr)
//             return 0;
//         int res = 0;
//         q.push(root);
//         q.push(NULL);
//         while (!empty(q))
//         {
//             if (q.front() == NULL)
//             {
//                 q.pop();
//                 if (q.empty())
//                     return res;
//                 res = 0;
//                 q.push(NULL);
//                 continue;
//             }
//             res += q.front()->val;
//             if (q.front()->left)
//             {
//                 res = 0;
//                 q.push(q.front()->left);
//             }
//             if (q.front()->right)
//             {
//                 res = 0;
//                 q.push(q.front()->right);
//             }
//             q.pop();
//         }
//         return res;
//     }
// };
class Solution
{
private:
    int maxl = 0, res = 0;
    void dfs(TreeNode *root, int level)
    {
        if (root == nullptr)
            return;
        if (level == maxl)
            res += root->val;
        if (level > maxl)
        {
            res = root->val;
            maxl = level;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end
