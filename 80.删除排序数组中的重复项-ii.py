#
# @lc app=leetcode.cn id=80 lang=python3
#
# [80] 删除排序数组中的重复项 II
#


# @lc code=start
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        slow = 0
        fast = 1
        apv = 1
        while (fast < n):
            if (nums[slow] != nums[fast]):
                apv = 1
                slow += 1
                nums[slow] = nums[fast]
            elif (apv > 0):
                apv -= 1
                slow += 1
                nums[slow] = nums[fast]
            fast+=1
        return slow + 1


# @lc code=end
