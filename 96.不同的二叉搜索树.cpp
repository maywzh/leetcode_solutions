/*
 * @lc app=leetcode.cn id=96 lang=cpp
 * @lcpr version=20002
 *
 * [96] 不同的二叉搜索树
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
    vector<vector<int>> memo;
    int count(int lo, int hi) {
        if (lo > hi)
            return 1;
        if (memo[lo][hi] != 0)
            return memo[lo][hi];
        int res = 0;
        for (int mid = lo; mid <= hi; mid++) {
            int left = count(lo, mid - 1);
            int right = count(mid + 1, hi);
            res += left * right;
        }
        memo[lo][hi] = res;
        return res;
    }

public:
    int numTrees(int n) {
        memo = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
        return count(1, n);
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
