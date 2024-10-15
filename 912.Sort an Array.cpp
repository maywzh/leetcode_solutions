/*
 * @lc app=leetcode.cn id=912 lang=cpp
 * @lcpr version=
 *
 * [912] 排序数组
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
    vector<int> sortArray(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void heapify(vector<int> &nums, int n, int i) {
        int largest = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        if (left < n && nums[left] > nums[largest])
            largest = left;
        if (right < n && nums[right] > nums[largest])
            largest = right;
        if (largest != i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }

    void mergeSort(vector<int> &nums, int lo, int hi) {
        if (lo == hi) {
            return;
        }
        int mid = lo + (hi - lo) / 2;
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);

        auto merge = [&](int lo, int mid, int hi) {
            int i = lo, j = mid + 1;
            vector<int> tmp;
            while (i <= mid || j <= hi) {
                if (i > mid) {
                    tmp.push_back(nums[j++]);
                } else if (j > hi) {
                    tmp.push_back(nums[i++]);
                } else {
                    tmp.push_back(nums[i] < nums[j] ? nums[i++] : nums[j++]);
                }
            }
            for (int k = 0; k < tmp.size(); ++k) {
                nums[lo + k] = tmp[k];
            }
        };

        merge(lo, mid, hi);
    }

    void heapSort(vector<int> &nums, int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }
        for (int i = n - 1; i >= 0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    void insertionSort(vector<int> &nums, int lo, int hi) {
        for (int i = lo + 1; i <= hi; i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= lo && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }

    // 快速排序
    void quickSort(vector<int> &nums, int lo, int hi) {
        if (lo >= hi)
            return;

        // 小数组优化：对于小于 10 的子数组，使用插入排序
        if (hi - lo < 10) {
            insertionSort(nums, lo, hi);
            return;
        }

        // 三数取中法选择基准
        int pivotIndex = medianOfThree(nums, lo, hi);
        swap(nums[pivotIndex], nums[hi]); // 将基准交换到末尾

        // 分区
        int p = partition(nums, lo, hi);

        // 递归排序左右部分
        quickSort(nums, lo, p - 1);
        quickSort(nums, p + 1, hi);
    }

    // 三数取中法选取基准
    int medianOfThree(vector<int> &nums, int lo, int hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[lo] > nums[mid])
            swap(nums[lo], nums[mid]);
        if (nums[lo] > nums[hi])
            swap(nums[lo], nums[hi]);
        if (nums[mid] > nums[hi])
            swap(nums[mid], nums[hi]);
        return mid; // 返回中间位置作为基准
    }

    // 分区函数
    int partition(vector<int> &nums, int lo, int hi) {
        int pivot = nums[hi]; // 使用三数取中法后的基准元素
        int i = lo - 1;
        for (int j = lo; j < hi; j++) {
            if (nums[j] < pivot) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[hi]); // 将基准元素放到正确位置
        return i + 1;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [5,2,3,1]\n
// @lcpr case=end

// @lcpr case=start
// [5,1,1,2,0,0]\n
// @lcpr case=end

 */
