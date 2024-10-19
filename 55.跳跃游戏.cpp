/*
 * @lc app=leetcode.cn id=55 lang=cpp
 * @lcpr version=20002
 *
 * [55] 跳跃游戏
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
    bool canJump2(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            if (dp[i] == 0)
                continue;
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n)
                    dp[i + j] = 1;
            }
        }
        return dp[n - 1] == 1;
    }

    bool canJump(vector<int> &nums) {
        int maxReach = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = maxReach < i + nums[i] ? i + nums[i] : maxReach;
            if (maxReach >= n - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [3,2,1,0,4]\n
// @lcpr case=end

 */
