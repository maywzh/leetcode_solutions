#
# @lc app=leetcode.cn id=919 lang=python
# @lcpr version=20002
#
# [919] 完全二叉树插入器
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class CBTInserter(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.q = deque()  # 使用 deque
        self.root = root
        temp = deque([root])  # 初始化 temp 队列
        while temp:
            node = temp.popleft()
            if node.left:
                temp.append(node.left)
            if node.right:
                temp.append(node.right)
            if node.left is None or node.right is None:
                self.q.append(node)

    def insert(self, val):
        """
        :type val: int
        :rtype: int
        """
        node = TreeNode(val)
        cur = self.q[0]  # 获取队列头部的节点但不移除
        if cur.left is None:
            cur.left = node
        else:
            cur.right = node
            self.q.popleft()  # 移除已填满左右孩子的节点
        self.q.append(node)
        return cur.val

    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.root

# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()
# @lc code=end
