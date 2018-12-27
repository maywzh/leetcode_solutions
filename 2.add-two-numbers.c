/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (29.89%)
 * Total Accepted:    688.3K
 * Total Submissions: 2.3M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int addone = 0, tmp;
    struct ListNode *rear;
    struct ListNode *l1head = l1;
    while (l1 != NULL && l2 != NULL)
    {
        tmp = l1->val + l2->val + addone;
        l1->val = tmp % 10;
        addone = tmp / 10;
        rear = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 != NULL)
    {
        while (l1 != NULL)
        {
            if (addone == 0)
                break;
            tmp = l1->val + addone;
            l1->val = tmp % 10;
            addone = tmp / 10;
            rear = l1;
            l1 = l1->next;
        }
    }
    else if (l2 != NULL)
    {
        rear->next = l2;
        while (l2 != NULL)
        {
            if (addone == 0)
                break;
            tmp = l2->val + addone;
            l2->val = tmp % 10;
            addone = tmp / 10;
            rear = l2;
            l2 = l2->next;
        }
    }
    if (addone > 0)
    {
        rear->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        rear->next->val = addone;
        rear->next->next = NULL;
    }
    return l1head;
}
