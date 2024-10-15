/*
 * @lc app=leetcode.cn id=566 lang=cpp
 * @lcpr version=20001
 *
 * [566] 重塑矩阵
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
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        if (r * c != m * n)
            return mat;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r * c; i++) {
            res[i / c][i % c] = mat[i / n][i % n];
        }
        return res;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2],[3,4]]\n1\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,4]]\n2\n4\n
// @lcpr case=end

 */
