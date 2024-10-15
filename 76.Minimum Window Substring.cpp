/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=20001
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        auto left = 0, right = 0;
        unordered_map<const char, int> cover;
        unordered_map<const char, bool> need;
        for (auto ch : t) {
            need.emplace(ch, true);
        }
        while (right < s.size()) {
            right++;
            if (cover.find(s[right - 1]) == cover.end())
                cover.emplace(s[right - 1], 0);
            cover[s[right - 1]]++;
            need[s[right - 1]] = false;
            while (left < right) {
                
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// "ADOBECODEBANC"\n"ABC"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"a"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n"aa"\n
// @lcpr case=end

 */
