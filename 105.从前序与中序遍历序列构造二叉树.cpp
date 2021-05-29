/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.69%)
 * Likes:    1040
 * Dislikes: 0
 * Total Accepted:    195.3K
 * Total Submissions: 280.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *traversal(vector<int> preorder, vector<int> inorder)
    {
        if (inorder.size() == 0)
            return nullptr;
        int gen = preorder[0];
        TreeNode *root = new TreeNode(gen);
        if (inorder.size() == 1)
            return root;
        int count = inorder.size();
        int index;
        for (int i = 0; i < count; i++)
        {
            if (inorder[i] == gen)
            {
                index = i;
                break;
            }
        }
        vector<int> lpreorder(preorder.begin() + 1, preorder.begin() + index + 1);
        vector<int> linorder(inorder.begin(), inorder.begin() + index);
        vector<int> rpreorder(preorder.begin() + index + 1, preorder.end());
        vector<int> rinorder(inorder.begin() + index + 1, inorder.end());
        root->left = traversal(lpreorder, linorder);
        root->right = traversal(rpreorder, rinorder);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return traversal(preorder, inorder);
    }
};
// @lc code=end
