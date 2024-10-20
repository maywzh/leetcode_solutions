/*
 * @lc app=leetcode.cn id=621 lang=cpp
 * @lcpr version=20002
 *
 * [621] 任务调度器
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
    int leastInterval(vector<char> &tasks, int n) {
        unordered_map<char, int> freq;
        int maxFreq = 0, maxFreqCount = 0;
        for (auto &task : tasks) {
            freq[task]++;
            maxFreq = max(maxFreq, freq[task]);
        }
        for (auto &entry : freq) {
            if (entry.second == maxFreq) {
                maxFreqCount++;
            }
        }
        int empty_slots = (maxFreq - 1) * (n + 1) + maxFreqCount;
        return max((int)tasks.size(), empty_slots);
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["A","A","A","B","B","B"]\n2\n
// @lcpr case=end

// @lcpr case=start
// ["A","C","A","B","D","B"]\n1\n
// @lcpr case=end

// @lcpr case=start
// ["A","A","A","B","B","B"]\n3\n
// @lcpr case=end

 */
