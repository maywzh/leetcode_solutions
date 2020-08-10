#
# @lc app=leetcode.cn id=673 lang=python3
#
# [673] 最长递增子序列的个数
#


# @lc code=start
class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        dp = [1 for i in range(len(nums))]
        ans = [1 for i in range(len(nums))]
        maxv = 1
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        ans[i] = ans[j]
                    elif dp[i] == dp[j] + 1:
                        ans[i] += ans[j]
            maxv = max(maxv, dp[i])
        res = 0
        for i, v in enumerate(dp):
            if v == maxv:
                res += ans[i]
        return res


# @lc code=end
