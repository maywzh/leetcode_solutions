/*
 * @lc app=leetcode.cn id=662 lang=cpp
 * @lcpr version=20002
 *
 * [662] 二叉树最大宽度
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;
        queue<pair<TreeNode *, unsigned long long>> q;
        q.push(make_pair(root, 1));
        int max_width = 0;
        while (!q.empty()) {
            int sz = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = left;
            for (int i = 0; i < sz; i++) {
                auto [cur_node, cur_id] = q.front();
                q.pop();
                unsigned long long norm_id = cur_id - left;
                if (cur_node->left) {
                    q.push({cur_node->left, norm_id * 2});
                }
                if (cur_node->right) {
                    q.push({cur_node->right, norm_id * 2 + 1});
                }
                if (i == sz - 1)
                    right = norm_id;
            }
            max_width = max(max_width, static_cast<int>(right + 1));
        }
        return max_width;
    }
};

// @lc code=end

/*
// @lcpr case=start
// [1,3,2,5,3,null,9]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5,null,null,9,6,null,7]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,2,5]\n
// @lcpr case=end

 */
