/*
 * @lc app=leetcode.cn id=208 lang=cpp
 * @lcpr version=20004
 *
 * [208] 实现 Trie (前缀树)
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
class Trie {
    class TreeNode {
        char key;
        unordered_map<char, TreeNode *> children;

    public:
        TreeNode(char ch)
            : key(ch) {}
        void addChild(char chKey) {
            if (!children.count(chKey)) {
                children[key] = new TreeNode(chKey);
            }
        }
    };

private:
    TreeNode *root;

public:
    Trie() {}

    void insert(string word) {}

    bool search(string word) {}

    bool startsWith(string prefix) {}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
