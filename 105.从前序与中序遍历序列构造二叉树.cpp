/*
 * @lc app=leetcode.cn id=105 lang=cpp
 * @lcpr version=20002
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
private:
    unordered_map<int, int> valToIndex;
    TreeNode *build(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd) {
        if (preStart > preEnd)
            return nullptr;
        int rootVal = preorder[preStart];
        int index = valToIndex[rootVal];
        int leftSize = index - inStart;
        TreeNode *root = new TreeNode(rootVal);
        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++)
            valToIndex[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end

/*
// @lcpr case=start
// [3,9,20,15,7]\n[9,3,15,20,7]\n
// @lcpr case=end

// @lcpr case=start
// [-1]\n[-1]\n
// @lcpr case=end

 */
