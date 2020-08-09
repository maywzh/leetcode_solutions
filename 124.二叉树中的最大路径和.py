#
# @lc app=leetcode.cn id=124 lang=python3
#
# [124] 二叉树中的最大路径和
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def __init__(self):
        self.ans = float("-inf")

    def maxPathSum(self, root: TreeNode) -> int:
        def dfs(root: TreeNode) -> int:
            if root == None:
                return 0
            maxl = max(0, dfs(root.left))
            maxr = max(0, dfs(root.right))
            self.ans = max(self.ans, root.val + maxl + maxr)
            return max(maxl, maxr) + root.val

        dfs(root)
        return self.ans


# @lc code=end
