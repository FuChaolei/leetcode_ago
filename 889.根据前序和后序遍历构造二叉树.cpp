/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.92%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    12.3K
 * Total Submissions: 18.1K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * 返回与给定的前序和后序遍历匹配的任何二叉树。
 * 
 * pre 和 post 遍历中的值是不同的正整数。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * 输出：[1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
 * 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    TreeNode *traversal(vector<int> pre, vector<int> post)
    {
        if (pre.size() == 0)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(pre[0]);
        if (pre.size() == 1)
        {
            return root;
        }
        //post.resize(post.size() - 1);
        int k;
        int count = post.size();
        for (int i = 0; i < count; i++)
        {
            if (post[i] == pre[1])
            {
                k = i;
                break;
            }
        }
        vector<int> leftPost(post.begin(), post.begin() + k + 1);
        vector<int> leftPre(pre.begin() + 1, pre.begin() + 1 + leftPost.size());
        vector<int> rightPre(pre.begin() + 1 + leftPost.size(), pre.end());
        vector<int> rightPost(post.begin() + k + 1, post.end() - 1);
        root->left = traversal(leftPre, leftPost);
        root->right = traversal(rightPre, rightPost);
        return root;
    }

public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        if (pre.size() == 0)
            return nullptr;
        return traversal(pre, post);
    }
};
// @lc code=end
