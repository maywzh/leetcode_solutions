import sun.awt.NullComponentPeer;

/*
 * @lc app=leetcode.cn id=21 lang=java
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
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null)
            return l2;
        if (l2 == null)
            return l1;
        ListNode p = l1, q = l2, head, rear;
        if (p.val < q.val) {
            head = p;
            p = p.next;
        }
        else {
            head = q;
            q = q.next;
        }
        rear = head;
        while (p != null && q != null) {
            if (p.val < q.val) {
                rear.next = p;
                while (p.val < q.val && p != null) {
                    rear = p;
                    p = p.next;
                }
            } else {
                rear.next = q;
                while (p.val >= q.val && q != null) {
                    rear = q;
                    q = q.next;
                }
            }
        }
        if (p == null)
            rear.next = q;
        if(q==null)
            rear.next = p;
        return head;
        
    }
}
// @lc code=end

