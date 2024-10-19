/*
 * @lc app=leetcode.cn id=45 lang=cpp
 * @lcpr version=20002
 *
 * [45] 跳跃游戏 II
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
    int jump2(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < n) {
                    dp[i + j] = min(dp[i + j], dp[i] + 1);
                }
            }
        }
        return dp[n - 1];
    }

    int jump(vector<int> &nums) {
        int jumps = 0;
        int curEnd = 0;
        int curFarthest = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            curFarthest = max(curFarthest, i + nums[i]);
            if (i == curEnd) { // 到达当前跳跃的边界
                jumps++;
                curEnd = curFarthest; // 更新边界
                if (curEnd >= nums.size() - 1) {
                    break;
                }
            }
        }
        return jumps;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [2,3,1,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,3,0,1,4]\n
// @lcpr case=end

 */
