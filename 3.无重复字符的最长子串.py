#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#


# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        ls = len(s)
        left = 0
        right = 1
        d = {}
        d[s[left]] = left
        maxl = [1 for i in range(ls)]
        while right < ls:
            if not s[right] in d.keys():
                maxl[right] = maxl[right - 1] + 1
                d[s[right]] = right
            else:
                while s[right] in d and left <= d[s[right]]:
                    del d[s[left]]
                    left += 1
                maxl[right] = right - left + 1
                d[s[right]] = right
            right += 1
        return max(maxl)

# @lc code=end
