/*
 * @lc app=leetcode.cn id=86 lang=cpp
 * @lcpr version=
 *
 * [86] 分隔链表
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        auto dummy0 = new ListNode(-1);
        auto dummy1 = new ListNode(-1);
        auto current0 = dummy0;
        auto current1 = dummy1;
        while (head) {
            if (head->val < x) {
                current0->next = head;
                current0 = current0->next;
            } else {
                current1->next = head;
                current1 = current1->next;
            }
            head = head->next;
        }
        current1->next = nullptr;
        current0->next = dummy1->next;
        return dummy0->next;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,4,3,2,5,2]\n3\n
// @lcpr case=end

// @lcpr case=start
// [2,1]\n2\n
// @lcpr case=end

 */
