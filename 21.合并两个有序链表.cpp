/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (61.33%)
 * Likes:    991
 * Dislikes: 0
 * Total Accepted:    248.3K
 * Total Submissions: 401.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *head, *rear;
        ListNode *p = l1;
        ListNode *q = l2;
        if (p == NULL)
            return q;
        if (q == NULL)
            return p;
        if (p->val < q->val)
        {
            head = p;
            rear = head;
            p = p->next;
        }
        else
        {
            head = q;
            rear = head;
            q = q->next;
        }

        while (p != NULL && q != NULL)
        {
            if (p->val < q->val)
            {
                rear->next = p;
                while (p != NULL && p->val < q->val)
                {
                    rear = p;
                    p = p->next;
                }
                //rear -> next = q;
            }
            else
            {
                rear->next = q;
                while (q != NULL && p->val >= q->val)
                {
                    rear = q;
                    q = q->next;
                }
                //rear -> next =p;
            }
        }
        if (p == NULL)
            rear->next = q;
        if (q == NULL)
            rear->next = p;
        return head;
    }
};
// @lc code=end
