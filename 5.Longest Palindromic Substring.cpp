/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=20001
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int max_length = 0, start = 0;
        auto palindrome = [&](int l, int r) {
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                l--;
                r++;
            }
            if (r - l - 1 > max_length) {
                max_length = r - l - 1;
                start = l + 1;
            }
        };

        for (int i = 0; i < s.size(); ++i) {
            palindrome(i, i);
            palindrome(i, i + 1);
            if (max_length == s.size())
                return s;
        }
        return s.substr(start, max_length);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */
