/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
 *
 * https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/description/
 *
 * algorithms
 * Hard (43.89%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 18.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给你二叉树的根结点 root ，请你设计算法计算二叉树的 垂序遍历 序列。
 * 
 * 对位于 (row, col) 的每个结点而言，其左右子结点分别位于 (row + 1, col - 1) 和 (row + 1, col + 1)
 * 。树的根结点位于 (0, 0) 。
 * 
 * 二叉树的 垂序遍历
 * 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有结点，形成一个按出现位置从上到下排序的有序列表。如果同行同列上有多个结点，则按结点的值从小到大进行排序。
 * 
 * 返回二叉树的 垂序遍历 序列。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：[[9],[3,15],[20],[7]]
 * 解释：
 * 列 -1 ：只有结点 9 在此列中。
 * 列  0 ：只有结点 3 和 15 在此列中，按从上到下顺序。
 * 列  1 ：只有结点 20 在此列中。
 * 列  2 ：只有结点 7 在此列中。
 * 
 * 示例 2：
 * 
 * 
 * 输入：root = [1,2,3,4,5,6,7]
 * 输出：[[4],[2],[1,5,6],[3],[7]]
 * 解释：
 * 列 -2 ：只有结点 4 在此列中。
 * 列 -1 ：只有结点 2 在此列中。
 * 列  0 ：结点 1 、5 和 6 都在此列中。
 * ⁠         1 在上面，所以它出现在前面。
 * ⁠         5 和 6 位置都是 (2, 0) ，所以按值从小到大排序，5 在 6 的前面。
 * 列  1 ：只有结点 3 在此列中。
 * 列  2 ：只有结点 7 在此列中。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：root = [1,2,3,4,6,5,7]
 * 输出：[[4],[2],[1,5,6],[3],[7]]
 * 解释：
 * 这个示例实际上与示例 2 完全相同，只是结点 5 和 6 在树中的位置发生了交换。
 * 因为 5 和 6 的位置仍然相同，所以答案保持不变，仍然按值从小到大排序。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树中结点数目总数在范围 [1, 1000] 内
 * 0 
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        map<pair<int, int>, multiset<int>> mp;
        int minx = INT_MAX;
        int maxx = INT_MIN;
        traverse(root, minx, maxx, mp, 0, 0);
        vector<vector<int>> res(maxx - minx + 1);
        for (auto it : mp)
        {
            int i = it.first.second - minx;
            res[i].insert(end(res[i]), begin(it.second), end(it.second));
        }
        return res;
    }

private:
    void traverse(TreeNode *root, int &minx, int &maxx, map<pair<int, int>, multiset<int>> &mp, int y, int x)
    {
        if (!root)
            return;
        minx = min(minx, x);
        maxx = max(maxx, x);
        mp[make_pair(y, x)].insert(root->val);
        traverse(root->left, minx, maxx, mp, y + 1, x - 1);
        traverse(root->right, minx, maxx, mp, y + 1, x + 1);
    }
};
// class Solution
// {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode *root)
//     {
//         if (!root)
//             return {};
//         int min_x = INT_MAX;
//         int max_x = INT_MIN;
//         map<pair<int, int>, set<int>> h; // {y, x} -> {vals}
//         traverse(root, 0, 0, h, min_x, max_x);
//         vector<vector<int>> ans(max_x - min_x + 1);
//         for (const auto &m : h)
//         {
//             int x = m.first.second - min_x;
//             ans[x].insert(end(ans[x]), begin(m.second), end(m.second));
//         }
//         return ans;
//     }

// private:
//     void traverse(TreeNode *root, int x, int y,
//                   map<pair<int, int>, set<int>> &h,
//                   int &min_x,
//                   int &max_x)
//     {
//         if (!root)
//             return;
//         min_x = min(min_x, x);
//         max_x = max(max_x, x);
//         h[{y, x}].insert(root->val);
//         traverse(root->left, x - 1, y + 1, h, min_x, max_x);
//         traverse(root->right, x + 1, y + 1, h, min_x, max_x);
//     }
// };
// @lc code=end
