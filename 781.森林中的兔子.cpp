/*
 * @lc app=leetcode.cn id=781 lang=cpp
 * @lcpr version=20002
 *
 * [781] 森林中的兔子
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
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> count;
        int ans = 0;
        for (int i = 0; i < answers.size(); i++) {
            count[answers[i]]++;
        }
        for (auto it = count.begin(); it != count.end(); it++) {
            ans += (it->second / (it->first + 1)) * (it->first + 1);
            ans += it->second % (it->first + 1) != 0 ? it->first + 1 : 0;
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [10,10,10]\n
// @lcpr case=end

 */
