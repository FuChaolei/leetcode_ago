/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (55.52%)
 * Likes:    1386
 * Dislikes: 0
 * Total Accepted:    283.2K
 * Total Submissions: 509.9K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         vector<int> res;
//         for (int i = 0; i < lists.size(); i++)
//         {
//             while (lists[i])
//             {
//                 res.emplace_back(lists[i]->val);
//                 lists[i] = lists[i]->next;
//             }
//         }
//         sort(res.begin(), res.end());
//         ListNode *root = new ListNode(0);
//         ListNode *q = root;
//         for (int i = 0; i < res.size(); i++)
//         {
//             q->next = new ListNode(res[i]);
//             q = q->next;
//         }
//         return root->next;
//     }
// };
//小顶堆
// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         ListNode dummy(0);
//         ListNode *tail = &dummy;
//         auto cmp = [&](ListNode *a, ListNode *b)
//         {
//             return a->val > b->val;
//         };
//         priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> q(cmp);
//         for (auto list : lists)
//         {
//             if (list)
//                 q.push(list);
//         }
//         while (!q.empty())
//         {
//             tail->next = q.top();
//             q.pop();
//             tail = tail->next;
//             if (tail->next)
//                 q.push(tail->next);
//         }
//         return dummy.next;
//     }
// };
//归并
class Solution
{
private:
    ListNode *mergeTwo(ListNode *l1, ListNode *l2)
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
        tail->next = l1 == nullptr ? l2 : l1;
        return dummy.next;
    }
    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l > r)
            return nullptr;
        if (l == r)
            return lists[l];
        if (l + 1 == r)
            return mergeTwo(lists[l], lists[r]);
        int mid = l + (r - l) / 2;
        auto l1 = merge(lists, l, mid);
        auto l2 = merge(lists, mid + 1, r);
        return mergeTwo(l1, l2);
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge(lists, 0, lists.size() - 1);
    }
};
// Author: Huahua
// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         return merge(lists, 0, lists.size() - 1);
//     }

// private:
//     ListNode *merge(vector<ListNode *> &lists, int l, int r)
//     {
//         if (l > r)
//             return nullptr;
//         if (l == r)
//             return lists[l];
//         if (l + 1 == r)
//             return mergeTwoLists(lists[l], lists[r]);
//         int m = l + (r - l) / 2;
//         auto l1 = merge(lists, l, m);
//         auto l2 = merge(lists, m + 1, r);
//         return mergeTwoLists(l1, l2);
//     }
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         ListNode dummy(0);
//         ListNode *tail = &dummy;
//         while (l1 && l2)
//         {
//             if (l1->val > l2->val)
//                 swap(l1, l2);
//             tail->next = l1;
//             l1 = l1->next;
//             tail = tail->next;
//         }
//         if (l1)
//             tail->next = l1;
//         if (l2)
//             tail->next = l2;
//         return dummy.next;
//     }
// };
// @lc code=end
