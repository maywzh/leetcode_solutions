/*
 * @lc app=leetcode.cn id=157 lang=cpp
 * @lcpr version=20004
 *
 * [157] 用 Read4 读取 N 个字符
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
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int index = 0;
        char *temp = new char[4];
        while (index < n) {
            int count = read4(temp);
            if (count == 0) {
                break;
            }
            for (int i = 0; i < count && index < n; i++) {
                buf[index++] = temp[i];
            }
        }
        return index;
    }
};
// @lc code=end

/*
// @lcpr case=start
// "abc"\n4\n
// @lcpr case=end

// @lcpr case=start
// "abcde"\n5\n
// @lcpr case=end

// @lcpr case=start
// "abcdABCD1234"\n12\n
// @lcpr case=end

// @lcpr case=start
// "leetcode"\n5\n
// @lcpr case=end

 */
