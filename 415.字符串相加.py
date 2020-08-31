#
# @lc app=leetcode.cn id=415 lang=python3
#
# [415] 字符串相加
#


# @lc code=start
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        if not num1 and not num2:
            return 0
        if not num1:
            return int(num2)
        if not num2:
            return int(num1)
        i, j, p = len(num1) - 1, len(num2) - 1, 0
        ans = [0] * (max(len(num1), len(num2)) + 1)
        while i >= 0 and j >= 0:
            ans[p] += ord(num1[i]) - ord('0') + ord(num2[j]) - ord('0')
            ans[p + 1] += int(ans[p] / 10)
            ans[p] %= 10
            p += 1
            i -= 1
            j -= 1
        while i >= 0:
            ans[p] += ord(num1[i]) - ord('0')
            ans[p + 1] += int(ans[p] / 10)
            p += 1
            i -= 1
        while j >= 0:
            ans[p] += ord(num2[j]) - ord('0')
            ans[p + 1] += int(ans[p] / 10)
            p += 1
            j -= 1
        while ans[p] == 0:
            ans.pop()
            p -= 1
        return "".join(ans[::-1])


# @lc code=end
