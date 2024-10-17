/*
 * @lc app=leetcode.cn id=752 lang=cpp
 * @lcpr version=20001
 *
 * [752] 打开转盘锁
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
    int openLock(vector<string> &deadends, string target) {
        unordered_set<string> cannot_go(deadends.begin(), deadends.end());
        if (cannot_go.count("0000")) return -1;
        auto op_lock = [](string s, int i, char op) {
            if (op == '+') {
                s[i] = (s[i] - '0' + 1) % 10 + '0';
            } else {
                s[i] = (s[i] - '0' - 1 + 10) % 10 + '0';
            }
            return s;
        };
        queue<string> q;
        q.push("0000");
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string cur = q.front();
                q.pop();
                if (cur == target)
                    return step;
                for (int i = 0; i < 4; i++) {
                    auto up = op_lock(cur, i, '+');
                    auto down = op_lock(cur, i, '-');
                    if (!cannot_go.count(up)) {
                        q.push(up);
                        cannot_go.insert(up);
                    }
                    if (!cannot_go.count(down)) {
                        q.push(down);
                        cannot_go.insert(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["0201","0101","0102","1212","2002"]\n"0202"\n
// @lcpr case=end

// @lcpr case=start
// ["8888"]\n"0009"\n
// @lcpr case=end

// @lcpr case=start
// ["8887","8889","8878","8898","8788","8988","7888","9888"]\n"8888"\n
// @lcpr case=end

 */
