/*
 * @lc app=leetcode.cn id=841 lang=cpp
 * @lcpr version=20002
 *
 * [841] 钥匙和房间
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
    bool canVisitAllRooms(vector<vector<int>> &rooms) {
        unordered_set<int> vis;
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int cur = q.front();
                q.pop();
                vis.insert(cur);
                for (auto can_go : rooms[cur]) {
                    if (!vis.count(can_go)) {
                        q.push(can_go);
                    }
                }
                if (vis.size() == n)
                    return true;
            }
        }
        return vis.size() == n;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1],[2],[3],[]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[3,0,1],[2],[0]]\n
// @lcpr case=end

 */
