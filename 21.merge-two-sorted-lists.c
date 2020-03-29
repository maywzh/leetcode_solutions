/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (44.65%)
 * Total Accepted:    465.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    result->next = NULL;
    struct ListNode *r = result;
    while (p != NULL && q != NULL)
    {
        if (p->val <= q->val)
        {
            r->next = p;
            p = p->next;
        }
        else
        {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }
    if (p != NULL)
        r->next = p;
    if (q != NULL)
        r->next = q;
    return result->next;
}
