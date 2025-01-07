/*
 * @lc app=leetcode.cn id=3019 lang=cpp
 * @lcpr version=20004
 *
 * [3019] 按键变更的次数
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
    int countKeyChanges(string s) {
        if (s.empty())
            return 0; // 空字符串没有键位切换

        int result = 0;

        // Lambda 表达式：将字符切换大小写
        auto toggleCase = [](char c) -> char {
            if (c >= 'a' && c <= 'z') {
                return c - ('a' - 'A'); // 小写转大写
            } else if (c >= 'A' && c <= 'Z') {
                return c + ('a' - 'A'); // 大写转小写
            }
            return c; // 非字母字符返回自身
        };

        // 遍历字符串，检查是否发生按键切换
        for (size_t i = 1; i < s.size(); i++) {
            // 如果当前字符和前一个字符在大小写上有切换，则计数
            if (s[i] != s[i - 1] && s[i] != toggleCase(s[i - 1])) {
                result++;
            }
        }

        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "aAbBcC"\n
// @lcpr case=end

// @lcpr case=start
// "AaAaAaaA"\n
// @lcpr case=end

 */
