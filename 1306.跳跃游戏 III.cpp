/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 * @lcpr version=20002
 *
 * [1306] 跳跃游戏 III
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
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto cur = q.front();
                q.pop();
                if (arr[cur] == 0)
                    return true;
                if (cur - arr[cur] >= 0 && !visited[cur - arr[cur]]) {
                    q.push(cur - arr[cur]);
                }
                if (cur + arr[cur] < n && !visited[cur + arr[cur]]) {
                    q.push(cur + arr[cur]);
                }
                visited[cur] = true;
            }
        }
        return false;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [4,2,3,0,3,1,2]\n5\n
// @lcpr case=end

// @lcpr case=start
// [4,2,3,0,3,1,2]\n0\n
// @lcpr case=end

// @lcpr case=start
// [3,0,2,1,2]\n2\n
// @lcpr case=end

 */
