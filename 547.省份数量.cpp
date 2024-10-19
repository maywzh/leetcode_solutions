/*
 * @lc app=leetcode.cn id=547 lang=cpp
 * @lcpr version=20002
 *
 * [547] 省份数量
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
    int findCircleNum(vector<vector<int>> &isConnected) {
        unordered_set<int> visited;
        int n = isConnected.size();
        int count = 0;
        function<void(int)> dfs = [&](int i) {
            visited.insert(i);
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && !visited.count(j)) {
                    dfs(j);
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (!visited.count(i)) {
                count++;
                dfs(i);
            }
        }
        return count;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,1,0],[1,1,0],[0,0,1]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,0,0],[0,1,0],[0,0,1]]\n
// @lcpr case=end

 */
