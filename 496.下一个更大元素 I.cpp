/*
 * @lc app=leetcode.cn id=496 lang=cpp
 * @lcpr version=20002
 *
 * [496] 下一个更大元素 I
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
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> greater = nextGreaterElement(nums2);
        unordered_map<int, int> map;
        for (int i = 0; i < nums2.size(); i++) {
            map[nums2[i]] = greater[i];
        }

        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = map[nums1[i]];
        }

        return res;
    }

private:
    vector<int> nextGreaterElement(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n, -1); // 默认值为 -1
        stack<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                res[i] = stk.top();
            }
            stk.push(nums[i]);
        }

        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,1,2]\n[1,3,4,2].\n
// @lcpr case=end

// @lcpr case=start
// [2,4]\n[1,2,3,4].\n
// @lcpr case=end

 */
