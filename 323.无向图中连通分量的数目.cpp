/*
 * @lc app=leetcode.cn id=323 lang=cpp
 * @lcpr version=20002
 *
 * [323] 无向图中连通分量的数目
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
    class UF {
    private:
        int _count;
        vector<int> parent;

    public:
        UF(int n)
            : _count(n) {
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        void union_(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);
            if (rootP == rootQ)
                return;
            parent[rootP] = rootQ;
            _count--;
        }
        bool connected(int p, int q) { return find(p) == find(q); }
        int count() { return _count; }
    };

public:
    int countComponents(int n, vector<vector<int>> &edges) {
        UF uf(n);
        for (auto &edge : edges) {
            uf.union_(edge[0], edge[1]);
        }
        return uf.count();
    }
};

// @lc code=end

/*
// @lcpr case=start
// 5\n[[0, 1], [1, 2], [3, 4]]\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1], [1,2], [2,3], [3,4]]\n
// @lcpr case=end

 */
