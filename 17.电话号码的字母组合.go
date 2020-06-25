/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start

var map = map[string]string{
	"0": "",
	"1": "",
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "wxyz"
}

func 

func letterCombinations(digits string) []string {
	
	stack := make([]string, 0)
	if len(digits) ==0 return stack;
	stack = append(stack, "")
	
}
// @lc code=end

