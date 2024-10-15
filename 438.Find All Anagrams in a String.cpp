/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        vector<int> ans;
        int valid = 0;
        int left = 0, right = 0;
        for (char c : p) {
            need[c]++;
        }
        while (right < s.length()) {
            if (need.count(s[right])) {
                window[s[right]]++;
                if (window[s[right]] == need[s[right]]) {
                    valid++;
                }
            }
            right++;
            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    ans.push_back(left);
                }
                if (need.count(s[left])) {
                    if (window[s[left]] == need[s[left]]) {
                        valid--;
                    }
                    window[s[left]]--;
                }
                left++;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */
