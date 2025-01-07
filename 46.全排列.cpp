/*
 * @lc app=leetcode.cn id=46 lang=cpp
 * @lcpr version=20004
 *
 * [46] 全排列
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
private:
    vector<vector<int>> result;

public:
    void backtracing(vector<int> &nums, vector<int> &current, vector<bool> &used) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            current.push_back(nums[i]);
            backtracing(nums, current, used);
            used[i] = false;
            current.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        vector<int> current;
        backtracing(nums, current, used);
        return result;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,1]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

 */
