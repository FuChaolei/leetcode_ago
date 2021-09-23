/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.78%)
 * Likes:    1216
 * Dislikes: 0
 * Total Accepted:    184K
 * Total Submissions: 275.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 * 
 * 进阶：
 * 
 * 
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5 
 * 
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
//     ListNode *sortList(ListNode *head)
//     {
//         vector<int> res;
//         ListNode *p = head, *q = head;
//         while (p)
//         {
//             res.emplace_back(p->val);
//             p = p->next;
//         }
//         sort(res.begin(), res.end());
//         int i = 0;
//         while (q)
//         {
//             q->val = res[i];
//             i++;
//             q = q->next;
//         }
//         return head;
//     }
// };
//优化
// class Solution
// {
// private:
//     ListNode *mergeSort(ListNode *l1, ListNode *l2)
//     {
//         ListNode res(0);
//         ListNode *tail = &res;
//         while (l1 && l2)
//         {
//             if (l1->val > l2->val)
//             {
//                 swap(l1, l2);
//             }
//             tail->next = l1;
//             l1 = l1->next;
//             tail = tail->next;
//         }
//         if (l1)
//             tail->next = l1;
//         if (l2)
//             tail->next = l2;
//         return res.next;
//     }

// public:
//     ListNode *sortList(ListNode *head)
//     {
//         if (!head || !head->next)
//             return head;
//         ListNode *slow = head;
//         ListNode *fast = head->next;
//         while (fast && fast->next)
//         {
//             slow = slow->next;
//             fast = fast->next;
//             fast = fast->next;
//         }
//         ListNode *mid = slow->next;
//         slow->next = nullptr;
//         return mergeSort(sortList(head), sortList(mid));
//     }
// };
//最优
class Solution
{
private:
    ListNode *split(ListNode *head, int n)
    {
        while (--n && head)
            head = head->next;
        ListNode *rest = head ? head->next : nullptr;
        if (head)
            head->next = nullptr;
        return rest;
    }
    pair<ListNode *, ListNode *> merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val > l2->val)
                swap(l1, l2);
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        while (tail->next)
        {
            tail = tail->next;
        }
        return {dummy.next, tail};
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        int len = 1;
        ListNode *cur = head;
        while (cur = cur->next)
            ++len;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *l;
        ListNode *r;
        ListNode *tail;
        for (int n = 1; n < len; n <<= 1)
        {
            cur = dummy.next;
            tail = &dummy;
            while (cur)
            {
                l = cur;
                r = split(l, n);
                cur = split(r, n);
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
