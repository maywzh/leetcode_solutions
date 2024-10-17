#
# @lc app=leetcode.cn id=752 lang=python
# @lcpr version=20001
#
# [752] 打开转盘锁
#


# @lcpr-template-start

# @lcpr-template-end
# @lc code=start
class Solution(object):
    def openLock(self, deadends, target):
        """
        :type deadends: List[str]
        :type target: str
        :rtype: int
        """
        if "0000" in deadends:
            return -1

        def twist_lock(s, i, op):
            # 将第 i 位向上或向下拨动一次
            new_digit = (int(s[i]) + op) % 10
            return s[:i] + str(new_digit) + s[i+1:]
        from collections import deque
        q1 = deque(["0000"])
        q2 = deque([target])
        deads = set(deadends)
        step = 0
        visited = set()
        while q1 and q2:
            temp = set()
            if len(q1) > len(q2):
                q1, q2 = q2, q1
            for cur in q1:
                if cur in q2:
                    return step
                visited.add(cur)
                for j in range(4):
                    up = twist_lock(cur, j, 1)
                    if up not in visited and up not in deads:
                        temp.add(up)
                    down = twist_lock(cur, j, -1)
                    if down not in visited and down not in deads:
                        temp.add(down)
            step += 1
            q1 = q2
            q2 = temp
        return -1

# @lc code=end


#
# @lcpr case=start
# ["0201","0101","0102","1212","2002"]\n"0202"\n
# @lcpr case=end

# @lcpr case=start
# ["8888"]\n"0009"\n
# @lcpr case=end

# @lcpr case=start
# ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"\n
# @lcpr case=end

#
