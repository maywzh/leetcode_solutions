/*
 * @lc app=leetcode.cn id=315 lang=cpp
 * @lcpr version=20002
 *
 * [315] 计算右侧小于当前元素的个数
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
    struct MPair {
        int val, id;
        MPair()
            : val(0)
            , id(0) {}
        MPair(int val, int id)
            : val(val)
            , id(id) {}
    };
    vector<MPair> temp;
    vector<int> count;

public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        count.resize(n);
        temp.resize(n);
        vector<MPair> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = MPair(nums[i], i);
        }
        sort(arr, 0, n - 1);
        return count;
    }

    void sort(vector<MPair> &arr, int lo, int hi) {
        if (lo == hi)
            return;
        int mid = lo + (hi - lo) / 2;
        sort(arr, lo, mid);
        sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }

    void merge(vector<MPair> &arr, int lo, int mid, int hi) {
        for (int i = lo; i <= hi; i++) {
            temp[i] = arr[i];
        }

        int i = lo, j = mid + 1;
        for (int p = lo; p <= hi; p++) {
            if (i == mid + 1) {
                arr[p] = temp[j++];
            } else if (j == hi + 1) {
                arr[p] = temp[i++];
                count[arr[p].id] += j - mid - 1;
            } else if (temp[i].val <= temp[j].val) {
                arr[p] = temp[i++];
                count[arr[p].id] += j - mid - 1;
            } else {
                arr[p] = temp[j++];
            }
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [5,2,6,1]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n
// @lcpr case=end

// @lcpr case=start
// [-1,-1]\n
// @lcpr case=end

 */
