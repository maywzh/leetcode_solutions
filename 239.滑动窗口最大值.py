#
# @lc app=leetcode.cn id=239 lang=python3
#
# [239] 滑动窗口最大值
#
from collections import deque


# @lc code=start
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if n * k == 0:
            return []
        if k == 1:
            return nums

        def clean_deque(i):
            if dq and dq[0] == i - k:
                dq.popleft()
            while dq and nums[i] > nums[dq[-1]]:
                dq.pop()

        res = []
        dq = deque()
        for i in range(n):
            clean_deque(i)
            dq.append(i)
            if (i >= k - 1):
                res.append(nums[dq[0]])
        return res


# @lc code=end
