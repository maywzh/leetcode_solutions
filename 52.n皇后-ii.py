#
# @lc app=leetcode.cn id=52 lang=python3
#
# [52] N皇后 II
#


# @lc code=start
class Solution:
    def totalNQueens(self, n: int) -> int:
        ans = 0
        solu = [0] * n

        def valid_solu(t) -> bool:
            for i in range(t):
                if abs(solu[i] - solu[t]) == abs(i - t) or solu[i] == solu[t]:
                    return False
            return True

        def backtrack(t: int):
            if t >= n:
                nonlocal ans
                ans += 1
                return
            for i in range(n):
                solu[t] = i
                if valid_solu(t):
                    backtrack(t + 1)

        backtrack(0)
        return ans


# @lc code=end
