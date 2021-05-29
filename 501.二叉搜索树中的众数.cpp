/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (50.64%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    54.4K
 * Total Submissions: 107.4K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 提示：如果众数超过1个，不需考虑输出顺序
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    vector<int> res;
    vector<int> r;
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        res.emplace_back(root->val);
        inorder(root->right);
        return;
    }

public:
    vector<int> findMode(TreeNode *root)
    {
        if (root == nullptr)
            return {};
        inorder(root);
        int count = res.size();
        //cout << count;
        int maxf = 0;
        int t = 0;
        int k = res[0];
        for (int i = 0; i < count; i++)
        {
            if (k == res[i])
            {
                t++;
                if (maxf < t)
                    maxf = t;
            }
            else
            {
                k = res[i];
                //i--;
                t = 1;
            }
        }
        cout << maxf;
        k = res[0];
        t = 0;
        for (int i = 0; i < count; i++)
        {
            if (k == res[i])
            {
                t++;
                if (maxf == t)
                    r.emplace_back(res[i]);
            }
            else
            {
                k = res[i];
                t = 1;
                if (maxf == t)
                    r.emplace_back(res[i]);
            }
        }
        return r;
    }
};
// @lc code=end
