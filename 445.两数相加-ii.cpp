/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (58.54%)
 * Likes:    403
 * Dislikes: 0
 * Total Accepted:    75.8K
 * Total Submissions: 129.3K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 
 * 
 * 示例1：
 * 
 * 
 * 
 * 
 * 输入：l1 = [7,2,4,3], l2 = [5,6,4]
 * 输出：[7,8,0,7]
 * 
 * 
 * 示例2：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[8,0,7]
 * 
 * 
 * 示例3：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表的长度范围为 [1, 100]
 * 0 
 * 输入数据保证链表代表的数字无前导 0
 * 
 * 
 * 
 * 
 * 进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
//暴力
// class Solution
// {
// public:
//     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
//     {
//         vector<int> l11;
//         vector<int> l22;
//         while (l1)
//         {
//             l11.emplace_back(l1->val);
//             l1 = l1->next;
//         }
//         while (l2)
//         {
//             l22.emplace_back(l2->val);
//             l2 = l2->next;
//         }
//         reverse(l11.begin(), l11.end());
//         reverse(l22.begin(), l22.end());
//         vector<int> res(max(l11.size(), l22.size()) + 1);
//         for (int i = 0; i < min(l11.size(), l22.size()); i++)
//         {
//             res[i] += l11[i];
//             res[i] += l22[i];
//             if (res[i] > 9)
//             {
//                 res[i] -= 10;
//                 res[i + 1]++;
//                 //cout << i << res[i + 1] << endl;
//             }
//         }
//         int lm = l11.size();
//         int ln = l22.size();
//         for (int i = min(l11.size(), l22.size()); i < res.size(); i++)
//         {
//             if (ln < lm && i < lm)
//             {
//                 res[i] += l11[i];
//                 if (res[i] > 9)
//                 {
//                     res[i] -= 10;
//                     res[i + 1]++;
//                 }
//             }
//             else if (ln >= lm && i < ln)
//             {
//                 res[i] += l22[i];
//                 if (res[i] > 9)
//                 {
//                     res[i] -= 10;
//                     res[i + 1]++;
//                 }
//             }
//         }
//         if (res[res.size() - 1] == 0)
//             res.pop_back();
//         for (int it : res)
//             cout << it << endl;
//         ListNode *root = new ListNode(0);
//         int o = res.size();
//         ListNode *l = root;
//         while (o--)
//         {
//             ListNode *w = new ListNode(res[o]);
//             l->next = w;
//             l = w;
//         }
//         return root->next;
//     }
// };
//栈存储
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1;
        stack<int> s2;
        while (l1)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode *head = nullptr;
        while (sum || !s1.empty() || !s2.empty())
        {
            if (!s1.empty() && !s2.empty())
            {
                sum += s1.top() + s2.top();
                s1.pop();
                s2.pop();
            }
            else if (!s1.empty())
            {
                sum += s1.top();
                s1.pop();
            }
            else if (!s2.empty())
            {
                sum += s2.top();
                s2.pop();
            }
            ListNode *n = new ListNode(sum % 10);
            sum /= 10;
            n->next = head;
            head = n;
        }
        return head;
    }
};
// @lc code=end
