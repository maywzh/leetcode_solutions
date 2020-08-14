#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#


# @lc code=start
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        lennums = len(nums)
        left = 0
        right = lennums - 1
        while (left <= right):
            mid = left + int((right - left) / 2)
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            elif nums[mid] == target:
                right = mid - 1

        if left >= lennums or nums[left] != target:
            return [-1, -1]
        theleft = left
        left = 0
        right = lennums - 1

        while (left <= right):
            mid = left + int((right - left) / 2)
            if nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
            elif nums[mid] == target:
                left = mid + 1

        if right < 0 or nums[right] != target:
            return [-1, -1]
        return [theleft, right]


# @lc code=end
