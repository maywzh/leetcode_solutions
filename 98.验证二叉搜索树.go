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
	var chk func(*TreeNode, int, int) bool
	chk = func(node *TreeNode, morethan, lessthan int) bool {
		if node == nil {
			return true
		}
		if node.Val >= lessthan || node.Val <= morethan {
			return false
		}
		return chk(node.Left, morethan, node.Val) && chk(node.Right, node.Val, lessthan)
	}
	return chk(root, math.MinInt64, math.MaxInt64)
}

// @lc code=end

