/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
 *
 * https://leetcode-cn.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (56.68%)
 * Likes:    927
 * Dislikes: 0
 * Total Accepted:    88.1K
 * Total Submissions: 155.4K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
 * 
 * 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * 输出：3
 * 解释：和等于 8 的路径有 3 条，如图所示。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 二叉树的节点个数的范围是 [0,1000]
 * -10^9  
 * -1000  
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
//递归
// class Solution
// {
// private:
//     int help(TreeNode *root, int t)
//     {
//         if (root == nullptr)
//             return 0;
//         t -= root->val;
//         return (t == 0 ? 1 : 0) + help(root->left, t) + help(root->right, t);
//     }

// public:
//     int pathSum(TreeNode *root, int &t)
//     {
//         if (!root)
//             return 0;
//         return pathSum(root->left, t) + pathSum(root->right, t) + help(root, t);
//     }
// };
//前缀和
class Solution
{
private:
    unordered_map<int, int> mp{{0, 1}};
    int res = 0;
    void pathSum(TreeNode *root, int cur, int &t)
    {
        if (root == nullptr)
            return;
        cur += root->val;
        res += mp[cur - t];
        mp[cur]++;
        pathSum(root->left, cur, t);
        pathSum(root->right, cur, t);
        mp[cur]--;
    }

public:
    int pathSum(TreeNode *root, int t)
    {
        if (!root)
            return 0;
        int cur = 0;
        pathSum(root, cur, t);
        return res;
    }
};
// @lc code=end
