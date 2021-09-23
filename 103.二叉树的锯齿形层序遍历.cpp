// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem103.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (57.13%)
 * Likes:    495
 * Dislikes: 0
 * Total Accepted:    161.3K
 * Total Submissions: 282.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层序遍历如下：
 * 
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        vector<vector<int>> res;
        deque<TreeNode *> q;
        q.push_back(root);
        bool t = true;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> p;
            while (n)
            {
                if (t)
                {
                    p.emplace_back(q.front()->val);
                    TreeNode *cur = q.front();
                    q.pop_front();
                    if (cur->left)
                    {
                        q.push_back(cur->left);
                    }
                    if (cur->right)
                    {
                        q.push_back(cur->right);
                    }
                }
                else
                {
                    p.emplace_back(q.back()->val);
                    TreeNode *cur = q.back();
                    q.pop_back();
                    if (cur->right)
                    {
                        q.push_front(cur->right);
                    }
                    if (cur->left)
                    {
                        q.push_front(cur->left);
                    }
                }
                n--;
            }
            t = !t;
            res.emplace_back(p);
        }
        return res;
    }
};
// @lc code=end
