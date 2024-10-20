/*
 * @lc app=leetcode.cn id=207 lang=cpp
 * @lcpr version=20002
 *
 * [207] 课程表
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
    vector<int> visited; // 0: 未访问, 1: 访问中, 2: 已访问完毕
    bool hasCycle = false;

    // 建图函数，构建邻接表
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto &edge : prerequisites) {
            int from = edge[1], to = edge[0];
            graph[from].push_back(to);
        }
        return graph;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        visited = vector<int>(numCourses, 0); // 初始化为未访问状态

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                traverse(graph, i);
            }
            if (hasCycle)
                return false; // 提前返回
        }
        return true;
    }

    void traverse(vector<vector<int>> &graph, int s) {
        if (hasCycle)
            return; // 提前终止

        if (visited[s] == 1) { // 遇到访问中的节点，说明存在环
            hasCycle = true;
            return;
        }

        if (visited[s] == 2)
            return; // 已经访问完毕的节点，直接返回

        visited[s] = 1; // 标记为访问中
        for (int t : graph[s]) {
            traverse(graph, t);
        }
        visited[s] = 2; // 标记为访问完毕
    }
};

// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,0]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[1,0],[0,1]]\n
// @lcpr case=end

 */
