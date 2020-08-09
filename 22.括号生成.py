#
# @lc app=leetcode.cn id=22 lang=python3
#
# [22] 括号生成
#


# @lc code=start
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        solu = ["" for i in range(2 * n)]

        def trySolu(l: int, r: int):
            if r > l:
                return
            elif r == l and l == n:
                ans.append("".join(solu))
                return
            if l < n:
                solu[l + r] = "("
                trySolu(l + 1, r)

            if r < l:
                solu[l + r] = ")"
                trySolu(l, r + 1)

        trySolu(0, 0)
        return ans


# @lc code=end
