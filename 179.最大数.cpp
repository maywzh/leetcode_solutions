/*
 * @lc app=leetcode.cn id=179 lang=cpp
 * @lcpr version=20002
 *
 * [179] 最大数
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
    string largestNumber(vector<int> &nums) {
        vector<string> num_strs(nums.size());
        transform(nums.begin(), nums.end(), num_strs.begin(), [](int x) { return to_string(x); });
        sort(num_strs.begin(), num_strs.end(), [](string &a, string &b) { return a + b > b + a; });
        if (num_strs[0] == "0") {
            return "0";
        }
        string result;
        for (string &str : num_strs) {
            result += str;
        }
        accumulate(num_strs.begin(), num_strs.end(), result, [](const string &a, const string &b) { return a + b; });
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [10,2]\n
// @lcpr case=end

// @lcpr case=start
// [3,30,34,5,9]\n
// @lcpr case=end

 */
