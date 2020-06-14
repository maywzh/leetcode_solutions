/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (62.81%)
 * Likes:    1106
 * Dislikes: 0
 * Total Accepted:    288.4K
 * Total Submissions: 459.2K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
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
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	if l1==nil {
		return l2
	}
	if l2==nil {
		return l1
	}
	var head *ListNode = &ListNode{}
	tail,a,b := head,l1,l2
	for a!=nil && b!=nil {
		if a.Val < b.Val {
			tail.Next = a
			a=a.Next
		} else {
			tail.Next = b
			b=b.Next
		}
		tail = tail.Next
	}
	if a!=nil {
		tail.Next=a
	} 
	if b!=nil{
		tail.Next=b
	}
	return head.Next
}
// @lc code=end

