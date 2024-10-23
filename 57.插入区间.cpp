/*
 * @lc app=leetcode.cn id=57 lang=cpp
 * @lcpr version=20002
 *
 * [57] 插入区间
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
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        if (intervals.empty())
            return {newInterval};
        vector<vector<int>> ans;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i++]);
        }
        int last_start = newInterval[0], last_end = newInterval[1];
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            last_start = min(last_start, intervals[i][0]);
            last_end = max(last_end, intervals[i][1]);
            i++;
        }
        ans.push_back({last_start, last_end});
        while (i < intervals.size()) {
            ans.push_back(intervals[i++]);
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,3],[6,9]]\n[2,5]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2],[3,5],[6,7],[8,10],[12,16]]\n[4,8]\n
// @lcpr case=end

 */
