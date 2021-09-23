/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (48.13%)
 * Likes:    1018
 * Dislikes: 0
 * Total Accepted:    260K
 * Total Submissions: 539.5K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
private:
    ListNode *reverse(ListNode *l)
    {
        if (l == nullptr)
        {
            return nullptr;
        }

        ListNode *h = new ListNode(0);
        h->next = l;
        ListNode *p = l->next, *q;
        l->next = nullptr;
        while (p != nullptr)
        {
            q = p->next;
            p->next = l;
            h->next = p;
            l = p;
            p = q;
        }
        return h->next;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *s = head;
        ListNode *f = head;
        while (f)
        {
            f = f->next;
            if (f == nullptr)
                break;
            else
            {
                f = f->next;
                if (f == nullptr)
                    break;
            }
            s = s->next;
        }
        ListNode *u = reverse(s->next);
        ListNode *w = u;
        ListNode *p = head;
        while (u && p && u->val == p->val)
        {
            u = u->next;
            p = p->next;
        }
        reverse(w);
        if (u)
        {
            return false;
        }
        else
        {
            return true;
        }
        return 0;
    }
};
// @lc code=end
