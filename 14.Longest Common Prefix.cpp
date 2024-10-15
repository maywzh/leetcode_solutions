/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=20001
 *
 * [14] 最长公共前缀
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
    string longestCommonPrefix(vector<string> &strs) {
        int max_len = 0;
        if (strs.size() == 1)
            return strs[0];
        int flag = true, index = -1;
        while (flag) {

            ++index;
            for (int i = 1; i < strs.size(); i++) {
                if (strs[i].length() == index)
                    return strs[i].substr(0, index);
                if (strs[i][index] != strs[0][index]) {
                    flag = false;
                    break;
                }
            }
        }
        return "";
    }
};
// @lc code=end

/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */
