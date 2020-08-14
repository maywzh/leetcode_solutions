#
# @lc app=leetcode.cn id=452 lang=python3
#
# [452] 用最少数量的箭引爆气球
#


# @lc code=start
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        def secondEle(lis):
            return lis[1]

        if not points:
            return 0
        points.sort(key=secondEle)
        i = 0
        j = 1
        ans = 1
        while j < len(points):
            if points[i][1] > points[j][0]:
                i += 1
            else:
                ans += 1
            j += 1
        return ans


# @lc code=end
