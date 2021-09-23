/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (72.45%)
 * Likes:    850
 * Dislikes: 0
 * Total Accepted:    152.2K
 * Total Submissions: 210K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 * 
 * 
 * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 * 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [1,2,5,3,4,null,6]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中结点数在范围 [0, 2000] 内
 * -100 
 * 
 * 
 * 
 * 
 * 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
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
//     TreeNode *h = new TreeNode(0);
//     TreeNode *p = h;
//     void preorder(TreeNode *root)
//     {
//         if (root)
//         {
//             p->right = new TreeNode(root->val);
//             p = p->right;
//             preorder(root->left);
//             preorder(root->right);
//         }
//     }
//     void flatten(TreeNode *root)
//     {
//         if (root == nullptr)
//             return;
//         preorder(root);
//         TreeNode *ans = root;
//         while (h->right->right)
//         {
//             ans->left = nullptr;
//             ans->right = h->right->right;
//             ans = ans->right;
//             h = h->right;
//         }
//     }
// };
// class Solution
// {
// private:
//     void preOrder(TreeNode *root, vector<TreeNode *> &l)
//     {
//         if (root)
//         {
//             l.emplace_back(root);
//             preOrder(root->left, l);
//             preOrder(root->right, l);
//         }
//     }

// public:
//     void flatten(TreeNode *root)
//     {
//         vector<TreeNode *> l;
//         preOrder(root, l);

//         for (int i = 1; i < l.size(); i++)
//         {
//             TreeNode *pre = l[i - 1];
//             pre->right = l[i];
//             pre->left = nullptr;
//         }
//     }
// };
//优化
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        TreeNode *p = root;
        while (p)
        {
            TreeNode *l = p->left;
            TreeNode *r = p->right;
            if (l)
            {
                p->left = nullptr;
                p->right = l;
                while (l->right)
                {
                    l = l->right;
                }
                l->right = r;
            }
            p = p->right;
        }
    }
};
// @lc code=end
