/*
 * @lc app=leetcode.cn id=8 lang=cpp
 * @lcpr version=20002
 *
 * [8] 字符串转换整数 (atoi)
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
    int myAtoi(string s) {
        int index = 0;
        int signal = 1;
        long ans = 0;
        while (index < s.length() && isspace(s[index])) {
            index++;
        }
        if (index >= s.length())
            return 0;
        if (s[index] == '-') {
            signal = -1;
            index++;
        } else if (s[index] == '+') {
            index++;
        }
        while (index < s.length() && s[index] == '0')
            index++;
        while (index < s.length() && isdigit(s[index])) {
            int digit = s[index] - '0';
            if (ans > (INT_MAX - digit) / 10)
                return signal == 1 ? INT_MAX : INT_MIN;
            ans = ans * 10 + digit;
            index++;
        }
        return static_cast<int>(ans * signal);
    }
};
// @lc code=end

/*
// @lcpr case=start
// "42"\n
// @lcpr case=end

// @lcpr case=start
// " -042"\n
// @lcpr case=end

// @lcpr case=start
// "1337c0d3"\n
// @lcpr case=end

// @lcpr case=start
// "0-1"\n
// @lcpr case=end

// @lcpr case=start
// "words and 987"\n
// @lcpr case=end

 */
