/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (71.80%)
 * Likes:    505
 * Dislikes: 0
 * Total Accepted:    107.7K
 * Total Submissions: 149.9K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *traversal(vector<int> inorder, vector<int> postorder)
    {
        if (postorder.size() == 0)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postorder.size() - 1]);
        if (postorder.size() == 1)
            return root;
        int t = postorder[postorder.size() - 1];
        int k;
        int count = inorder.size();
        for (int i = 0; i < count; i++)
        {
            if (inorder[i] == t)
            {
                k = i;
                //cout << "k=" << k << endl;
                break;
            }
        }

        vector<int> Treeleftinorder(inorder.begin(), inorder.begin() + k);

        vector<int> Treerightinorder(inorder.begin() + k + 1, inorder.end());
        vector<int> Treeleftpost(postorder.begin(), postorder.begin() + k);
        vector<int> Treerightpost(postorder.begin() + k, postorder.end() - 1);
        //postorder.resize(postorder.size() - 1);
        root->left = traversal(Treeleftinorder, Treeleftpost);
        root->right = traversal(Treerightinorder, Treerightpost);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (postorder.size() == 0)
            return nullptr;
        return traversal(inorder, postorder);
    }
};
// @lc code=end
