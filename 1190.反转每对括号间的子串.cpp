/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> stack; // 存储字符串
        string current;      // 当前构建的字符串

        for (char c : s) {
            if (c == '(') {
                stack.push(current);
                current.clear();
            } else if (c == ')') {
                reverse(current.begin(), current.end());
                if (!stack.empty()) {
                    string temp = stack.top();
                    stack.pop();
                    temp += current;
                    current = temp;
                }
            } else {
                current += c;
            }
        }

        return current;
    }
};
// @lc code=end
