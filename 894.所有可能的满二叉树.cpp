/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
 *
 * https://leetcode-cn.com/problems/all-possible-full-binary-trees/description/
 *
 * algorithms
 * Medium (77.49%)
 * Likes:    208
 * Dislikes: 0
 * Total Accepted:    12.1K
 * Total Submissions: 15.6K
 * Testcase Example:  '7'
 *
 * 满二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。
 * 
 * 返回包含 N 个结点的所有可能满二叉树的列表。 答案的每个元素都是一个可能树的根结点。
 * 
 * 答案中每个树的每个结点都必须有 node.val=0。
 * 
 * 你可以按任何顺序返回树的最终列表。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：7
 * 
 * 输出：[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
 * 解释：
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 20
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
// public:
//     vector<TreeNode *> allPossibleFBT(int n)
//     {
//         vector<TreeNode *> dp;
//         //int f = 0;
//         if (n % 2 == 0)
//             return dp;
//         if (n == 1)
//         {
//             dp.emplace_back(new TreeNode(0));
//             return dp;
//         }
//         for (int i = 1; i <= n - 2; i += 2)
//         {
//             for (auto &l : allPossibleFBT(i))
//             {
//                 for (auto &r : allPossibleFBT(n - i - 1))
//                 {
//                     TreeNode *root = new TreeNode(0);
//                     root->left = l;
//                     root->right = r;
//                     dp.emplace_back(root);
//                 }
//             }
//         }
//         return dp;
//     }
// };
//记忆化数组
// class Solution
// {
// private:
//     static constexpr int max_n = 21;
//     array<vector<TreeNode *>, max_n> arr;
//     vector<TreeNode *> &Tree(int n)
//     {
//         if (arr[n].size() != 0)
//             return arr[n];
//         vector<TreeNode *> &ans = arr[n];
//         if (n % 2 == 0)
//             return ans = {};
//         if (n == 1)
//             return ans = {new TreeNode(0)};
//         for (int i = 1; i <= n - 2; i += 2)
//         {
//             for (auto &l : Tree(i))
//             {
//                 for (auto &r : Tree(n - i - 1))
//                 {
//                     TreeNode *root = new TreeNode(0);
//                     root->left = l;
//                     root->right = r;
//                     ans.emplace_back(root);
//                 }
//             }
//         }
//         return ans;
//     }

// public:
//     vector<TreeNode *> allPossibleFBT(int n)
//     {
//         return Tree(n);
//     }
// };
//动态规划
class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    {
        if (n % 2 == 0)
            return {};
        vector<vector<TreeNode *>> dp(n + 1);
        dp[1] = {new TreeNode(0)};
        for (int i = 3; i <= n; i += 2)
        {
            for (int j = 1; j < i; j += 2)
            {
                int k = i - j - 1;
                for (auto &l : dp[j])
                {
                    for (auto &r : dp[k])
                    {
                        TreeNode *root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        dp[i].emplace_back(root);
                    }
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
