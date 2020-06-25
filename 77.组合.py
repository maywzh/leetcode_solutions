#
# @lc app=leetcode.cn id=77 lang=python3
#
# [77] 组合
#


# @lc code=start
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []

        def comp(curSet: Set[int]):
            if len(curSet) >= k:
                ans.append(list(curSet))
                return
            for i in range(1, n + 1):
                if not x in curSet:
                    comp(curSet.copy().add(i))

        comp({})


# @lc code=end
