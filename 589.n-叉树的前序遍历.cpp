/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (74.30%)
 * Likes:    165
 * Dislikes: 0
 * Total Accepted:    79.7K
 * Total Submissions: 107.3K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的 前序遍历 。
 * 
 * N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
 * 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 递归法很简单，你可以使用迭代法完成此题吗?
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：[1,3,5,6,2,4]
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * N 叉树的高度小于或等于 1000
 * 节点总数在范围 [0, 10^4] 内
 * 
 * 
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//递归
// class Solution
// {
// private:
//     vector<int> res;
//     void Preorder(Node *root)
//     {
//         if (root)
//         {
//             res.emplace_back(root->val);
//             for (int i = 0; i < root->children.size(); i++)
//                 Preorder(root->children[i]);
//         }
//     }

// public:
//     vector<int> preorder(Node *root)
//     {
//         Preorder(root);
//         return res;
//     }
// };
//迭代
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        stack<Node *> st;
        if (root)
            st.push(root);
        while (!st.empty())
        {
            res.emplace_back(st.top()->val);
            Node *tmp = st.top();
            st.pop();
            for (int i = tmp->children.size() - 1; i >= 0; i--)
            {
                if (tmp->children[i] != nullptr)
                    st.push(tmp->children[i]);
            }
        }
        return res;
    }
};
// @lc code=end
