/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 *
 * https://leetcode-cn.com/problems/maximum-binary-tree/description/
 *
 * algorithms
 * Medium (81.16%)
 * Likes:    283
 * Dislikes: 0
 * Total Accepted:    44.5K
 * Total Submissions: 54.9K
 * Testcase Example:  '[3,2,1,6,0,5]'
 *
 * 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
 * 
 * 
 * 二叉树的根是数组 nums 中的最大元素。
 * 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
 * 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
 * 
 * 
 * 返回有给定数组 nums 构建的 最大二叉树 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [3,2,1,6,0,5]
 * 输出：[6,3,5,null,2,0,null,null,1]
 * 解释：递归调用如下所示：
 * - [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
 * ⁠   - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
 * ⁠       - 空数组，无子节点。
 * ⁠       - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
 * ⁠           - 空数组，无子节点。
 * ⁠           - 只有一个元素，所以子节点是一个值为 1 的节点。
 * ⁠   - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
 * ⁠       - 只有一个元素，所以子节点是一个值为 0 的节点。
 * ⁠       - 空数组，无子节点。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,1]
 * 输出：[3,null,2,null,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * nums 中的所有整数 互不相同
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
    TreeNode *traversal(vector<int> nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        int max_idx = max_element(nums.begin(), nums.end()) - nums.begin();
        //cout << max_idx;
        TreeNode *root = new TreeNode(nums[max_idx]);
        //cout << nums[max_idx];
        //cout << root->val;
        int k;
        int count = nums.size();
        //cout << count << endl;
        for (int i = 0; i < count; i++)
        {
            if (nums[i] == nums[max_idx])
            {
                k = i;
                //cout << k << endl;
                break;
            }
        }
        //cout << k;
        vector<int> left(nums.begin(), nums.begin() + k);
        // for (int i = 0; i < left.size(); i++)
        // {
        //     cout << left[i] << " ";
        // }

        vector<int> right(nums.begin() + k + 1, nums.end());
        root->left = traversal(left);
        root->right = traversal(right);
        return root;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &num)
    {
        return traversal(num);
    }
};
// @lc code=end
