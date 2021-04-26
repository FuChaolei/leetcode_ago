/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    // long long n(ListNode *k)
    // {
    //     ListNode *h = k;
    //     long long t = 0, i = 0, l = 1;
    //     while (h)
    //     {
    //         t += h->val * l;
    //         l *= 10;
    //         h = h->next;
    //     }
    //     cout << t << endl;
    //     return t;
    // }
    // ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    // {
    //     long long m = n(l1) + n(l2);
    //     ListNode *h = new ListNode();
    //     //l3->next = NULL;
    //     // ListNode *r = l1;
    //     // while (r)
    //     // {
    //     //     cout << r->val << endl;
    //     //     r = r->next;
    //     // }

    //     //cout << m << endl;
    //     //ListNode *l3 = new ListNode(m % 10);
    //     ListNode *p = h, *r = h;
    //     if (m == 0)
    //         return l1;
    //     while (m != 0)
    //     {
    //         // h->next = new ListNode(m % 10);
    //         ListNode *r = new ListNode(m % 10);
    //         m /= 10;
    //         p->next = r;
    //         p = r;
    //         //r->next = h->next;

    //         //r = h->next;
    //         //h->next = new ListNode(m % 10);
    //         //h->next->next = r;
    //         // if (l3->next == nullptr)
    //         //cout << "1" << endl;
    //         //l3->next = r;
    //         //cout << h->next->val << endl;
    //     }
    //     // ListNode *r = l3;
    //     // int o = 5;
    //     // while (o)
    //     // {
    //     //     cout << r->val << endl;
    //     //     r = r->next;
    //     //     if (r == nullptr)
    //     //         r = r->next;
    //     //     o--;
    //     // }
    //     return h->next;
    // }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *h = head;
        int sum = 0;
        bool carry = false;
        while (l1 || l2)
        {
            sum = 0;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
                sum++;
            h->val = sum % 10;
            //h->next = new ListNode(sum % 10);
            if (l1 || l2)
            {
                h->next = new ListNode();
                h = h->next;
            }
            if (sum >= 10)
                carry = true;
            else
                carry = false;
            if (carry && l1 == nullptr && l2 == nullptr)
            {
                //h->next = new ListNode(1);
                h->next = new ListNode();
                h = h->next;
            }
        }
        if (carry)
        {
            //h->next = new ListNode(1);
            h->val = 1;
        }
        return head;
    }
};
// @lc code=end
