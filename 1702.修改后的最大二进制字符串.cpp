/*
 * @lc app=leetcode.cn id=1702 lang=cpp
 *
 * [1702] 修改后的最大二进制字符串
 */

// @lc code=start
class Solution {
public:
    string maximumBinaryString(string binary) {
        if (binary.length() <= 1 || binary == "01") {
            return binary;
        }

        size_t cnt = 0, pos = string::npos;

        for (size_t i = 0; i < binary.length(); i++) {
            if (binary[i] == '0') {
                cnt++;
                if (pos == string::npos) {
                    pos = i;
                }
            }
        }

        if (cnt <= 1) {
            return binary;
        }

        for (size_t i = pos; i < binary.length(); i++) {
            binary[i] = (i != pos + cnt - 1) ? '1' : '0';
        }

        return binary;
    }
};
// @lc code=end
