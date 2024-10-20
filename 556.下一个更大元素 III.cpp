/*
 * @lc app=leetcode.cn id=556 lang=cpp
 * @lcpr version=20002
 *
 * [556] 下一个更大元素 III
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
    int nextGreaterElement(int n) {
        string num_str = to_string(n);
        int i = num_str.size() - 2;
        while (i >= 0 && num_str[i] >= num_str[i + 1])
            i--;

        if (i < 0) {
            return -1;
        }
        int j = num_str.size() - 1;
        while (j > i && num_str[j] <= num_str[i])
            j--;

        swap(num_str[i], num_str[j]);
        reverse(num_str.begin() + i + 1, num_str.end());
        long result = stoi(num_str);
        if (result > INT_MAX)
            return -1;
        return static_cast<int>(result);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 21\n
// @lcpr case=end

// @lcpr case=start
// 61321\n
// @lcpr case=end

 */
