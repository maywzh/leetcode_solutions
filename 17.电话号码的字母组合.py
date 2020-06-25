#
# @lc app=leetcode.cn id=17 lang=python3
#
# [17] 电话号码的字母组合
#


# @lc code=start
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letterMap = {
            '0': "",
            '1': "",
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }
        dlen = len(digits)
        ans = []

        def find(build, idx):
            if idx >= dlen:
                if (len(build) > 0):
                    ans.append(build)
                return
            digit = digits[idx]
            for c in letterMap[digit]:
                find(build + c, idx + 1)

        find("", 0)
        return ans


# @lc code=end
