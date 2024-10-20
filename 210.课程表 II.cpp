/*
 * @lc app=leetcode.cn id=210 lang=cpp
 * @lcpr version=20002
 *
 * [210] 课程表 II
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
    vector<int> visited;
    bool hasCycle = false;
    vector<int> postOrder;
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &p : prerequisites) {
            graph[p[1]].push_back(p[0]);
        }
        return graph;
    }

    void traverse(int cur, vector<vector<int>> &graph) {
        if (visited[cur] == 1) {
            hasCycle = true;
            return;
        }
        if (visited[cur] == 2) {
            return;
        }
        visited[cur] = 1;
        for (auto next : graph[cur]) {
            traverse(next, graph);
        }
        postorder.push_back(s);
        visited[cur] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        auto graph = buildGraph(numCourses, prerequisites);
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0)
                traverse(i, graph);
            if (hasCycle)
                return false;
        }
        return true;
    }

public:
    findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        auto graph = buildGraph(numCourses, prerequisites);
        visited = vector<int>(numCourses);
        for (int i = 0; i < numCourses; i++) {
            traverse(graph, i);
            if (hasCycle)
                return vector<int>();
        }
        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 4\n[[1,0],[2,0],[3,1],[3,2]]\n
// @lcpr case=end

// @lcpr case=start
// 1\n[]\n
// @lcpr case=end

 */
