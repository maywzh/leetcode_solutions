/*
 * @lc app=leetcode.cn id=170 lang=cpp
 * @lcpr version=20002
 *
 * [170] 两数之和 III - 数据结构设计
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
class TwoSum {
private:
    unordered_map<int, int> nums_count;

public:
    TwoSum() {}

    void add(int number) { nums_count[number]++; }

    bool find(int value) {
        for (auto &[num, count] : nums_count) {
            long complement = static_cast<long>(value) - static_cast<long>(num);
            if (complement < INT_MIN || complement > INT_MAX) {
                continue;
            }
            if (complement != num) {
                if (nums_count.count(complement))
                    return true;
            } else {
                if (count >= 2)
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
// @lc code=end

/*
// @lcpr case=start
// ["TwoSum", "add", "add", "add", "find", "find"][[], [1], [3], [5], [4], [7]]\n
// @lcpr case=end

 */
