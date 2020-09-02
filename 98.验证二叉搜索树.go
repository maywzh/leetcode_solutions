/*
 * @lc app=leetcode.cn id=98 lang=golang
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	rep := make([]int, 0)
	var rebuild func(*TreeNode)
	rebuild = func(node *TreeNode) {
		if node != nil {
			rebuild(node.Left)
			rep = append(rep, node.Val)
			rebuild(node.Right)
		}
	}
	rebuild(root)
	for i := 0; i < len(rep)-1; i++ {
		if rep[i] >= rep[i+1] {
			return false
		}
	}
	return true
}

// @lc code=end

