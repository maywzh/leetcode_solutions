#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#


# @lc code=start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        solu = [0 for i in range(n + 1)]
        if k > n:
            return ans
        elif k == n:
            ans.append([i for i in range(1, n + 1)])
            return ans

        def comp(pos, length):
            if k - length > n - pos:  # 剪枝
                return
            if length >= k:
                ans.append(solu[1:k + 1])
                return
            for i in range(pos + 1, n + 1):
                solu[length + 1] = i
                comp(i, length + 1)

        comp(0, 0)
        return ans


# @lc code=end
