#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#

# @lc code=start
class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0:
             return 0
        lmax = height[0]
        rmax = height[len(height)-1]
        l = ans= 0
        r = len(height) - 1
        while l<=r:
            lmax = max(lmax, height[l])
            rmax = max(rmax, height[r])
            if lmax < rmax:
                ans += lmax - height[l]
                l+=1
            else:
                ans += rmax - height[r]
                r-=1
        return ans
# @lc code=end

