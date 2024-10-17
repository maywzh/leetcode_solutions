/*
 * @lc app=leetcode.cn id=863 lang=cpp
 * @lcpr version=20002
 *
 * [863] 二叉树中所有距离为 K 的结点
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
        traverse(root, nullptr);
        vector<int> ans;
        unordered_set<TreeNode *> visited;
        queue<TreeNode *> q;
        q.push(target);
        int distance = 0;
        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto cur = q.front();
                q.pop();
                if (distance == k) {
                    ans.push_back(cur->val);
                }
                visited.insert(cur);
                if (cur->left && !visited.count(cur->left)) {
                    q.push(cur->left);
                }
                if (cur->right && !visited.count(cur->right)) {
                    q.push(cur->right);
                }
                if (parentOf[cur] && !visited.count(parentOf[cur])) {
                    q.push(parentOf[cur]);
                }
            }
            distance++;
        }
        return ans;
    }

private:
    unordered_map<TreeNode *, TreeNode *> parentOf;
    void traverse(TreeNode *root, TreeNode *parent) {
        if (!root)
            return;
        parentOf[root] = parent;
        traverse(root->left, root);
        traverse(root->right, root);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,5,1,6,2,0,8,null,null,7,4]\n5\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n3\n
// @lcpr case=end

 */
