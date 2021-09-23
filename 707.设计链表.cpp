/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 *
 * https://leetcode-cn.com/problems/design-linked-list/description/
 *
 * algorithms
 * Medium (31.35%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    52.6K
 * Total Submissions: 167.5K
 * Testcase Example:  '["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]\n' +
  '[[],[1],[3],[1,2],[1],[1],[1]]'
 *
 * 设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
 * 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
 * 
 * 在链表类中实现这些功能：
 * 
 * 
 * get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
 * addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
 * addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
 * addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index
 * 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
 * deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
 * linkedList.get(1);            //返回2
 * linkedList.deleteAtIndex(1);  //现在链表是1-> 3
 * linkedList.get(1);            //返回3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 所有val值都在 [1, 1000] 之内。
 * 操作次数将在  [1, 1000] 之内。
 * 请不要使用内置的 LinkedList 库。
 * 
 * 
 */

// @lc code=start
class ListN
{
public:
    int val;
    ListN *next;
    ListN(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};
class MyLinkedList
{
private:
    ListN *head = nullptr;
    int len = 0;

public:
    /** Initialize your data structure here. */
    MyLinkedList()
    {
    }
    /** Get the value of the index-th ListN in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index < 0 || index > len - 1)
            return -1;
        ListN *cur = head;
        while (index)
        {
            index--;
            cur = cur->next;
        }
        return cur->val;
    }
    //     /** Add a ListN of value val before the first element of the linked list. After the insertion, the new ListN will be the first ListN of the linked list. */
    void addAtHead(int val)
    {
        ListN *cur = new ListN(val);
        cur->next = head;
        head = cur;
        len++;
    }
    //     /** Append a ListN of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        if (head == nullptr)
        {
            addAtHead(val);
            return;
        }
        ListN *cur = head;
        while (cur->next)
        {
            cur = cur->next;
        }
        cur->next = new ListN(val);
        cur->next->next = nullptr;
        len++;
    }
    /** Add a ListN of value val before the index-th ListN in the linked list. If index equals to the length of linked list, the ListN will be appended to the end of linked list. If index is greater than the length, the ListN will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index <= 0)
        {
            addAtHead(val);
            return;
        }
        if (index == len)
        {
            addAtTail(val);
            return;
        }
        if (index > len)
            return;
        ListN *cur = new ListN(val);
        ListN *pre = head;
        while (--index)
        {
            pre = pre->next;
        }
        cur->next = pre->next;
        pre->next = cur;
        len++;
    }
    /** Delete the index-th ListN in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= len)
        {
            return;
        }
        if (index == 0)
        {
            head = head->next;
            len--;
            return;
        }
        ListN *pre = head;
        while (--index)
        {
            pre = pre->next;
        }
        pre->next = pre->next->next;
        len--;
    }
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
