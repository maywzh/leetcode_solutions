#
# @lc app=leetcode.cn id=78 lang=python3
#
# [78] 子集
#


# @lc code=start
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []

        def backtrace(curset, idx):
            if idx >= len(nums):
                return
            ans.append(curset.copy())
            for i in range(idx + 1, len(nums)):
                curset.append(nums[i])
                backtrace(curset, i)
                curset.pop()

        backtrace([], -1)
        return ans


# @lc code=end
