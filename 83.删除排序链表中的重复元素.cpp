/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (53.72%)
 * Likes:    564
 * Dislikes: 0
 * Total Accepted:    246.5K
 * Total Submissions: 459.2K
 * Testcase Example:  '[1,1,2]'
 *
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除所有重复的元素，使每个元素 只出现一次 。
 * 
 * 返回同样按升序排列的结果链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,1,2]
 * 输出：[1,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,1,2,3,3]
 * 输出：[1,2,3]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点数目在范围 [0, 300] 内
 * -100 
 * 题目数据保证链表已经按升序排列
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
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        //k = 2;
        ListNode *p = head, *q = head->next;
        if (p->next == nullptr)
            return head;
        while (q->next)
        {
            //q = q->next;
            if (p->val == q->val)
            {
                //q->next = q->next->next;
                q = q->next;
                p->next = q;
            }
            else
            {
                p = q;
                q = q->next;
            }
        }
        if (p->val == q->val)
        {
            //q->next = q->next->next;
            q = q->next;
            p->next = q;
        }
        return head;
    }
};
// @lc code=end
