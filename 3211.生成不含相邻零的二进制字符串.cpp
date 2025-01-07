/*
 * @lc app=leetcode.cn id=3211 lang=cpp
 * @lcpr version=20002
 *
 * [3211] 生成不含相邻零的二进制字符串
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
private:
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        function<void(string, int)> backtrace = [&](string s, int i) {
            if (i == n) {
                ans.emplace_back(s);
                return;
            }
            if (i == 0) {
                backtrace(s + '1', i + 1);
                backtrace(s + '0', i + 1);
            } else if (s[s.size() - 1] == '1') {
                backtrace(s + '0', i + 1);
                backtrace(s + '1', i + 1);
            } else if (s[s.size() - 1] == '0') {
                backtrace(s + '1', i + 1);
            }
        };
        backtrace("", 0);
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
