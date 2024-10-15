/*
 * @lc app=leetcode.cn id=6 lang=cpp
 * @lcpr version=20001
 *
 * [6] Z 字形变换
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
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        if (s.size() <= numRows)
            return s;
        vector<string> rows(numRows);
        int direction = 1, row_num = 0;
        for (auto ch : s) {
            rows[row_num] += ch;
            row_num += direction;
            if (row_num == numRows - 1 || row_num == 0) {
                direction = -direction;
            }
        }
        string res;
        for (auto row : rows) {?
            res += row;
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "PAYPALISHIRING"\n3\n
// @lcpr case=end

// @lcpr case=start
// "PAYPALISHIRING"\n4\n
// @lcpr case=end

// @lcpr case=start
// "A"\n1\n
// @lcpr case=end

 */
