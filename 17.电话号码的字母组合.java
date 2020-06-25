import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode.cn id=17 lang=java
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
    private String[] ltMap = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    public String find(String build, String digits, int idx) {
        int dlen = digits.length();
        if (idx >= dlen)
            return build;
        int digit =  Integer.valueOf(digits[idx]).intValue();
        for (int i = 0; i < ltMap[digit].length(); i++) {
            find(build+ltMap[digit][i],idx++, )
        }

    }

    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>();
        // int dlen = digits.length();
        // char[] stack = new char[dlen];
        // int top = -1, idx = 0;
        // while (idx >= 0 && idx < dlen) {

        // if (idx < dlen)
        // {
        // int digit = Integer.parseInt(digits[idx]);
        // for (int i=0;i<ltMap[];i++)
        // }
        // stack[++top] =
        // }

    }
}
// @lc code=end
