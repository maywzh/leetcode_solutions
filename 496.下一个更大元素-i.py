#
# @lc app=leetcode.cn id=496 lang=python3
#
# [496] 下一个更大元素 I
#


# @lc code=start
class Solution:
    def nextGreaterElement(self, nums1: List[int],
                           nums2: List[int]) -> List[int]:
        s = []
        d = {}
        for i in range(len(nums2) - 1, -1, -1):
            while s and s[-1] < nums2[i]:
                s.pop()
            if not s:
                d[nums2[i]] = -1
            else:
                d[nums2[i]] = s[-1]
            s.append(nums2[i])
        return [d[i] for i in nums1]


# @lc code=end
