// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "commoncppproblem92.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (54.67%)
 * Likes:    989
 * Dislikes: 0
 * Total Accepted:    197.5K
 * Total Submissions: 361.3K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 给你单链表的头指针 head 和两个整数 left 和 right ，其中 left  。请你反转从位置 left 到位置 right 的链表节点，返回
 * 反转后的链表 。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], left = 2, right = 4
 * 输出：[1,4,3,2,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [5], left = 1, right = 1
 * 输出：[5]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目为 n
 * 1 
 * -500 
 * 1 
 * 
 * 
 * 
 * 
 * 进阶： 你可以使用一趟扫描完成反转吗？
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (right == left)
            return head;
        ListNode *dummy = new ListNode(0);
        ListNode *p = head;
        int f = 0;
        int l = left;
        while (--l && p)
        {
            //l--;
            f = 1;
            dummy = p;
            cout << dummy->val;
            p = p->next;
        }
        dummy->next = nullptr;
        ListNode *res = p;
        //cout << res->val;
        right = right - left + 1;
        while (right && p)
        {
            ListNode *s = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = s;
            right--;
        }
        res->next = p;
        if (f == 1)
            return head;
        else
            return dummy->next;
    }
};
// @lc code=end
