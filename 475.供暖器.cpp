/*
 * @lc app=leetcode.cn id=475 lang=cpp
 * @lcpr version=20002
 *
 * [475] 供暖器
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
    int findRadius(vector<int> &houses, vector<int> &heaters) {
        int left_house = INT_MAX, right_house = INT_MIN;
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (int house : houses) {
            int closed_heater_distance = findClosestHeater(house, heaters);
            radius = max(radius, closed_heater_distance);
        }
        return radius;
    }

private:
    int findClosestHeater(int house, vector<int> &heaters) {
        auto it = lower_bound(heaters.begin(), heaters.end(), house);
        int dist_left = (it == heaters.begin()) ? INT_MAX : house - *(it - 1);
        int dist_right = (it == heaters.end()) ? INT_MAX : *it - house;
        return min(dist_left, dist_right);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4]\n[1,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,5]\n[2]\n
// @lcpr case=end

 */
