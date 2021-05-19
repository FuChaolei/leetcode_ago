/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-n-ary-tree/description/
 *
 * algorithms
 * Easy (72.10%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    50.7K
 * Total Submissions: 70.3K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，找到其最大深度。
 * 
 * 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
 * 
 * N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：5
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 树的深度不会超过 1000 。
 * 树的节点数目位于 [0, 10^4] 之间。
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

class Solution
{
public:
    int maxDepth(Node *root)
    {
        // if (root == nullptr)
        //     return 0;
        // int dep = 0;
        // int count = root->children.size();
        // for (int i = 0; i < count; i++)
        // {
        //     dep = max(dep, maxDepth(root->children[i]));
        // }
        // return dep + 1;
        //迭代法
        queue<Node *> q;
        if (root != nullptr)
            q.push(root);
        int res = 0;
        while (!q.empty())
        {
            int count = q.size();
            res++;
            //cout << count;
            for (int i = 0; i < count; i++)
            {
                Node *node = q.front();
                q.pop();

                int count1 = node->children.size();
                cout << count1;
                for (int j = 0; j < count1; j++)
                {
                    //cout << node->children[j]->val << " ";
                    q.push(node->children[j]);
                }
                cout << endl;
            }
        }
        return res;
    }
};
// @lc code=end
