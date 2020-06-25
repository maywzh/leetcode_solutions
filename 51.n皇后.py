#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N皇后
#


# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        solution = [0 for i in range(n)]

        def valid_solution(t) -> bool:
            for i in range(t):
                if abs(solution[i] -
                       solution[t]) == abs(i -
                                           t) or solution[i] == solution[t]:
                    return False
            return True

        def trans_str(l):
            res = []
            for i in l:
                str = "".join(['.' if j != i else 'Q' for j in range(n)])
                res.append(str)
            return res

        def backtrack(t: int):
            if t >= n:
                ans.append(trans_str(solution))
                return
            for i in range(n):
                solution[t] = i
                if valid_solution(t):
                    backtrack(t + 1)

        backtrack(0)
        return ans


# @lc code=end
