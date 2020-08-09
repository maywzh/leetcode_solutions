#
# @lc app=leetcode.cn id=4 lang=python3
#
# [4] 寻找两个正序数组的中位数
#


# @lc code=start
class Solution:
    def findMedianSortedArrays(self, nums1: List[int],
                               nums2: List[int]) -> float:
        if len(nums2) == 0:
            return (nums1[len(nums1) >> 1] + nums1[(len(nums1) - 1) >> 1]) >> 1
        if len(nums1) == 0:
            return (nums1[len(nums2) >> 1] + nums1[(len(nums2) - 1) >> 1]) >> 1
        return 0

# @lc code=end
