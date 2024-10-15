/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=20001
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return {}; // 检查空矩阵情况

        int m = matrix.size(), n = matrix[0].size();
        int upperbound = 0, lowerbound = m - 1;
        int leftbound = 0, rightbound = n - 1;

        vector<int> res;

        while (res.size() < m * n) {
            // 向右遍历
            for (int j = leftbound; j <= rightbound && res.size() < m * n; j++) {
                res.push_back(matrix[upperbound][j]);
            }
            upperbound++;

            // 向下遍历
            for (int i = upperbound; i <= lowerbound && res.size() < m * n; i++) {
                res.push_back(matrix[i][rightbound]);
            }
            rightbound--;

            // 向左遍历
            for (int j = rightbound; j >= leftbound && res.size() < m * n; j--) {
                res.push_back(matrix[lowerbound][j]);
            }
            lowerbound--;

            // 向上遍历
            for (int i = lowerbound; i >= upperbound && res.size() < m * n; i--) {
                res.push_back(matrix[i][leftbound]);
            }
            leftbound++;
        }

        return res;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */
