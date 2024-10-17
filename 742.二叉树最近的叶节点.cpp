/*
 * @lc app=leetcode.cn id=742 lang=cpp
 * @lcpr version=20002
 *
 * [742] 二叉树最近的叶节点
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
    int findClosestLeaf(TreeNode *root, int k) {
        traverse(root, k, nullptr);
        queue<TreeNode *> q;
        unordered_set<TreeNode *> visited;
        if (!target)
            return -1;
        q.push(target);
        visited.insert(target);
        int delta = INT_MAX;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto cur = q.front();
                q.pop();
                if (!cur->left && !cur->right) {
                    return cur->val;
                }
                if (cur->left && !visited.count(cur->left)) {
                    q.push(cur->left);
                    visited.insert(cur->left);
                }
                if (cur->right && !visited.count(cur->right)) {
                    q.push(cur->right);
                    visited.insert(cur->right);
                }
                auto parent = parent_map[cur];
                if (parent && !visited.count(parent)) {
                    q.push(parent);
                    visited.insert(parent);
                }
            }
        }
        return -1;
    }

private:
    TreeNode *target = nullptr;
    unordered_map<TreeNode *, TreeNode *> parent_map;
    void traverse(TreeNode *root, int k, TreeNode *parent) {
        if (!root)
            return;
        parent_map[root] = parent;
        if (root->val == k) {
            target = root;
            return;
        }
        traverse(root->left, k, root);
        traverse(root->right, k, root);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1, 3, 2]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,null,null,null,5,null,6]\n2\n
// @lcpr case=end

 */
