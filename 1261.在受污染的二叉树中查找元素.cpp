/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 * @lcpr version=20002
 *
 * [1261] 在受污染的二叉树中查找元素
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
class FindElements {
public:
    FindElements(TreeNode *root) { traverse(root, 0); }

    bool find(int target) { return vals.count(target) > 0; }

private:
    unordered_set<int> vals;

    void traverse(TreeNode *node, int val) {
        if (node == nullptr)
            return;

        // 直接设置节点值，并将其加入集合
        node->val = val;
        vals.insert(node->val);

        // 遍历左子树和右子树，按规则赋值
        traverse(node->left, val * 2 + 1);
        traverse(node->right, val * 2 + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

/*
// @lcpr case=start
// ["FindElements","find","find"][[[-1,null,-1]],[1],[2]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find"][[[-1,-1,-1,-1,-1]],[1],[3],[5]]\n
// @lcpr case=end

// @lcpr case=start
// ["FindElements","find","find","find","find"][[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]\n
// @lcpr case=end

 */
