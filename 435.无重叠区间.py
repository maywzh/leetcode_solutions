#
# @lc app=leetcode.cn id=435 lang=python3
#
# [435] 无重叠区间
#


# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        def secondEle(lis):
            return lis[1]

        intervals.sort(key=secondEle)
        pivot = 0
        i = 1
        ans = 1
        while i < len(intervals):
            if intervals[pivot][1] <= intervals[i][0]:
                pivot = i
            else:
                ans += 1
            i += 1
        return ans


# @lc code=end
