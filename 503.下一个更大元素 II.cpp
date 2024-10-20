/*
 * @lc app=leetcode.cn id=503 lang=cpp
 * @lcpr version=20002
 *
 * [503] 下一个更大元素 II
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
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1); // 初始化结果数组，默认值为 -1
        stack<int> stk;         // 单调栈，保存元素的索引
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] <= nums[i % n]) {
                stk.pop();
            }
            if (i < n) {
                res[i] = stk.empty() ? -1 : nums[stk.top()];
            }
            stk.push(i % n);
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,1]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,3]\n
// @lcpr case=end

 */
