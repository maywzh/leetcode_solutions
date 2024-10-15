/*
 * @lc app=leetcode.cn id=76 lang=cpp
 * @lcpr version=
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
        unordered_map<char, int> need, window;
        for (char c : t)
            need[c]++;
        int left = 0, right = 0, valid = 0;
        int min_length = INT_MAX, start = left;
        while (right < s.size()) {
            if (need.count(s[right])) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]])
                    valid++;
            }
            right++;
            while (valid == need.size()) {
                if (min_length > right - left) {
                    min_length = right - left;
                    start = left;
                }
                if (need.count(s[left])) {
                    if (window[s[left]] == need[s[left]])
                        valid--;
                    window[s[left]]--;
                }
                left++;
            }
        }
        return min_length == INT_MAX ? "" : s.substr(start, min_length);
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
