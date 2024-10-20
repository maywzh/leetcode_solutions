/*
 * @lc app=leetcode.cn id=392 lang=cpp
 * @lcpr version=20002
 *
 * [392] 判断子序列
 */

// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.length() == 0)
            return true;
        if (t.length() == 0)
            return false;
        int slow = 0, fast = 0;
        while (fast < t.size()) {
            if (t[fast] == s[slow]) {
                slow++;
                if (slow == s.size())
                    return true;
            }
            fast++;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n"ahbgdc"\n
// @lcpr case=end

// @lcpr case=start
// "axc"\n"ahbgdc"\n
// @lcpr case=end

 */
