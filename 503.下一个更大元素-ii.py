#
# @lc app=leetcode.cn id=503 lang=python3
#
# [503] 下一个更大元素 II
#


# @lc code=start
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        lennum = len(nums)
        ans = [-1 for i in range(lennum)]
        s = []
        for i in range(2*lennum-1,-1,-1):
            while s and s[-1] <= nums[i%lennum]:
                s.pop()
            if not s:
                ans[i%lennum] = -1
            else:
                ans[i%lennum] = s[-1]
            s.append(nums[i%lennum])
        return ans


# @lc code=end
