/*
 * @lc app=leetcode.cn id=310 lang=cpp
 * @lcpr version=20002
 *
 * [310] 最小高度树
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
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        vector<vector<int>> graph(n);
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        if (edges.size() == 0)
            return vector<int>({0});
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                q.push(i);
            }
        }
        int nodeCount = n;
        while (nodeCount > 2) {
            int sz = q.size();
            nodeCount -= sz;
            for (int i = 0; i < sz; i++) {
                auto cur = q.front();
                q.pop();
                for (int neighbor : graph[cur]) {
                    auto it = find(graph[neighbor].begin(), graph[neighbor].end(), cur);
                    if (it != graph[neighbor].end()) {
                        graph[neighbor].erase(it);
                    }
                    if (graph[neighbor].size() == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 4\n[[1,0],[1,2],[1,3]]\n
// @lcpr case=end

// @lcpr case=start
// 6\n[[3,0],[3,1],[3,2],[3,4],[5,4]]\n
// @lcpr case=end

 */
